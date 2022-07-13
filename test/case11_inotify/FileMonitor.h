//
// Created by lixiaoqing on 2022/7/12.
//

#ifndef INOTIFY_FILEMONITOR_H
#define INOTIFY_FILEMONITOR_H

#include <string>
#include <map>

/**
 * 文件监视器。
 * 用于监控文件系统中文件相关的事件，如创建、删除等操作。
 */
class FileMonitor {

public:

    FileMonitor() = default;

    ~FileMonitor() = default;

    void startWatch(const std::string &path);

    void stopWatch();

    bool addWatch(const std::string &path);

private:

    // inotify 句柄
    int inotify_fd{0};

    // inotify_add_watch返回值 -> 要监控的文件名 的映射
    std::map<int, std::string> watchDesc2Name;

    // 是否停止监控
    bool isStopped{false};
};


#endif //INOTIFY_FILEMONITOR_H
