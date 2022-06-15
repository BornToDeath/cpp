//
// Created by lixiaoqing on 2021/11/16.
//

#include <iostream>
#include <thread>
#include <boost/asio.hpp>
//#include "boost/thread.hpp"

using namespace boost::asio;

namespace Test {
    void test01() {
        auto handler = [](const boost::system::error_code &ec) {
            std::cout << "5 s." << std::endl;
        };
        boost::asio::io_service io_service;
        boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(5));
        std::cout << __LINE__ << std::endl;
        timer.async_wait(handler);
        std::cout << __LINE__ << std::endl;
        io_service.run();
        std::cout << __LINE__ << std::endl;
    }

    void test02() {
        io_service service;
        io_service::work work(service);
        printf("Before run\n");
        service.run();
        printf("After run\n");
    }

    void test03() {
        auto service = new io_service();
        auto runnable = [service]() {
            printf("[%llu] Thread start\n", std::this_thread::get_id());
            service->run();
            printf("[%llu] Thread over\n", std::this_thread::get_id());
        };
        std::vector<std::thread *> threads;
        for (int i = 0; i < 3; ++i) {
            auto t = new std::thread(runnable);
            threads.push_back(t);
        }

        auto func = []() {
            printf("[%llu] Enter func\n", std::this_thread::get_id());
            std::this_thread::sleep_for(std::chrono::seconds(1));
            printf("[%llu] Leave func\n", std::this_thread::get_id());
        };
        for (int i = 0; i < 5; ++i) {
            service->post(func);
        }

        for (auto t: threads) {
            t->join();
            delete t;
        }

        printf("Before stop.\n");
        service->stop();
        printf("After stop.\n");

        printf("End.\n");
    }
}


int main() {
    Test::test03();
    return 0;
}