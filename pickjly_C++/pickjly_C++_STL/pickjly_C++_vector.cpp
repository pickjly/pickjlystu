/***
 * Author : pickjly
 * Email  : 2461789521@qq.com
 * Date   : 2021-05-15
 * Time   : 12:00
 * File   : @pickjly_C++_vector.cpp
 * Content:
 *      C++ 容器
 * ***/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Person {

private:
    
    string _name;
    int _age;

public:

    Person() {
        _name = "null";
        _age = 0;
    }

    Person(string name, int age) : _name(name), _age(age) {

    }

    void printinfo() {
        cout << " _name is " << _name << " and _age is " << _age << endl;
    }

};

void test02() {
    vector<Person> v;

    Person p1("qw", 1);
    Person p2("qh", 2);
    Person p3("fg", 3);
    Person p4("xc", 4);
    Person p5("as", 5);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    vector<Person>::iterator v_begin = v.begin();
    vector<Person>::iterator v_end = v.end();

    while (v_begin != v_end) {
        // (*v_begin ++).printinfo();   // 或者以下方式
        v_begin->printinfo();
        v_begin ++;
    }

}

void myprint(int val) {
    cout << " val is " << val << endl;
}

void test01() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator v_begin = v.begin();
    vector<int>::iterator v_end   = v.end();

    while (v_begin != v_end) {
        cout << *v_begin ++ << endl;
    }

// 10
// 20
// 30
// 40
// 50

    for_each(v.begin(), v.end(), myprint);
/***
 val is 10
 val is 20
 val is 30
 val is 40
 val is 50
***/
}

int main(int argc, char **argv) {
    test01();
    test02();
}