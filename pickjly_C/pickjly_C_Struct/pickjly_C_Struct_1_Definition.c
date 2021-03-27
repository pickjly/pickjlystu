#include <stdio.h>

// C语言中，可以使用结构体（Struct）来存放一组不同类型的数据
// 在声明结构体时，需要注意对齐
struct student{
    int age;
    int num;
    float score;
    char *name;
}stu3;  //此处有 ; 可以直接定义变量

typedef struct {
    int sex;
    int age;
    char *name;
}human; // 定义一个类型，

int main() {
    // typedef 是对结构体取了个名字，
    struct student student1;
    // student student2;    // 通过方式一声明的结构体不可以直接定义变量
    human human1;
    stu3.age=10;    // 通过方式一定义的变量，可以直接赋值


    return 0;
}