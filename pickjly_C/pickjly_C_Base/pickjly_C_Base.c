/***
 * Author : pickjly
 * Email  : 2461789521@qq.com
 * Date   : 2021-05-24
 * Time   : 9:00
 * File   : @pickjly_C_Base.c
 * Content:
 *      关于C语言的一些基础知识
 * ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***
 * 
 * 详细解释
 * sizeof
 * strlen
 * 的区别
 * 
 * ***/
void test01() {
    // sizeof 是运算符， strlen是函数

    char str[100] = "1234567890";
    char *s = (char *)malloc(100);
    strcpy(s, str);

    printf(" sizeof str[100] is %d\n", sizeof(str));    //  sizeof str[100] is 100
    printf(" strlen str[100] is %d\n", strlen(str));    //  strlen str[100] is 10

    printf(" sizeof s        is %d\n", sizeof(s));    //  sizeof s        is 8
    printf(" strlen s        is %d\n", strlen(s));    //  strlen s        is 10

}

int main () {
    test01();
}