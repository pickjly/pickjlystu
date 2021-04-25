#include <iostream>
#include <cstring>
using namespace std;

class human {   // 类成员可以被定义为 public、private 或 protected。默认情况下是定义为 private。

private:
    char* _name;
    int _age;
    int _sex;

public:
    human() {   // 

    }

    // human(char* name, int age, int sex) {    // 带参数的构造函数，相当于初始化类表来初始化   // 传统的初始化列表方式
    //     strcpy(_name, name);
    //     _age = age;
    //     _sex = sex;
    //     cout << " human()" << endl;
    // }
    // human(char* name, int age, int sex) : _name(name), _age(age), _sex(sex){    // 初始化列表
    //     cout << " human()" << endl;
    // }

    human(const human &obj) {    //
        _name = obj._name;
        _age = obj._age;
        _sex = obj._sex;
    }

    ~human() {
        cout << " ~human()" << endl;
    }

    int gethumanage();
    int sethumanage(int);
};

int human::gethumanage() {
    return _age;
}

int human::sethumanage(int age) {
    _age = age;
    return 1;
}

// typedef class human {    // class 相当与 typedef struct  // 编译报错
//     char* name;
//     int age;
//     int sex;
// }human;

int main(int argc, char **argv) {

    human human1;
    // human1.age = 1; // private error
    human1.sethumanage(10);
    human human2(human1);   // 复制构造函数也可以在这里
    cout << " human1's age is " << human1.gethumanage() << endl;
    return 0;
}