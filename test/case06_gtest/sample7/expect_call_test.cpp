//
// Created by boss on 2023/12/4.
//

#include <gmock/gmock.h>

class Interface {
public:
    virtual ~Interface() {}

    virtual int foo(int value) = 0;

};

class MockInterface : public Interface {
public:
    MOCK_METHOD(int, foo, (int), (override));
};

TEST(MyTest, FooReturnsValue) {
    // 实例化模拟对象
    MockInterface mock;

    // 设置期望：当 mock 对象的 foo 方法用参数 5 被调用时，返回 10
    EXPECT_CALL(mock, foo(5)).WillOnce(::testing::Return(5));

    // 调用 mock 方法并验证结果
    int result = mock.foo(5);
    EXPECT_EQ(result, 5);

    EXPECT_CALL(mock, foo(10)).WillOnce(testing::Return(10));
    EXPECT_EQ(mock.foo(10), 10);

    EXPECT_CALL(mock, foo(20)).WillOnce(testing::Return(20));
    EXPECT_EQ(mock.foo(20), 20);

    int num = 30;
    EXPECT_CALL(mock, foo(num)).WillOnce(testing::Return(num));
    EXPECT_EQ(mock.foo(num), num);
}
