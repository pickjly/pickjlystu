#include <stdio.h>

struct stu1{     // 声明结构体
    char *name;  //姓名
    int num;  //学号
    int age;  //年龄
    char group;  //所在小组
    float score;  //成绩
} student1 = { "Tom", 12, 18, 'A', 136.5 };

// 或者
typedef struct{     // 声明结构体
    char *name;  //姓名
    int num;  //学号
    int age;  //年龄
    char group;  //所在小组
    float score;  //成绩
}stu2;
stu2 student2 = { "Li", 13, 16, 'B', 136.5 };

// 定义结构体指针
struct stu1 *pstu1 = &student1;
stu2 *pstu2 = &student2;

int main() {
    // # 获取结构体成员 #
    // 对定义的结构体变量，可以使用 .  来获取结构体成员
    // 对声明的结构体指针，可以使用 -> 来获取结构体变量
    printf(" student1 name is %s\n", student1.name);
    printf(" student1 name is %s\n", pstu1->name);      // 指针通过 -> 来获取成员
    printf(" student1 name is %s\n", (*pstu1).name);    // 也可以先取值，再通过 . 来获取成员
    return 0;
}