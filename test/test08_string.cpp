//
// Created by lixiaoqing on 2021/11/10.
//

/**
 * 结论：本例中，还是构造一次，频繁赋值的方法更省时
 *  test01 耗时：12031 us
 *  test02 耗时：27068 us
 */

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

unsigned long long getCurrentTimeMills();

void test01();

void test02();

void test03();

void test04();

void test05();

void test06();

void test07();

void test08();

void test09();

void test10();


int main() {
//    auto t1 = getCurrentTimeMills();
//    test01();
//    auto t2 = getCurrentTimeMills();
//    std::cout << "test01 耗时：" << (t2-t1) << std::endl;
//
//    t1 = getCurrentTimeMills();
//    test02();
//    t2 = getCurrentTimeMills();
//    std::cout << "test02 耗时：" << (t2-t1) << std::endl;

    test10();
    return 0;
}

void test10() {
    unsigned long long num = 100;
//    std::string s = num;   // error: 不可以直接赋值

    struct Node {
        std::string sss;
    };

    Node node;
    node.sss = num;   // error: 可以直接赋值，但是赋的值不对
    std::cout << node.sss << std::endl;
}

void test09() {
    std::string s;
    std::cout << sizeof(s) << std::endl;  // 24
    for (int i = 0; i < 10; ++i) {
        s.append("1");
        std::cout << sizeof(s) << std::endl;  // always 24
    }
}

void test01() {
    std::string str("");
    for (int i = 0; i < 100000; ++i) {
        str = "mei xiang ni yi ci, tian shang jiu piao luo yi li sha, yu shi bian you le sa ha la. mei xiang ni yi ci, tian shang jiu luo xia yi di shui, yu shi bian you le tai ping yang.";
        std::string aaa = str;
    }
}

void test02() {
    for (int i = 0; i < 100000; ++i) {
        std::string str(
                "mei xiang ni yi ci, tian shang jiu piao luo yi li sha, yu shi bian you le sa ha la. mei xiang ni yi ci, tian shang jiu luo xia yi di shui, yu shi bian you le tai ping yang.");
        std::string aaa = str;
    }
}

unsigned long long getCurrentTimeMills() {
    // 微秒
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now().time_since_epoch()
    );
    return us.count();
}

void test03() {
    std::cout << std::boolalpha;
    std::string s1 = "100000";
    std::string s2 = "100001";
    std::cout << s1.compare(s2) << std::endl;
    std::cout << (s1 < s2) << std::endl;
}

void test04() {
    class A {
    public:
        std::string s;
    };

    A a;
    std::cout << sizeof(a) << std::endl;

    a.s.append("123");
    std::cout << sizeof(a) << std::endl;
}

void test05() {
    struct A {
    public:
        std::string name;
        std::string city;
        std::vector<int> names;
        int age;
        int *ptr;
    public:
        A() = default;

        A(const A &obj) {
            std::cout << "调用A的拷贝构造" << std::endl;
            ptr = new int(*obj.ptr);
        }

//        A &operator=(const A &obj) {
//            std::cout << "调用A的赋值构造" << std::endl;
//            ptr = new int(*obj.ptr);
//            return *this;
//        }
    };

    A *a1 = new A();
    a1->name = "lixiaoqing";
    a1->city = "Beijing";
    a1->age = 27;
    a1->ptr = new int(10);
    a1->names.push_back(10);
    a1->names.push_back(20);
    a1->names.push_back(30);

    std::cout << "===============" << std::endl;
    A *a2 = new A();

    std::cout << "Before memcpy" << std::endl;
    std::cout << "a2->name:" << a2->name << std::endl;
    std::cout << "a2->city:" << a2->city << std::endl;
    std::cout << "a2->age:" << a2->age << std::endl;
//    std::cout << "a2->names:" << a2->names[0] << ", " << a2->names[1] << ", " << a2->names[2] << std::endl;

    std::cout << "Ready to memcpy" << std::endl;
//    memcpy(a2, a1, sizeof(A));

    *a2 = *a1;

    std::cout << "After memcpy" << std::endl;
    std::cout << "a2->name:" << a2->name << std::endl;
    std::cout << "a2->city:" << a2->city << std::endl;
    std::cout << "a2->age:" << a2->age << std::endl;
//    std::cout << "a2->names:" << a2->names[0] << ", " << a2->names[1] << ", " << a2->names[2] << std::endl;

    printf("a1: %p\n", a1->names.data());
    printf("a2: %p\n", a2->names.data());
    std::cout << "a1 vector address:" << a1->names.data() << std::endl;
    std::cout << "a2 vector address:" << a2->names.data() << std::endl;

    std::cout << "a1 ptr: " << a1->ptr << std::endl;
    std::cout << "a2 ptr: " << a2->ptr << std::endl;

    std::cout << "===============1" << std::endl;
    delete a1;
    std::cout << "===============2" << std::endl;
    delete a2;

    std::cout << "End" << std::endl;
}

void test06() {
    class A {
    public:
        char c;
    public:
        A() {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
    };

    A *ptr1 = new A[10];
    std::cout << sizeof(ptr1[0]) << std::endl;
    delete[] ptr1;
}

void test07() {
    class A {
    public:
        std::vector<int> nums;
    };

    A *a = new A();
    a->nums.push_back(10);
    a->nums.push_back(20);
    a->nums.push_back(30);

    A *b = new A();
    std::cout << b->nums.empty() << std::endl;
    *b = *a;
    std::cout << b->nums.empty() << std::endl;
    std::cout << b->nums[0] << std::endl;
    std::cout << b->nums[1] << std::endl;
    std::cout << b->nums[2] << std::endl;
}

void test08() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    const std::string fileName1 = "/Users/lixiaoqing/Desktop/Projects/scripts/cpp/test/files/aaa.txt";
    const std::string fileName2 = "/Users/lixiaoqing/Desktop/Projects/scripts/cpp/test/files/bbb.txt";

    auto file1 = fopen(fileName1.c_str(), "rb");
    if (file1 == nullptr) {
        std::cout << "file1 == nullptr" << std::endl;
        return;
    }

//    fseek(file1, 0, SEEK_END);
//    long fileSize = ftell(file1);
//    fseek(file1, 0, SEEK_SET);

    auto file2 = fopen(fileName2.c_str(), "wb");
    if (file2 == nullptr) {
        std::cout << "file2 == nullptr" << std::endl;
        return;
    }

    const int size = 1024 * 1024;
    char *buf = new char[size]();

    while (!feof(file1)) {
        int readNum = fread(buf, sizeof(char), size, file1);
        std::cout << "readNum=" << readNum << std::endl;
        fwrite(buf, sizeof(char), readNum, file2);
    }

    delete[] buf;
    fclose(file1);
    fclose(file2);
}













