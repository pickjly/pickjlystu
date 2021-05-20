/***
 * Author : pickjly
 * Email  : 2461789521@qq.com
 * Date   : 2021-05-15
 * Time   : 12:00
 * File   : @pickjly_C++_file.c
 * Content:
 *      C++ 文件读写
 * ***/

#include <iostream>
#include <fstream>  // 包含头文件
using namespace std;

#define FileName "test.txt"

/***
 * 1  包含头文件
 * 2  创建流对象
 * 3  打开文件
 * 4  读写文件
 * 5  关闭文件
 * ***/

void test01() {

    // 创建流对象
    ofstream ofs;

    ofs.open("test.txt");

    ofs << "test.txt"; // << endl;
    ofs << endl << "test.txt";

    ofs.close();

}

int main() {

    test01();
    getchar();
}