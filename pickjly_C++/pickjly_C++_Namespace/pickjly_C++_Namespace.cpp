#include <iostream>

namespace pickjly1{
    int a;
}

namespace pickjly2{
    int a;
}

int main(int argc, char **argv) {
    pickjly1::a = 1;
    std::cout << pickjly1::a << std::endl;
    pickjly2::a = 10;
    pickjly2::a ++;
    std::cout << pickjly2::a << std::endl;
    return 0;
}

// # 命名空间的由来 #
//  C++ 引入了命名空间的概念，计划重新编写库，将类、函数、宏等都统一纳入一个命名空间，这个命名空间的名字就是std。
// std 是 standard 的缩写，意思是“标准命名空间”。
// 为了避免头文件重名，新版 C++ 库也对头文件的命名做了调整，去掉了后缀.h，所以老式 C++ 的iostream.h变成了iostream，fstream.h变成了fstream。
// 而对于原来C语言的头文件，也采用同样的方法，但在每个名字前还要添加一个c字母，所以C语言的stdio.h变成了cstdio，stdlib.h变成了cstdlib。

// # namesapce 使用 #
// 推荐在函数内部声明 std。