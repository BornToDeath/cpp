//
// Created by lixiaoqing on 2021/11/15.
//

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

/**
 * 使用互斥锁实现单例
 */
namespace SingleTest01 {

    class Singleton {

    public:

        static std::shared_ptr<Singleton> getSingleton();

        void print() {
            std::cout << "Hello World." << std::endl;
        }

        ~Singleton() {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }

    private:

        Singleton() {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
    };

    static std::shared_ptr<Singleton> singleton = nullptr;
    static std::mutex singletonMutex;

    std::shared_ptr<Singleton> Singleton::getSingleton() {
        if (singleton == nullptr) {
            std::unique_lock<std::mutex> lock(singletonMutex);
            if (singleton == nullptr) {
                auto temp = std::shared_ptr<Singleton>(new Singleton());
                singleton = temp;
            }
        }
        return singleton;
    }
}

/**
 * 使用 std::call_once 实现单例
 */
namespace SingleTest02 {
    class Singleton {
    public:
        static std::shared_ptr<Singleton> getSingleton();

        void print() {
            std::cout << "Hello World." << std::endl;
        }

        ~Singleton() {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }

    private:
        Singleton() {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
    };

    static std::shared_ptr<Singleton> singleton = nullptr;
    static std::once_flag singletonFlag;

    std::shared_ptr<Singleton> Singleton::getSingleton() {
        std::call_once(singletonFlag, [&] {
            singleton = std::shared_ptr<Singleton>(new Singleton());
        });
        return singleton;
    }
}

namespace singleton_test03 {
    class Singleton {
    public:
        static Singleton *&getInstance() {
            if (instance == nullptr) {
                std::unique_lock<std::mutex> lock(_mutex);
                if (instance == nullptr) {
                    auto obj = new Singleton();
                    instance = obj;
                    std::cout << ">>> " << instance << std::endl;
                }
            }
            return instance;
        }

        static void releaseInstance() {
            if (instance) {
                std::unique_lock<std::mutex> lock(_mutex);
                delete instance;
                instance = nullptr;
            }
        }

    private:
        static Singleton *instance;
        static std::mutex _mutex;
    };

    Singleton *Singleton::instance = nullptr;
    std::mutex Singleton::_mutex;
}

void test01() {
    auto runnable = [] {
        auto ptr = SingleTest02::Singleton::getSingleton();
        ptr->print();
    };

    std::thread t1(runnable);
    std::thread t2(runnable);
    std::thread t3(runnable);

    t1.join();
    t2.join();
    t3.join();
}

void test02() {
    using singleton_test03::Singleton;

    auto instance = Singleton::getInstance();
    std::cout << "1: " << instance << std::endl;

    instance = nullptr;
    std::cout << instance << std::endl;

    std::cout << "2: " << Singleton::getInstance() << std::endl;

    Singleton::getInstance() = nullptr;   // 如果单例返回的是指针的引用，则此处单例实例被修改为了空！有风险！造成内存泄露

    std::cout << "3: " << Singleton::getInstance() << std::endl;  // 此处会重新创建一份单例实例，

    Singleton::releaseInstance();
}

int main() {
    test02();
    std::cout << "Exit." << std::endl;
    return 0;
}