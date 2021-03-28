#include <stdio.h>

// # inline 函数 #
// 为了解决一些频繁调用的小函数大量消耗栈空间或是叫栈内存的问题，特别的引入了inline修饰符
// 栈空间就是指放置程序的局部数据也就是函数内数据的内存空间。
// 栈空间是有限的，假如频繁大量的使用就会造成因栈空间不足所造成的程序出错的问题：比如函数的死循环递归调用的最终结果就是导致栈内存空间枯竭，程序崩溃

// # 与 宏定义的区别 与 相同点 #
// 内联函数在可读性方面与函数是相同的，而在编译时是将函数直接嵌入调用程序的主体，省去了调用/返回指令，这样在运行时速度更快。
// 内联函数可以调试，而宏定义是不可以调试的

// 在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符。
// 如果想把一个函数定义为内联函数，则需要在函数名前面放置关键字 inlin
// 如果已定义的函数多于一行，编译器会忽略 inline 限定符。

int main() {
    return 0;
}