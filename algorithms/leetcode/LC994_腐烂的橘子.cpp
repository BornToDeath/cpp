//
// Created by lixiaoqing on 2023/7/24.
//

#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>

using std::vector;

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        /*
         * 方法1: BFS: 先找到所有 1, 然后逐轮腐烂, 每轮将腐烂的橘子移除, 直到结束
         * 时间复杂度 O(mn), 空间复杂度 O(mn)
         */
//        if (grid.empty()) {
//            return -1;
//        }
//
//        int ans = 0;
//        std::vector<std::pair<int, int>> ones;
//        const int rows = grid.size(), cols = grid.front().size();
//
//        auto infect = [&](int i, int j) -> bool {
//            if (i - 1 >= 0 && grid[i - 1][j] == 2) {
//                return true;
//            }
//            if (i + 1 < rows && grid[i + 1][j] == 2) {
//                return true;
//            }
//            if (j - 1 >= 0 && grid[i][j - 1] == 2) {
//                return true;
//            }
//            if (j + 1 < cols && grid[i][j + 1] == 2) {
//                return true;
//            }
//            return false;
//        };
//
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                if (grid[i][j] == 1) {
//                    ones.emplace_back(i, j);
//                }
//            }
//        }
//
//        while (!ones.empty()) {
//            std::vector<std::pair<int, int>> v;
//            for (const auto &e: ones) {
//                if (infect(e.first, e.second)) {
//                    v.emplace_back(e.first, e.second);
//                }
//            }
//            if (v.empty()) {
//                return -1;
//            }
//            for (const auto &e: v) {
//                grid[e.first][e.second] = 2;
//                ones.erase(std::find(ones.begin(), ones.end(), e));
//            }
//            ++ans;
//        }
//
//        return ans;

        /*
         * 方法2: BFS: 方法1的改进, 使用一个变量来记录新鲜橘子的数量
         * 时间复杂度 O(mn), 空间复杂度 O(mn)
         */
        if (grid.empty()) {
            return -1;
        }
        int round = 0, count = 0;
        std::queue<std::pair<int, int>> q;
        const int rows = grid.size(), cols = grid.front().size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    ++count;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        const std::vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        while (count > 0 && !q.empty()) {
            // 每轮都会腐烂新的橘子
            ++round;
            const int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto p = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int x = p.first + dx[j], y = p.second + dy[j];
                    if (x < 0 || x >= rows || y < 0 || y >= cols) {
                        continue;
                    }
                    if (grid[x][y] == 1) {
                        grid[x][y] = 2;  // 表示这个新鲜橘子被腐烂了
                        --count;         // 新鲜橘子的数量减一
                        q.push({x, y});  // 被腐烂的新鲜橘子添加到队列中, 在下一轮次中腐烂别的橘子
                    }
                }
            }
        }
        return count > 0 ? -1 : round;
    }

private:
    int infect(std::vector<std::vector<int>> &grid, int i, int j) {
//        if (i < 0 || i >= grid.size() || j < 0 || j >= grid.front().size() || grid[i][j] != 1) {
//            return 0;
//        }
//        grid[i][j] = 3;
//        int count = 0;
//        count = std::max(count, infect(grid, i - 1, j) + 1);
//        count = std::max(count, infect(grid, i + 1, j) + 1);
//        count = std::max(count, infect(grid, i, j - 1) + 1);
//        count = std::max(count, infect(grid, i, j + 1) + 1);
//        return count;

        int count = 0;
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            grid[i - 1][j] = 3;
            count = std::max(count, infect(grid, i - 1, j) + 1);
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
            grid[i + 1][j] = 3;
            count = std::max(count, infect(grid, i + 1, j) + 1);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            count = std::max(count, infect(grid, i, j - 1) + 1);
        }
        if (j + 1 < grid.front().size() && grid[i][j + 1] == 1) {
            count = std::max(count, infect(grid, i, j + 1) + 1);
        }
        return count;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}
    };
    grid = {
            {2, 1, 1},
            {0, 1, 1},
            {1, 0, 1}
    };
    grid = {
            {0, 2}
    };
    std::cout << Solution().orangesRotting(grid) << std::endl;
    return 0;
}