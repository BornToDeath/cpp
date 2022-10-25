//
// Created by lixiaoqing on 2022/10/25.
//

#ifndef LOCKFREEQUEUE_LOCKFREEQUEUE_H
#define LOCKFREEQUEUE_LOCKFREEQUEUE_H

#include <unistd.h>
#include <sys/mman.h>
//#include <sys/stat.h>
//#include <sys/types.h>
#include <fcntl.h>

#define USE_LOCK  // 开启 spinlock 锁，多生产者多消费者场景
#define USE_POT   // 开启队列大小的2的幂对齐
#define USE_MB    // 开启 memory barrier
#define IS_POT(x) ((x) && !((x) & ((x) - 1)))
#define MEMORY_BARRIER __sync_synchronize()

/**
 * 无锁队列
 * 多线程场景下，需要定义 USE_LOCK 宏，开启锁保护。
 * @tparam T
 */
template<typename T>
class LockFreeQueue {

public:

    explicit LockFreeQueue(unsigned int size, const char *name = nullptr) : m_head(0), m_tail(0) {

#ifdef USE_POT
        if (!IS_POT(size)) {
            size = roundup_pow_of_two(size);
        }
#endif

        m_size = size;
        if (name == nullptr) {
            m_buffer = new T[m_size]();
        } else {
            int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
            if (shm_fd < 0) {
                perror("shm_open failed");
                exit(1);
            }
            if (ftruncate(shm_fd, m_size * sizeof(T)) < 0) {
                perror("ftruncate failed");
                close(shm_fd);
                exit(1);
            }
            void *addr = mmap(nullptr, m_size * sizeof(T), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
            if (addr == MAP_FAILED) {
                perror("mmap failed");
                close(shm_fd);
                exit(1);
            }
            if (close(shm_fd) == -1) {
                perror("close failed");
                exit(1);
            }
            m_buffer = static_cast<T *>(addr);
            memcpy(shm_name, name, strlen(name));
        }
    }

    ~LockFreeQueue() {
        if (shm_name[0] == 0) {
            delete[] m_buffer;
            m_buffer = nullptr;
        } else {
            if (munmap(m_buffer, m_size * sizeof(T)) == -1) {
                perror("munmap failed");
            }
            if (shm_unlink(shm_name) == -1) {
                perror("shm_unlink failed");
            }
        }
    }

public:

    bool push(const T &value) {
#ifdef USE_LOCK
        m_lock.spinlock_lock();
#endif
        if (isFull()) {
#ifdef USE_LOCK
            m_lock.spinlock_unlock();
#endif
            return false;
        }

        memcpy(m_buffer + m_tail, &value, sizeof(T));

#ifdef USE_MB
        MEMORY_BARRIER;
#endif

#ifdef USE_POT
        m_tail = (m_tail + 1) & (m_size - 1);
#else
        m_tail = (m_tail + 1) % m_size;
#endif

#ifdef USE_LOCK
        m_lock.spinlock_unlock();
#endif

        return true;
    }

    bool pop(T &value) {
#ifdef USE_LOCK
        m_lock.spinlock_lock();
#endif
        if (isEmpty()) {
#ifdef USE_LOCK
            m_lock.spinlock_unlock();
#endif
            return false;
        }

        memcpy(&value, m_buffer + m_head, sizeof(T));

#ifdef USE_MB
        MEMORY_BARRIER;
#endif

#ifdef USE_POT
        m_head = (m_head + 1) & (m_size - 1);
#else
        m_head = (m_head + 1) % m_size;
#endif

#ifdef USE_LOCK
        m_lock.spinlock_unlock();
#endif
        return true;
    }

    bool isFull() const {
#ifdef USE_POT
        return m_head == ((m_tail + 1) & (m_size - 1));
#else
        return m_head == (m_tail + 1) % m_size;
#endif
    }

    bool isEmpty() const {
        return m_head == m_tail;
    }

    unsigned int head() const {
        return m_head;
    }

    unsigned int tail() const {
        return m_tail;
    }

protected:

    unsigned int roundup_pow_of_two(size_t size) {
        size |= size >> 1;
        size |= size >> 2;
        size |= size >> 4;
        size |= size >> 8;
        size |= size >> 16;
        size |= size >> 32;
        return size + 1;
    }

protected:
    class spinlock_t {
    public:
        void spinlock_lock() {
            while (!__sync_bool_compare_and_swap(&m_lock, 0, 1)) {}
        }

        void spinlock_unlock() {
            __sync_lock_release(&m_lock);
        }

    private:
        int m_lock{0};
    };

protected:
    char shm_name[32]{};           // 共享内存 key 的路径名称
    volatile unsigned int m_head;  // 队列头部索引
    volatile unsigned int m_tail;  // 队列尾部索引（指向队列尾部元素的下一个元素）
    unsigned int m_size;           // 队列大小
    T *m_buffer;
#ifdef USE_LOCK
    spinlock_t m_lock;
#endif
};

#endif //LOCKFREEQUEUE_LOCKFREEQUEUE_H
