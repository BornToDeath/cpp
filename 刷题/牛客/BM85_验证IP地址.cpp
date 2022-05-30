//
// Created by lixiaoqing on 2022/5/23.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 验证IP地址
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串
     */
    string solve(string IP) {
        if (IP.find(':') == std::string::npos) {
            return isIpv4(IP);
        } else {
            return isIpv6(IP);
        }
    }

private:
    std::string isIpv4(std::string &ip) {
        if (ip.empty() || std::count(ip.begin(), ip.end(), '.') != 3) {
            return "Neither";
        }
        if (ip[0] == '.' || ip[ip.length() - 1] == '.') {
            return "Neither";
        }
        for (int i = 0; i < ip.length(); ++i) {
            int j = i;
            while (j < ip.length() && ip[j] != '.') {
                ++j;
            }
            auto temp = ip.substr(i, j - i);
            if (temp.empty() || (temp[0] == '0' && temp.length() > 1) ||
                !isDigit(temp) || std::stoi(temp) < 0 || std::stoi(temp) > 255) {
                return "Neither";
            }
            i = j;
        }
        return "IPv4";
    }

    std::string isIpv6(std::string &ip) {
        if (ip.empty() || std::count(ip.begin(), ip.end(), ':') != 7) {
            return "Neither";
        }
        if (ip[0] == ':' || ip[ip.length() - 1] == ':') {
            return "Neither";
        }
        for (int i = 0; i < ip.length(); ++i) {
            int j = i;
            while (j < ip.length() && ip[j] != ':') {
                ++j;
            }
            auto temp = ip.substr(i, j - i);
            if (!isValid(temp)) {
                return "Neither";
            }
            i = j;
        }
        return "IPv6";
    }

private:
    bool isDigit(std::string &str) {
        for (auto ch: str) {
            if (ch < '0' || ch > '9') {
                return false;
            }
        }
        return true;
    }

    bool isValid(std::string &str) {
        if (str.empty() || str.length() > 4) {
            return false;
        }
        for (auto ch: str) {
            if (!(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F')) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::string ip = "20EE:FGb8:85a3:0:0:8A2E:0370:7334";
    std::cout << Solution().solve(ip) << std::endl;
    return 0;
}