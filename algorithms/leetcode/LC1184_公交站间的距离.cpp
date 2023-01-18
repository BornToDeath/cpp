//
// Created by lixiaoqing on 2022/7/24.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
        int dis = 0;
        while (start != destination) {
            dis += distance[start];
            start = (start + 1) % distance.size();
        }
        int sum = std::accumulate(distance.begin(), distance.end(), 0);
        return std::min(dis, sum - dis);
    }
};

int main() {
    return 0;
}