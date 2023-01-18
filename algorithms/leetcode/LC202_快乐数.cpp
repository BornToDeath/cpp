//
// Created by lixiaoqing on 2022/8/31.
//

#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        /**
         * 方法1：如果不是快乐数，最终一定会形成一个循环，故用 set 记录出现过的数
         */
//        std::unordered_set<int> set;
//        while (set.count(n) == 0) {
////            printf("%d, ", n);
//            set.insert(n);
//            int num = 0;
//            while (n) {
//                num += (n % 10) * (n % 10);
//                n /= 10;
//            }
//            if (num == 1) {
//                return true;
//            }
//            n = num;
//        }
//        return false;

        /**
         * 方法2：判断循环就用快慢指针
         */
        auto getNext = [](int num) {
            int ans = 0;
            while (num) {
                ans += (num % 10) * (num % 10);
                num /= 10;
            }
            return ans;
        };
        int slow = n, fast = n;
        do {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        } while (slow != fast);
        return fast == 1;
    }
};

int main() {
    std::cout << std::boolalpha << Solution().isHappy(19) << std::endl;
    std::cout << std::boolalpha << Solution().isHappy(2) << std::endl;
    return 0;
}