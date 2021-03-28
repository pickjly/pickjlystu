#include <iostream>
using namespace std;

class box {
private:
    int _length;
    int _width;
    int _height;

public:
    void setLength(int length) {    // 在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符。
        _length = length;           // 如果想把一个函数定义为内联函数，则需要在函数名前面放置关键字 inline
    }                               // 如果已定义的函数多于一行，编译器会忽略 inline 限定符。
    void setWidth(int width) {
        _width = width;
    }
    int getLength() {
        return _length;
    }
    int getgetLength() {
        return this->getLength();   // 当我们调用成员函数时，实际上是替某个对象调用它。
    }

    box():_length(0), _width(0), _height(0) {

    }

    ~box() {

    }

    box(box &b) {
        _length = b._length;
        _width = b._width;
        _height = b._height;
    }

    friend int getWidth(box &);
};

int getWidth(box &boxn) {
    return boxn._width;
}

int main(int argc, char **argv) {

    box box1;
    box1.setLength(10);
    box box2(box1);
    cout << " box1's length is " << box1.getLength() << endl;
    cout << " box2's length is " << box2.getLength() << endl;

    box1.setWidth(5);
    cout << " box1's width is " << getWidth(box1) << endl;

    return 0;
}