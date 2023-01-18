//
// Created by lixiaoqing on 2022/5/31.
//

#include <string>
#include <vector>

using namespace std;

class Frequency {
public:
    int getFrequency(vector<string> article, int n, string word) {
        return std::count(article.begin(), article.end(), word);
    }
};