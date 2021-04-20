#include <iostream>
using namespace std;

/*
二位数组的定义方式：
    1  数据类型 数组名[ 行数 ][ 列数 ];
    2  数据类型 数组名[ 行数 ][ 列数 ] = { 数据1, 数据2, 数据3, 数据4 };
    3  数据类型 数组名[     ][ 列数 ] = { 数据1, 数据2, 数据3, 数据4 };
    4  数据类型 数组名[ 行数 ][ 列数 ] = { { 数据1, 数据2}, {数据3, 数据4} };
*/
int main() {
    // 1
    int array[2][3];
    array[0][0] = 1;
    array[0][1] = 2;
    array[0][2] = 3;
    array[1][0] = 4;
    array[1][1] = 5;
    array[1][2] = 6;

    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < 3; j ++) {
            cout << " " << array[i][j] << "\t";
        }
        cout << endl;
    }

    // 2
    int array2[2][3] = {1,2,3,4,5,6};
        for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < 3; j ++) {
            cout << " " << array2[i][j] << "\t";
        }
        cout << endl;
    }

    // 3
    int array3[2][3] = { {1, 2, 3}, {1, 2, 3} };
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < 3; j ++) {
            cout << " " << array3[i][j] << "\t";
        }
        cout << endl;
    }

    int array4[2][3] = { {1, 2, 3}, {1, 2, 3} };
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < 3; j ++) {
            cout << " " << array4 [i][j] << "\t";
        }
        cout << endl;
    }

    // 通过sizeof获取数组大小
    cout << " size of array is " << sizeof(array) << endl;
    cout << " array in all has " << sizeof(array) / sizeof(int) << " elements" << endl;
    cout << " array[0] has " << sizeof(array[0]) / sizeof(int) << " elements" << endl;

    // 获取二位数组的行数, 列数
    cout << " the rows of array is " << sizeof(array) / sizeof(array[0]) << endl;
    cout << " the cols of array is " << sizeof(array[0]) / sizeof (array[0][0]) << endl;

    // 二位数组的首地址
    cout << " the head address of array is " << array << endl;
    // cout << " the head address of array is " << (int)array << endl;
    cout << " the head address of array of first line is " << array[0] << endl;

    // 想知道 数组没有全部赋值时， 数组的大小
    int array_test1[10];
    array_test1[0] = 1;
    cout << " array_test1 size is " << sizeof(array_test1) / sizeof(int) << endl;
    array_test1[1] = 2;
    cout << " array_test1 size is " << sizeof(array_test1) / sizeof(int) << endl;
 
    getchar();
}