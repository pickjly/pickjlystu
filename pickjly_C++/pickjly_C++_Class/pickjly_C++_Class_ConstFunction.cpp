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
    int _Age;
    mutable int _wAge;

public:
    // this 的本质是 指针常量， 即指针指向不可更改，只能指向当前对象
    void showPersonAge() const{ // 相当于 const Person* const this; 只是把  const 放在了函数最后
        // this->_Age = 100;    // assignment of member ‘Person::_Age’ in read-only object
        this->_wAge = 100;      // mutable 修饰的变量可以在const函数中修饰
    }
    Person(int Age, int aAge):  _Age(Age), _wAge(aAge){

    }
    void showconst() {

    }
};

void test01() {
    const Person p1(10, 20);    // 

    p1.showPersonAge();
    // p1.showconst();  //in call to ‘void Person::showconst()  // 常对象只能调用常函数


}

int main() {

}