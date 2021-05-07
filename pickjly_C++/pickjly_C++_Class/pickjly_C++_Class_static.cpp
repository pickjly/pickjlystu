/***
 * 
 *  Author: pickjly
 *  Date  : 2021-04-25
 *  Email : 2461789521@qq.com
 * 
 * ***/

#include <iostream>
using namespace  std;

/***
 * 
 *  静态成员 ： 静态成员变量 & 静态成员函数
 *    静态成员变量
 *       所有对象共享一份数据
 *       编译阶段分配内存 (全局区 )
 *       类内声明，类外初始化
 *    静态成员函数
 *       所有对象共享的函数
 *       静态成员函数之可以访问静态变量
 * 
 * ***/

class static_test {
public:
    int data;
    static int test;    // 类内声明
    static void func1() { // 类内声明
        test = 50;
        // data = 10;  // error: invalid use of member ‘static_test::data’ in static member function
        cout << " func1 调用, test is " << test << endl;
    }
    static void func2() {    // 类内声明
        cout << " func2 调用" << endl;
    }
private:
    static int test_error;  // 静态成员函数也有权限访问问题
};

int static_test::test = 100;
int static_test::test_error = 100;  // 声明为私有是可以的

int main() {
    {
        static_test test01;
        cout << " test01 : test is " << test01.test << endl;

        static_test test02;
        test02.test = 200;
        cout << " test01 : test is " << test01.test << endl;
        cout << " test02 : test is " << test02.test << endl;

        // test01 : test is 100
        // test01 : test is 200
        // test02 : test is 200
    }

    {
        // 静态成员函数可以通过两种方式进行访问

        // 通过类访问
        static_test test03;
        cout << " test03 : test is " << test03.test << endl;

        // 通过类名访问
        cout << " static_test is " << static_test::test << endl;
        // test03 : test is 200
        // static_test is 200

        // cout << " static_test is " << static_test::test_error << endl; // 可以在类外初始化，但是不可以进行访问
    }
    
    {
        // 静态成员函数的访问方式有两种

        // 通过对象访问
        static_test test04;
        test04.func2();

        // 通过类名访问
        static_test::func2();
    }
     
    {
        static_test::func1();
    }

}