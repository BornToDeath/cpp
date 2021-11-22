//
// Created by lixiaoqing on 2021/11/16.
//

#include <boost/asio.hpp>
#include <iostream>

void handler(const boost::system::error_code &ec) {
    std::cout << "5 s." << std::endl;
}

int main() {
    boost::asio::io_service io_service;
    boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(5));
    std::cout << __LINE__ << std::endl;
    timer.async_wait(handler);
    std::cout << __LINE__ << std::endl;
    io_service.run();
    std::cout << __LINE__ << std::endl;
}