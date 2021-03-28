#include <stdio.h>
#include <time.h>

// # 寄存器变量 #
// 用register声明的变量是寄存器变量

// 一般声明的变量是在内存中的，但是使用register声明的变量，存取以及计算更快
// 相比与一般的变量，寄存器变量
    // 1 不能取地址
    // 2 运算速度快

int main() {
    int a = 0;
    register int b = 0;
    int i = 0;

    time_t time_common_start, time_common_end;
    time_t time_register_start, time_register_end;
    double time_cost_common = 0;
    double time_cost_register = 0;

    time(&time_common_start);
    for(i = 0; i < 50000000; i ++) {
        a++;
        a--;
    }
    time(&time_common_end);

    time(&time_register_start);
    for(i = 0; i < 50000000; i ++) {
        a++;
        a--;
    }
    time(&time_register_end);
    // printf(" common   var cost %f.6\n", time_cost_common   = time_common_end   - time_common_start);
    // printf(" register var cost %f.6\n", time_cost_register = time_register_end - time_register_start);
    printf(" common   var cost %f.10\n", difftime( time_common_end, time_common_start));
    printf(" common   var cost %f.10\n", difftime( time_register_end, time_register_start));
    return 0;
}