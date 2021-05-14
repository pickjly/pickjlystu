/***
 * Author : pickjly
 * Email  : 2461789521@qq.com
 * Date   : 2021-05-11
 * Time   : 23:00
 * File   : @pickjly_C_Pointer_array.c
 * Content:
 *      指针数组
 * ***/

#include <stdio.h>

// 如果一个数组中的所有元素保存的都是指针，那么我们就称它为指针数组。指针数组的定义形式一般为：
// dataType *arrayName[length];
// 理解方式为， *修饰的是arrayName， arrayName是一个数组，所以是一个指针数组
// 括号里面说明arrayName是一个数组，包含了length个元素，括号外面说明每个元素的类型为dataType *。

int main(int argc, char ** argv) {
    int a = 1, b = 2, c = 3;
    int *pointer_array[3] = {&a, &b, &c};
    int **p_pointer_array = &pointer_array;
}