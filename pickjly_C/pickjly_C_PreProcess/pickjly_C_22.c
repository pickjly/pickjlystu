#include <stdio.h>

// 在#define中，有两个特殊的符号，他们是#和##
// # 代表替换的意思
// ## 拼接

#include<stdio.h>

#define dprint(expr) printf(#expr"=%d\n",expr);
#define f(a,b) a##b

int main() 
{  
    int a=20,b=10;
    int as = 15;
    dprint(a/b);    // // 输出：a/b=2
}

// int main()
// {
//     int a2=3;
//     //printf("%s\n",f(a,2));错误，没有a2的字符串变量 
//     printf("%d\n",f(a,2));//正确 
//     printf("%s\n", h(f(1,2)));
//     printf("%s\n", g(f(1,2)));
//     return 0;
// }
// /*输出
// 3
// 12
// f(1,2)
// */

