//
// Created by lixiaoqing on 2021/11/3.
//

#include <iostream>
#include <fstream>

void test01();

void test02();

/**
 * std::ofstream 测试
 */
namespace ofstreamTest {
    void test01() {
        std::string imagePath = "/Users/lixiaoqing/Desktop/lixiaoqing/photos/the_light.jpg";

        /** 读文件 */
        std::ifstream ifs(imagePath, std::ios::in | std::ios::binary | std::ios::ate);
        int length = ifs.tellg();
        ifs.seekg(0, std::ios::beg);
        auto buf = new char[length]();
        ifs.read(buf, length);
        ifs.close();

        /** 写文件 */
        std::ofstream ofs;
        ofs.open(imagePath + ".jpg", std::ios::out | std::ios::trunc | std::ios::binary);
        ofs.write(buf, length);
        ofs.close();

    }
}

int main() {
    test02();
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

void test02() {
    std::string path = "/Users/lixiaoqing/Desktop/AIDot/aidot应用包/升级包（测试用）/AIDot_0_104_20220701/upgrade.json";
    std::ifstream ifs(path);
    std::string content{std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>()};
    std::cout << content << std::endl;

//    std::string str;
//    while (getline(ifs, str)) {
//        std::cout << str << "123" << std::endl;
//    }
    ifs.close();
}