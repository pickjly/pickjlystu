#include <stdio.h>

// 指针是一个变量，其值为另一个变量的地
int main(int argc, char *argv[]) {
    int a = 10;
    // 声明指针的方式， 两种
    // 1
    int *a_pointer1 = &a;

    // 2
    // int *a_pointer2 = NULL;    // 在声明指针时，先将其指向NULL
    int *a_pointer2 = NULL;       // 在声明指针时，先将其指向NULL
    a_pointer2 = &a;

    printf("a_pointer1 address is %p, value is %d\n", a_pointer1, *a_pointer1);
    printf("a_pointer2 address is %p, value is %d\n", a_pointer2, *a_pointer2);
    a_pointer1 = NULL;
    a_pointer2 = NULL;

    // 指针的算数运算
    // 指针的每一次递增/递减，它其实会指向后/前一个元素的存储单元。且跳跃的字节数取决于指针所指向变量数据类型长度，比如 int 就是 4 个字节
    int var_arr[] = {1, 2, 3};
    int length = sizeof(var_arr) / sizeof(int);
    printf("length is %d\n", length);
    int *arr_pointer = &var_arr[0];
    for( int i = 0; i < length; i ++) {
        printf("arr_pointer now points to %d\n", *arr_pointer);
        arr_pointer ++;
    }
    
    
}