/***
 *  @ pickjly
 *  @ 2416789521@qq.com
 *  @ 2021 / 04-25 / 00:30
 * ***/

/***
 *  @ 类 构造函数
 *  @ class and Constructors
 * ***/

#include <iostream>
using namespace std;

class stuConstructors {
public:
    int _data;
    stuConstructors() {
        _data = 0;
        cout << " no  parameter" << endl;
    }
    stuConstructors(int data) {
        _data = data;
        cout << " with  parameter" << endl;
    }
    // stuConstructors(const stuConstructors *stu1) {   // important
    stuConstructors(const stuConstructors &stu1) {
        // _data = stu1->_data;
        _data = stu1._data;
        cout << " copy  parameter" << endl;
    }

    ~stuConstructors() {
        cout << " Deconstruction" << endl;
    }
};

int main() {

    {
        // 默认构造函数
        stuConstructors stu;
        cout << " stu.data is " << stu._data << endl;

        // 有参数的构造
        stuConstructors stu1(10);
        cout << " stu1.data is " << stu1._data << endl;

        // 拷贝构造函数
        // stuConstructors stu2(&stu1); // important
        stuConstructors stu2(stu1);
        cout << " stu2.data is " << stu2._data << endl;
    }

    cout << endl << endl << endl;

    // 显示调用
    {
        stuConstructors stuC;
        stuConstructors stuC2 = stuConstructors(10);
        stuConstructors stuC3 = stuConstructors(stuC2);

        // important
        // 初始化匿名对象
        stuConstructors(1); // 该语句会直接进行创建一个对象，紧接着会析够掉
        // 不能使用拷贝额哦构造函数初始化匿名对象
        // stuConsttructors(stuC3); // 该语句 === stuConsttructors stuC3， 所以会出现stuC3重复定义的错误。
    }

    // 隐式转换
    {
        stuConstructors stuo1 = 10; // === stuConstructors stuo1 = stuConstructors(10);
        stuConstructors stuo2 = stuo1;
    }

    getchar();
}