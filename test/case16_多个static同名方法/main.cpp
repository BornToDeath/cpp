//
// Created by lixiaoqing on 2023/4/6.
//

/**
 * 结论：
 * 1. 多个 cpp 中如果具有相同的 static 方法，这些方法会全部编译到代码段中，它们的地址是不同的。
 * 2. 多个 cpp 中如果具有相同的非 static 方法，在编译时会报错。
 * 3. 类中的 static 变量也在 .data 段中。
 * 4. C++ 中，const 修饰的全局变量默认链接属性是 LOCAL 的，即只能在本文件中使用，不能在其他文件中使用；
 *    extern const 关键字修饰的全局变量的链接属性是 GLOBAL 的，可以在其他文件中使用。
 *    而在 C 中，const 修饰的全局变量的默认链接属性是 GLOBAL 的。
 */

#include <iostream>
extern void b_print();

int main() {
    printf("Hello, world.\n");
    b_print();
    return 0;
}