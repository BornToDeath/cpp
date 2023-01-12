//
// Created by lixiaoqing on 2023/1/12.
//

#include <iostream>
#include <filesystem>

void test01() {
    std::filesystem::path filePath("/Users/lixiaoqing/Desktop/Projects/scripts/cpp/test/test58_file_system.cpp");
    std::cout << filePath.empty() << std::endl
              << filePath.string() << std::endl
              << filePath.has_filename() << std::endl
              << filePath.filename() << std::endl
              << filePath.filename().string() << std::endl
              << filePath.parent_path() << std::endl
              << filePath.parent_path().string() << std::endl
              << filePath.root_path() << std::endl
              << filePath.root_name() << std::endl
              << filePath.root_directory() << std::endl
              << std::filesystem::file_size(filePath) << std::endl
              << std::filesystem::is_directory(std::filesystem::status(filePath)) << std::endl
              << std::filesystem::is_regular_file(std::filesystem::status(filePath)) << std::endl
              << std::filesystem::exists(filePath) << std::endl
              << std::filesystem::current_path() << std::endl;

    std::filesystem::path toPath("/Users/lixiaoqing/Desktop/Projects/scripts/cpp/test/test58_file_system.cpp.back");
    if (std::filesystem::exists(toPath)) {
        std::filesystem::remove(toPath);
    }
//    std::filesystem::copy(filePath, toPath);
    std::filesystem::copy(filePath, toPath, std::filesystem::copy_options::overwrite_existing);  // 覆盖源文件
    std::cout << "exist: " << std::filesystem::exists(toPath) << std::endl;
    std::cout << "remove: " << std::filesystem::remove(toPath) << std::endl;

    std::cout << "-----------------" << std::endl;
    std::filesystem::path dirPath("/Users/lixiaoqing/Desktop/Projects/scripts/cpp/test/");
    auto dir = std::filesystem::directory_entry(dirPath);
    std::cout << dir.exists() << std::endl
              << dir.path() << std::endl
              << std::filesystem::is_directory(dir.path()) << std::endl;

}

int main() {
    test01();
    return 0;
}