#include <iostream>
using namespace std;

int main( int argc, char* argv[]) {
    // const 修饰指针有三种情况：
    // 1 const修饰指针 -->常量指针
    // 2 const修饰常量 -->指针常量
    // 3 const 既修饰指针，也修饰常量

    int a = 10, b;
    // 1  const 修饰指针
    const int* p1 = &a;     // 被修饰的是 int*, 此时，  指针指向可以修改，但是指针的值不可以修改。
    int *p2 = &a;           // 声明另一个指针指向a，
    cout << " a is " << *p2 << endl;
    // *p1 = 12;            // 此时通过常量指针，不可以修改指向的指针的值
    *p2 = 11;               // 但是可以通过另一个指针修改常量指针指向的值
    cout << " a is " << *p2 << endl;
    a = 13;                 // 也可以通过变量本身去修改 值
    cout << " a is " << *p2 << endl;
    int *pb = &b;
    *pb = 20;               // 初始时，指针指向的值没有初始化，这里是否可以修改？
    cout << " b is " << *pb << endl;

    int c = 1, d = 2;
    // 2 const 修饰常量
    int* const p3 = &c;
    // p2 = &d;             // 指针的指向不可以更改，
    *p3 = 3;                // 但是指向的值，也可以改变
    cout << " c is " << *p3 << endl;

    int e = 3, f;
    const int* const p4 = &e;
    // p4 = &f;                // 这是错误的
    // *p4 = 5;                // 修改指向的值也是错误的
    e = 5;                      // 可以通过变量本身修改
    const int* const p5 = &f;
    // *p5 = 5;                    // 初始时，指针指向的值没有初始化，这里是否可以修改？答案是不可以


    getchar();
}