//
// Created by lixiaoqing on 2023/3/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> permutation(string s) {
        /**
         * 方法1：不 AC ，时间超限
         * 时间复杂度 O(n!) ，空间复杂度 O(n!)
         */
//        permute(s, 0);
//        return ans;

        /**
         * 方法2：借助哈希表
         * 时间复杂度 O(n!) ，空间复杂度 O(n!)
         */
//        std::unordered_set<std::string> us;
//        permute(s, 0, us);
//        std::vector<std::string> v(us.begin(), us.end());
//        return v;

        /**
         * 方法3：下一个排列
         * https://leetcode.cn/problems/zi-fu-chuan-de-pai-lie-lcof/solution/zi-fu-chuan-de-pai-lie-by-leetcode-solut-hhvs/
         * 时间复杂度 O(n!) ，空间复杂度 O(1)
         */
        if (s.empty()) {
            return {};
        }
        std::sort(s.begin(), s.end());
        std::vector<std::string> ans;
        do {
            ans.push_back(s);
        } while (next_permutation(s));
        return ans;
    }

private:
    bool next_permutation(std::string &s) {
        int i = s.length() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            --i;
        }
        if (i < 0) {
            return false;
        }
        int j = s.length() - 1;
        while (j >= 0 && s[i] >= s[j]) {
            --j;
        }
        std::swap(s[i], s[j]);
        std::reverse(s.begin() + i + 1, s.end());
        return true;
    }

    void permute(std::string &s, int pos, std::unordered_set<std::string> &us) {
        if (pos == s.length() - 1) {
            us.insert(s);
            return;
        }
        for (int i = pos; i < s.length(); ++i) {
            std::swap(s[pos], s[i]);
            permute(s, pos + 1, us);
            std::swap(s[pos], s[i]);
        }
    }

    void permute(std::string &s, int pos) {
        if (pos == s.length() - 1) {
            if (std::find(ans.begin(), ans.end(), s) == ans.end()) {
                ans.emplace_back(s);
            }
            return;
        }
        for (int i = pos; i < s.length(); ++i) {
            std::swap(s[pos], s[i]);
            permute(s, pos + 1);
            std::swap(s[pos], s[i]);
        }
    }

private:
    std::vector<std::string> ans;
};

int main() {
    std::string s = "vpvptjzh";
    auto ans = Solution().permutation(s);
    std::cout << "size: " << ans.size() << std::endl;
    for (auto &o: ans) {
        std::cout << o << std::endl;
    }
    return 0;
}