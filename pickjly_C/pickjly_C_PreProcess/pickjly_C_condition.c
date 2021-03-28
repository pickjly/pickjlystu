#include <stdio.h>

#define DEBUG
#ifdef DEBUG
// expression
#else
// expression

#ifndef __HEADERNAME_H__    // 防止头文件被重复引用
#define __HEADERNAME_H__
#endif

// 条件编译指令实现源代码的部分编译
#if i > 0
    // expression
#elif i == 0
    // expression
#else
    // expression
#endif

int main() {
    return 0;
}