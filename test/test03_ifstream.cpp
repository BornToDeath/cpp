//
// Created by lixiaoqing on 2021/11/3.
//

#include <iostream>
#include <fstream>

void test01();

int main() {
    test01();
    return 0;
}

void test01() {
    auto imagePath = "/Users/lixiaoqing/Desktop/projects/AIDot/files/images/1620717326899742.jpg";

    std::ifstream ifs(imagePath, std::ios::binary | std::ios::ate);
    if (!ifs.is_open()) {
        std::cout << "文件打开失败！" << std::endl;
        return;
    }

    int size = static_cast<int>(ifs.tellg());
    std::cout << size << std::endl;

    ifs.seekg(0, std::ios::beg);
    auto buf = new char[size]();
    ifs.read(buf, size);
    ifs.close();

    delete[] buf;
}