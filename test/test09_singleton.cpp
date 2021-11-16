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

int main() {

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

    std::cout << "Exit." << std::endl;
}