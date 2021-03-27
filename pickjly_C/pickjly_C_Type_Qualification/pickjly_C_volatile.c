#include <stdio.h>

// # volatile # // 不稳定的
// 经常用于 被频繁改变的变量
// 声明变量使用volatile 是告诉编译器，不要对这样的语句进行优化。

int main(){
    volatile int a;
    a = 1;
    a = 2;
    return 0;
}

int square(volatile int *ptr) {

    int a,b;
    a = *ptr;
    b = *ptr;
    return a * b;   // 由于*ptr的值可能被意想不到地该变，因此a和b可能是不同的。结果，这段代码可能返不是你所期望的平方值！
}

// #一个参数既可以是const还可以是volatile吗？#
// 可以，例如只读的状态寄存器。它是volatile因为它可能被意想不到地改变。它是const因为程序不应该试图去修改它。