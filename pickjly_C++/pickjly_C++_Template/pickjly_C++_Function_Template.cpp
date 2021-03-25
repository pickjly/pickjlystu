#include <iostream>
using namespace std;

// 在缺少泛型编程的情况下，下列的函数，只能被重载

    //     宏定义：
    // - 优点：代码复用，适合所有的类型
    // - 缺点：缺少类型检查，宏在预处理阶段就被替换掉，编译器并不知道宏的存在

    // 函数：
    // - 优点：真正的函数调用，编译器对类型进行检查
    // - 缺点：类型不同需要重复定义函数，代码无法复用

// void swap(double &, double &);
// void swap(int &, int &);

 // 函数模板是一种特殊的函数，可以使用不同的类型进行调用
 // 对于功能相同的函数，不需要重复编写代码，并且函数模板与普通函数看起来很类似，区别就是类型可以被参数化
 // 函数模板是一种特殊的函数，可以使用不同的类型进行调用
 // 对于功能相同的函数，不需要重复编写代码，并且函数模板与普通函数看起来很类似，区别就是类型可以被参数化
template <typename T>   // 泛型编程, T 是一个泛指类型
void SwapAB(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void fun(T a)
{
    cout << "void fun(T1 a)" << endl;
}
 
template <typename T1, typename T2>
void fun(T1 a, T2 b)
{
    cout << "void fun(T1 a, T2 b)" << endl;
}
 
void fun(int a, float b)
{
    cout << "void fun(int a, float b)" << endl;
}

template <typename T1, typename T2, typename T3>
int AddABCD(T1 &a, T2 &b, T3 &c) {
        return (static_cast<T1>(a + b + c));
}

int main (int argc, char** argv) {
    int a = 3;
    int b = 4;
    float c = 5.6;
    double d = 6;

    // 在使用函数模板时有两种方式
        // - 自动类型推到调用 Swap(a, b)
        // - 具体类型显示调用 Swap<int>(a, b)
    SwapAB(a, b);   // 原函数名为 swap(), 编译报错，需要变为 ::swap()
    cout << " a is " << a << " b is " << b << endl;
    SwapAB<int>(a, b);
    cout << " a is " << a << " b is " << b << endl;

    // 当使用较多的template, 可以从左向右指定
    cout << " a + b + c + d = " << AddABCD<int, int, float>(a, b, c) << endl;

    // 函数模板跟普通函数一样，也可以被重载
    // 编译器会优先去调用普通函数，但是当函数模板有更好的匹配时或使用限定符<>时，编译器就会去匹配函数模板。

    fun(a);   
    fun(a, c);	//普通函数void fun(int a, float b)已经能完美匹配，于是调用普通函数
    fun(c, a);	//这个调用，函数模板有更好的匹配，于是调用函数模板
    fun<>(a, c);	//限定只使用函数模板
    return 0;
}

// void swap(int &a, int &b) {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }
// void swap(double &a, double &b) {
//     double tmp = a;
//     a = b;
//     b = tmp;
// }