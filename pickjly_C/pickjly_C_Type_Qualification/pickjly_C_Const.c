#include <stdio.h>

// # const #
// 用于修饰一个对象，表明该对象是一个常量（constant）。被const修饰的对象只能初始化一次，之后它的值就不能被修改
const int file_name = 1;
// file_name = 2;   // 编译此句报错
// 如果想在多个文件之间共享const对象，必须在变量的定义之前添加extern关键字
extern const int a = 1;

int main () {
    // int &b = a;  // 编译不通
    int c = 2;
    int &d = c;
    
}