#include <stdio.h>

// # restrict #
// 用于告诉编译器，对象已经被指针所引用，不能通过除该指针外所有其他直接或间接的方式修改该对象的内容。


int foo(int *a, int *b)
{
    *a = 1;
    *b = 6;
    return *a + *b;
}
 
int rfoo(int *restrict a, int *restrict b)
{
    *a = 1;
    *b = 6;
    return *a + *b;
}
 
int main()
{
    int i =0;
    int *restrict a = &i;
    int *restrict b = &i;
 
   //  printf("%d ",foo(a,b));
    printf("%d ", rfoo(a,b));
}