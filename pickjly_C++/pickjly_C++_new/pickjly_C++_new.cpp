#include <iostream>
using namespace std;

// 1 new的基本用法 ---> new 返回的是 数据类型的指针
int* func() {
    int* p = new int(10);
    return p;
}

// 2 new 用来开辟数组
void test() {
    int* p = new int[10];    // 10 代表 size, 
    for (int i = 0; i < 10; i ++) {
        // p[i] = i;
        cout << p << "\t" << i << endl;
        *p = i;
        ++ p;
    }
    for (int i = 0 ; i < 10; i ++) {
        --p;
        cout << *p << endl;
    }
}

int main() {
    int* accept_p = func();
    cout << " func() return " << *accept_p << endl;

    delete accept_p;
    cout << " func() return " << *accept_p << endl; // 再次访问， 值为 0

    test();

    getchar();
}