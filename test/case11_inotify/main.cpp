//
// Created by lixiaoqing on 2022/7/12.
//

#include <iostream>
#include "FileMonitor.h"

int main() {
    std::string dirPath = "/home/nvidia/logs";
    FileMonitor fileMonitor;
    fileMonitor.startWatch(dirPath);
    return 0;
}