#include <iostream>
using namespace std;

// 同一个作用域内，可以声明几个功能类似的同名函数，但是这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同

void print(int i) {
    cout << "整数为: " << i << endl;
    }

    void print(double  f) {
    cout << "浮点数为: " << f << endl;
    }

    void print(char c[]) {
    cout << "字符串为: " << c << endl;
    }

int main() {
    // 输出整数
   print(5);
   // 输出浮点数
   print(500.263);
   // 输出字符串
   char c[] = "Hello C++";
   print(c);
 
   return 0;
}