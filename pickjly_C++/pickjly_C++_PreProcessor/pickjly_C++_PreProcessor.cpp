#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    cout << __DATE__ << __TIME__ << __FILE__ <<" "<< __LINE__ <<endl;
    return 0;
}

// # 预处理 #
// 预处理器的主要作用就是:    把通过预处理的内建功能对一个资源进行等价替换

// # 常见的预处理 #
// 文件包含  条件编译  布局控制  宏替换

// # 文件包含 #
// #include 是一种最为常见的预处理，主要是做为文件的引用组合源程序正文
// # 条件编译 #
// #if,#ifndef,#ifdef,#endif,#undef等也是比较常见的预处理
// 主要是进行编译时进行有选择的挑选，注释掉一些指定的代码，以达到版本控制、防止对文件重复包含的功能
// # 布局控制 #
// #progma，这也是我们应用预处理的一个重要方面，主要功能是为编译程序提供非常规的控制流信息
// # 宏替换 #
// #define，这是最常见的用法，它可以定义符号常量、函数功能、重新命名、字符串的拼接等各种功能。

// # 常见的预处理指令 #
    // #define      宏定义
    // #undef       取消宏
    // #include     文本包含
    // #ifdef       如果宏被定义就进行编译
    // #ifndef      如果宏未被定义就进行编译
    // #endif       结束编译块的控制
    // #if          表达式非零就对代码进行编译
    // #else        作为其他预处理的剩余选项进行编译
    // #elif        这是一种#else和#if的组合选项
    // #line        改变当前的行数和文件名称
    // #error       输出一个错误信息
    // #pragma      为编译程序提供非常规的控制流信息

// # 预定义标识符 #
// 为了处理一些有用的信息，预处理定义了一些预处理标识符，虽然各种编译器的预处理标识符不尽相同，但是他们都会处理下面的4种：
//      __FILE__   正在编译的文件的名字
//      __LINE__   正在编译的文件的行号
//      __DATE__   编译时刻的日期字符串，例如： "25 Dec 2000"
//      __TIME__   编译时刻的时间字符串，例如： "12:30:55"
//      例如：cout<<"The file is :"<<__FILE__"<<"! The lines is:"<<__LINE__<<endl;

// # 文件包含指令 #
    //  #include <iostream>             file://标准库头文件
    //  #include <iostream.h>          file://旧式的标准库头文件
    //  #include "IO.h"                     file://用户自定义的头文件
    //  #include "../file.h"                 file://UNIX下的父目录下的头文件
    //  #include "/usr/local/file.h"      file://UNIX下的完整路径
    //  #include "..//file.h"                file://Dos下的父目录下的头文件
    //  #include "//usr//local//file.h"   file://Dos下的完整路径