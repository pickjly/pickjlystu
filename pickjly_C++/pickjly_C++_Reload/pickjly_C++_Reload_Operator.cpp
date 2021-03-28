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
    void setALL(int length, int width, int height) {
        _length = length;
        _width  = width;
        _height = height;
    }
    int getLength() {
        return _length;
    }

    box():_length(0), _width(0), _height(0) {

    }

    ~box() {

    }

    // 重载 + 运算符，用于把两个 Box 对象相加
    box operator+(const box& b)
    {
        box box3;    // 定义一个新的类对象，并将值保存到新的里面
        box3._length = _length + b._length;
        box3._width  = _width  + b._width;
        box3._height = _height + b._height;
        return box3;
    }

    // // 重载 + 运算符，用于把两个 Box 对象相加
    // Box operator*(const Box& b)
    // {
    //     // 保存在自身
    //     _length = _length * b._length;
    //     _width  = _width  * b._width;
    //     _height = _height * b._height;
    // }

};

int main(int argc, char **argv) {

    box box1;
    box1.setALL(2,4,6);
    box box2(box1);

    box box3 = box1 + box2;
    cout << " box3's length is " << box3.getLength() << endl;

    // box1 = box1 * box2;
    // cout << " box1's length is " << box1.getLength() << endl;

    return 0;
}