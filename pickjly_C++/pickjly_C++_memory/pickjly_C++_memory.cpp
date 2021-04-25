#include <iostream>
using namespace std;

// 1 代码区
    // 二进制代码，由操作系统管理

    /******
     * 代码区特点
     * 1 共享 ：频繁调用，只需要在内存有一份就可以
     * 2 只读 ：
     * 存放cpu的执行指令
     * 
     * ******/

// 2 全局区
    // 全局变量， 静态变量， 常量（字符串常量 和 const 修饰的常量 ）

    /******
     * 全局区特点
     * 1 该区域的数据在程序执行之后，由操作系统释放
     * *******/

// 3 栈区
    // 存放函数的参数， 局部变量

// 4 堆区
    // 程序员分配与释放

// 不同的生命周期

int g_a = 10;   // 全局变量
int g_b = 10;
static int s_g_a = 10;  // 全局静态变量
static int s_g_b = 10;
const int c_g_a = 10;   // 全局常量
const int c_g_b = 10;
 
int* func(int v_a) {    // 形参数据也放在栈区
    int v_b = 10; // 局部变量， 存放在栈区
    cout << "func 中， a 的地址是 " << &v_a << endl;
    cout << "func 中， b 的地址是 " << &v_b << endl;
    return &v_b;  // 不可返回局部变量的地址
}

int* func_heap() {
    int *a = new int(10);   // 开辟一个int内存， 赋值为10
    return a;
}

int main(int argc, char **argv) {
    
    {   // 全局区
        // 声明局部变量，打印局部变量和全局变量的地址
        int a = 10;
        int b = 10;
        static int s_a = 10;
        static int s_b = 10;
        
        const int c_a = 10;
        const int c_b = 10;

        cout << "局部变量 a 的地址是 " << &a << endl;
        cout << "局部变量 b 的地址是 " << &b << endl;

        cout << endl;

        cout << "全局变量 a 的地址是 " << &g_a << endl; // 可以发现 全局变量和静态变量的地址值在一个地址段
        cout << "全局变量 b 的地址是 " << &g_b << endl;

        cout << endl;

        cout << "全局静态变量 a 的地址是 " << &s_g_a << endl;
        cout << "全局静态变量 b 的地址是 " << &s_g_b << endl;

        cout << endl;

        cout << "局部静态变量 a 的地址是 " << &s_a << endl;
        cout << "局部静态变量 b 的地址是 " << &s_b << endl;

        cout << endl;

        cout << "字符串常量的地址是 " << &("Hello world") << endl;

        cout << endl;


        cout << "全局常量 a 的地址是 " << &c_g_a << endl;
        cout << "全局常量 b 的地址是 " << &c_g_b << endl;
        cout << "局部常量 a 的地址是 " << &c_a << endl; // 局部常量的地址 和 局部变量 是同一地址段
        cout << "局部常量 b 的地址是 " << &c_b << endl;

        // in all
        // 全局区：     全局变量， 静态变量（全局和局部）， 常量（全局常量， 字符串常量）
        // 非全局区域：  局部变量， 局部常量
    }

    {   // 栈区
        // int *c = func();
        int stack_a = 10;
        cout << "stack address is " << &stack_a << endl;
        func(stack_a);
        // cout << "func return address and its value is " << *c << endl;  // 访问出错
    }

    {   // 堆区， 用来在堆区开辟内存
        int *heap_a = func_heap();
        cout << "func_heap return " << *heap_a << endl;
    }

    getchar();
}