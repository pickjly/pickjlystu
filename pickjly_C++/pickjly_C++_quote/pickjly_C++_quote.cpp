#include <iostream>
using namespace std;

// 结构体类型的引用
typedef struct {
    int x;
    int y;
}Coor;

void function_pointer(int*, int*);
void function_quote(int &, int &);

int main(int argc, char **argv) {

    // 引用的简单介绍，别名
    int a = 10;
    int &quote = a;
    cout << " a is " << a << endl;
    quote = 20;
    cout << " a is " << a << endl;  // 需要让 a 做事情，不需要喊真名，喊小名也行
    cout << " quote is " << a << endl;  // 需要让 a 做事情，不需要喊真名，喊小名也行

    Coor c1;    // 定义一个变量，
    Coor &c = c1;   // 给c1取小名
    c.x = 10;
    c.y = 20;
    cout << " c1.x= " << c1.x << " c1.y = " << c1.y << endl;
    cout << " c.x= " << c1.x << " c.y = " << c1.y << endl;

    // 指针类型的引用
    int* p1 = &a;   // 定义int* 型的变量p1
    int* &p = p1;  // 给 p1 取小名叫做 p
    *p = 30;
    cout << " a = " << a << endl;
    cout << " *p = " << *p << endl;
    cout << " *p1 = " << *p << endl;    // 此处， p 是 p1 的别名， 想怎么从 p1 取值，就怎么从 p 取值。

    // 引用作函数参数
    int s1 = 3, s2 = 5;
    int* s1_d = &s1;
    int* s2_d = &s2;

    function_pointer(s1_d, s2_d);   // 通过声明指针传地址和直接取址，效果实质是一样的。
    cout << " s1 is " << s1 << " s2 is " << s2 << endl;

    function_pointer(&s1, &s2);
    cout << " s1 is " << s1 << " s2 is " << s2 << endl;

    function_quote(s1, s2);
    cout << " s1 is " << s1 << " s2 is " << s2 << endl;
}

void function_pointer(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void function_quote(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}