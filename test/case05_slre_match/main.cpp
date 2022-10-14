#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include "slre.h"

using namespace std;

void test01() {
    // const string re = "^(B20)*";
    const string re = "(BPZ20)*";
    // const string re = "^(B20|BPZ20)*";

    vector<string> strs;
    strs.push_back("B20210403151208.mp4");
    strs.push_back("20210403151208.mp4");
    strs.push_back("BPZ20210409120723");
    strs.push_back("1BPZ20210409120723");


    for (auto &str : strs) {
        int res = slre_match(re.c_str(), str.c_str(), str.length(), NULL, 0, 0);
        printf("%s\tres=%d\n", str.c_str(), res);
    }

    // ostringstream oss;
    // oss << "str="
    //     << str
    //     << ", "
    //     << "res="
    //     << res
    //     << "\n";
    // cout << oss.str() << endl;
}

void test02() {
    string re = R"(^[0-9]{2})";
    std::string str = R"(2{2})";

    int res = slre_match(re.c_str(), str.c_str(), str.length(), nullptr, 0, 0);
    printf("res=%d\n", res);
}

void test03() {
    std::string str = "22";
    std::regex regex1("^[0-9]{2}");
    bool ret = std::regex_match(str.c_str(), regex1);
    std::cout << ret << std::endl;
}

void test04() {
//    const string re = "^.*(_back|_[1-3])(\\.[^.]+)?$";  // false
//    const string re = ".*(_back|_[1-3])";  // true
//    const string re = ".*(_back|_[1-3])(\\..+)";  // true
    const string re = "^.*(_back|_[1-3])(\\.[^\\.]+)?$";  // true
    std::cout << re << std::endl;

    const std::string str = "20221014073948_back.ts\\";
    std::cout << str << std::endl;

    int res = slre_match(re.c_str(), str.c_str(), str.length(), NULL, 0, 0);
    std::cout << res << std::endl;

    std::regex regex(re);
//    std::cout << std::regex_match(str, regex) << std::endl;
    std::cout << std::regex_search(str, regex) << std::endl;
}

int main() {
    test04();
    return 0;
}