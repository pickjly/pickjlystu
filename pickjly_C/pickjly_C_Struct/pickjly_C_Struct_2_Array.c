#include <stdio.h>

// 结构体数组，是指数组中的每个元素都是一个结构体
// struct stu{
//     char *name;  //姓名
//     int num;  //学号
//     int age;  //年龄
//     char group;  //所在小组 
//     float score;  //成绩
// }students[5];

struct stu{
    char *name;  //姓名
    int num;  //学号
    int age;  //年龄
    char group;  //所在小组 
    float score;  //成绩
}students[5] = {
// }students[] = {  // 当对数组中全部元素赋值时，也可不给出数组长度
    {"Li ping", 5, 18, 'C', 145.0},
    {"Zhang ping", 4, 19, 'A', 130.5},
    {"He fang", 1, 18, 'A', 148.5},
    {"Cheng ling", 2, 17, 'F', 139.0},
    {"Wang ming", 3, 17, 'B', 144.5}
};

int main()
{
    printf(" student 1 name is %s\n", students[1].name);
    return 0;
}