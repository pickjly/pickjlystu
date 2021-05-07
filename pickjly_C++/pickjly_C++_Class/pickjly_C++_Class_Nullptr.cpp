/***
 * 
 *  Author: pickjly
 *  Date  : 2021-04-25
 *  Email : 2461789521@qq.com
 * 
 * ***/

#include <iostream>
using namespace std;

class Person {

private:
    int _age;

public:
    void EchoPersonAge () {
        if (this == NULL) {
            return;
        }
        cout << " _age is " << _age << endl;
    }
    void ShowPersonClass() {
        cout << " this is Person class" << endl;
    }
};

void test01() {
    Person *p = NULL;
    p->EchoPersonAge();  // 可以访问成员函数，但是不可以访问承运变量
    p->ShowPersonClass();
}

int main() {
    test01();
}
