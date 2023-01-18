//
// Created by lixiaoqing on 2022/7/5.
//

#include <iostream>
#include <vector>

class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        for (auto &pair: intervals) {
            if (!(start >= pair.second || end <= pair.first)) {
                return false;
            }
        }
        intervals.emplace_back(start, end);
        return true;
    }

private:
    std::vector<std::pair<int, int>> intervals;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */