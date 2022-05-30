//
// Created by lixiaoqing on 2022/5/24.
//

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

void print(const std::vector<Interval> &inters) {
    for (auto &inter: inters) {
        printf("[%d, %d], ", inter.start, inter.end);
    }
    printf("\n");
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        /**
         * 方法1：分治的思想
         */
//        divide(intervals, 0, intervals.size() - 1);

        /**
         * 方法2
         */
        if (intervals.empty()) {
            return {};
        }
        std::sort(intervals.begin(), intervals.end(), [](const Interval &inter1, const Interval &inter2) {
            if (inter1.start < inter2.start) {
                return true;
            } else if (inter1.start == inter2.start && inter1.end < inter2.end) {
                return true;
            }
            return false;
        });
//        print(intervals);
        vector<Interval> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back().end >= intervals[i].start) {
                res.back().end = std::max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main() {
    std::vector<Interval> inters = {
            {1, 4},
            {2, 3}
    };
    auto res = Solution().merge(inters);
    print(res);
    return 0;
}