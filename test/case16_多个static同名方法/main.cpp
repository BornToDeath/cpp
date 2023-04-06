//
// Created by lixiaoqing on 2023/4/6.
//

/**
 * 结论：
 * 1. 多个 cpp 中如果具有相同的 static 方法，这些方法会全部编译到代码段中，它们的地址是不同的。
 * 2. 多个 cpp 中如果具有相同的非 static 方法，在编译时会报错。
 * 3. 类中的 static 变量也在 .data 段中。
 */

int main() {
    return 0;
}