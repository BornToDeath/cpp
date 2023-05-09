//
// Created by boss on 2023/5/5.
//

#include <iostream>
#include <unordered_map>

class Date {
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

public:
    int year;
    int month;
    int day;
};

static std::unordered_map<int, int> CAL = {
        {0, 0},
        {1, 31},
        {2, 28},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31},
};

bool isRunYear(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}


long days(Date &date1, Date &date2) {
    long ans = 0;

    if (date1.year == date2.year) {  // same year
        if (date1.month == date2.month) {  // same month
            ans += date2.day - date1.day;
        } else {
            ans += CAL[date1.month] - date1.day + date2.day;
//            std::cout << ans << std::endl;
            if (isRunYear(date1.year) && date1.month == 2) {
                ans += 1;
            }
            for (int i = date1.month + 1; i < date2.month; ++i) {
                ans += CAL[i];
                if (isRunYear(date1.year) && i == 2) {
                    ans += 1;
                }
            }
        }
    } else {  // not the same year
        // 1. date1 current year days
        ans += CAL[date1.month] - date1.day;
        if (isRunYear(date1.year) && date1.month == 2) {
            ans += 1;
        }
//        std::cout << ans << std::endl;
        for (int i = date1.month + 1; i < CAL.size(); ++i) {
            ans += CAL[i];
            if (isRunYear(date1.year) && i == 2) {
                ans += 1;
            }
        }
//        std::cout << ans << std::endl;

        // 2. between date1.year and date2.year
        for (int i = date1.year + 1; i < date2.year; ++i) {
            ans += 365;
            if (isRunYear(i)) {
                ans += 1;
            }
        }
//        std::cout << ans << std::endl;

        // 3. date2 current year days
        for (int i = 1; i < date2.month; ++i) {
            ans += CAL[i];
            if (isRunYear(date2.year) && i == 2) {
                ans += 1;
            }
        }
        ans += date2.day;
//        std::cout << ans << std::endl;
    }
    return ans;
}

int main() {
    Date date1(2024, 1, 1);
    Date date2(2024, 4, 1);
    std::cout << days(date1, date2) << std::endl;
    return 0;
}

// 30 + 29 + 31