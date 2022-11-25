//
// Created by lixiaoqing on 2022/11/25.
//

/*
 * 字节面试题：队列中元素并发执行，最大并发数为2
 */

#include <queue>
#include <thread>
#include <memory>
#include <mutex>
#include <unistd.h>
#include <vector>

class Request {
public:
    Request(int value, int time) : value(value), time(time) {}

public:
    int value;
    int time;
};

static std::queue<std::shared_ptr<Request>> _queue;
static std::mutex _mutex;
static std::vector<std::thread *> threadPool;

void scheduler(int max) {
    auto process = [](int tid) {
        while (true) {
            std::shared_ptr<Request> request = nullptr;
            {
                std::unique_lock<std::mutex> lock;
                if (_queue.empty()) {
                    break;
                }
                request = _queue.front();
                _queue.pop();
            }
            usleep(request->time * 1000);
            printf("%d\n", request->value);
        }
//        printf("thread %d quit\n", tid);
    };
    for (int i = 0; i < max; ++i) {
        auto t = new std::thread(process, i);
        threadPool.push_back(t);
    }
}

int main() {
    _queue.push(std::make_shared<Request>(1, 1000));
    _queue.push(std::make_shared<Request>(2, 500));
    _queue.push(std::make_shared<Request>(3, 300));
    _queue.push(std::make_shared<Request>(4, 400));
    scheduler(2);
    for (auto t: threadPool) {
        t->join();
        delete t;
        t = nullptr;
    }
    printf("end\n");
    return 0;
}