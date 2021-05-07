/***
 * 
 *  Author: pickjly
 *  Date  : 2021-04-25
 *  Email : 2461789521@qq.com
 * 
 * ***/

#include <iostream>
using namespace std;

// 成员函数和成员变量的存储
class test{
private:
    int data;   // 非静态成员变量 占位 4

public:
    static int s_data;  // 静态成员变量不占用类的空间
    void func() {}      // 非静态成员函数， 也不占用类的空间， 不属于类的对象上
    static void func2(){}   // 静态成员函数， 不属于类的对象上
};

int test::s_data = 0;

int main() {
    // 类为空时，占用空间为 1 字节, 空的类也需要独立的地址
    cout << " test size is " << sizeof(test) << endl;
}