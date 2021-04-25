/***
 *  @ pickjly
 *  @ 2416789521@qq.com
 *  @ 2021 / 04-25 / 00:30
 * ***/

/***
 *  @ 浅拷贝 和 深拷贝
 *  @ Shallow copy and deep copy
 * ***/

#include <iostream>
using namespace std;

class stuConstructors {
public:
    int _data;
    int *_address;
    stuConstructors() {
        _data = 0;
        cout << " no  parameter" << endl;
    }
    stuConstructors(int data, int address) {
        _data = data;
        _address = new int(address);    // 申请内存，将内存的值存储为address， 并返回地址。
        cout << " with  parameter" << endl;
    }
    // stuConstructors(const stuConstructors *stu1) {   // important
    // stuConstructors(const stuConstructors &stu1) {   // 这是默认的拷贝构造函数，称之为浅拷贝构造函数
                                                        // 当类中出现地址时，需要在析够函数中，释放两次指针，会产生错误
    //     // _data = stu1->_data;
    //     _data = stu1._data;
    //     cout << " copy  parameter" << endl;
    // }

    stuConstructors(const stuConstructors &stu1) {   // 实现自己的拷贝构造函数
        cout << " copy  parameter" << endl;
        _data = stu1._data;
        _address = new int(*stu1._address);
    }

    ~stuConstructors() {
        cout << " Deconstruction" << endl;
        if (_address != NULL) {
            delete(_address);
            _address = NULL;
        }
    }
};

int main() {

    // 显示调用
    { 
        stuConstructors stuC2 = stuConstructors(10, 12);
        stuConstructors stuC3 = stuConstructors(stuC2);
    }

    getchar();
}