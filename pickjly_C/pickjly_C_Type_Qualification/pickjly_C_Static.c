#include <stdio.h>

void test1();

int main () {
    // test();  // 声明为static之后，无法访问
    test1();
}

// 当程序执行时， 会创建栈空间，函数的参数、局部变量等，会被压入栈中。
// 函数在调用结束后不会会自动清理栈上的内存，如果我们再次访问原来栈空间上的数据，那么我们读取到的数据还是可以读取到的，