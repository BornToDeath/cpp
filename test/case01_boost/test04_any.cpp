//
// Created by lixiaoqing on 2021/11/16.
//

#include <iostream>
#include <string>
#include "boost/any.hpp"


void test01() {
    boost::any obj = 1;
    std::cout << typeid(obj).name() << std::endl;
    auto temp1 = boost::any_cast<int>(obj);
    std::cout << temp1 << std::endl;

    obj = 3.14;
    std::cout << typeid(obj).name() << std::endl;
    auto temp2 = boost::any_cast<double>(obj);
    std::cout << temp2 << std::endl;

    obj = std::string("Hello world.");
    std::cout << typeid(obj).name() << std::endl;
    auto temp3 = boost::any_cast<std::string>(obj);
    std::cout << temp3 << std::endl;

//    std::cout << std::to_string(obj.type()) << std::endl;
//    std::string str = obj.type();
}

void test02() {
    int n, a[17],b[17],c[17],i,sum=0;
    int s[17];
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    for(i=0;i<n;i++){
        s[i] = a[i] + b[i] + c[i];
        printf("%d ", s[i]);
    }
    for(i=0;i<n;i++){
        sum += s[i];
    }
    printf("%d", sum);
}

int main() {
    test02();
    return 0;
}