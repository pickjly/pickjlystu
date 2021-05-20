/***
 * Author : pickjly
 * Email  : 2461789521@qq.com
 * Date   : 2021-05-15
 * Time   : 12:00
 * File   : @pickjly_C++_function_template.cpp
 * Content:
 *      C++ 函数模板
 * ***/

#include <iostream>
using namespace std;

template< typename T>
void swapT(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

void test01() {
    int a = 10, b = 20;
    swapT(a, b);    // 使用自动推导类型
    swapT<int>(a, b);   // 指定类型

    double c = 1.2, d = 3.4;
    swapT(c, d);
}

int main() {
    test01();
}