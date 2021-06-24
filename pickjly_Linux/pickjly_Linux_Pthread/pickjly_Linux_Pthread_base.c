#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

/***
 * 线程的基本状态
 *      就绪
 *      运行
 *      阻塞
 *      终止
 * 
 * 
 *   创建 -> 就绪  <========>  运行 --> 结束
 *            <              /
 *             \            /
 *              \          /
 *               \        /
 *                \     <
 *                 阻塞
 * ***/

/***
 * 线程控制
 *  线程终止
 *      1 exit 比较危险，在主线程未退出时，程序终止
 *  线程连接
 * 
 *  线程取消
 * 
 *  线程信号
 *  
 *  清除操作
 * 
 * ***/

/***
 * 线程取消
 *  取消函数
 * 
 *  取消状态
 * 
 *  取消类型
 * 
 *  取消点
 *  
 * 
 * ***/

void print_err( char *s ) {
    perror(s);
    exit(-1);
}

void printID( char *s ) {

    pthread_t tid = pthread_self();
    pid_t     pid = getpid();

    printf(" %s: pid_t is %u, tid_t is %lu\n", s, pid, tid);
}

void *pthread_function(void *arg) {
    printID(arg);
    return (void *)1;
}

typedef struct Stu {
    int age;
    char name[20];
}stu;

void *print_stu(void *stu_in) {
    printf(" stu->name is %s, and age is %d\n", ((stu *)stu_in) -> name, ((stu *)stu_in) -> age);
    return (void *)2;
}

void *pthread_fun_exit(char *s) {
    if (strcmp(s, "1") == 0) {
        printf(" New thread return!\n");
        return ((void *)31);
    } else if (strcmp(s, "2") == 0) {
        printf(" New thread pthread_exit!\n");
        pthread_exit((void *)32);
    } else {
        printf(" New thread exit!\n");
        exit(3);
    }
}

int main(int argc, char **argv) {

    pthread_t ntid1;
    pthread_t ntid2;
    pthread_t ntid3;
    int errnum = -1;

    void *rval_1;
    void *rval_2;
    void *rval_3;

    // 创建线程实例
    errnum = pthread_create(&ntid1, NULL, pthread_function, "New thread");
    if ( errnum != 0 ) {
        print_err("线程创建错误！");
    }

    printID("main thread");
    // sleep(2);    // 等待线程结束，可以更换为pthread_join
    printf(" pthread ntid1 return val is %d\n", pthread_join(ntid1, &rval_1));
    printf(" rval_1 is %d\n", (int *)rval_1);

    stu stu1;
    stu1.age = 18;
    strcpy(stu1.name,  "pickjly");

    // 以结构体为单位，传递变量
    errnum = pthread_create(&ntid2, NULL, print_stu, (void *)(&stu1));
    if ( errnum != 0) {
        print_err("线程创建错误！");
    }
    // sleep(1);
    printf(" pthread ntid2 return val is %d\n", pthread_join(ntid2, &rval_2));
    printf(" rval_2 is %d\n", (int *)rval_2);

    errnum = pthread_create(&ntid3, NULL, pthread_fun_exit, (void *)argv[1]);
    if ( errnum != 0) {
        print_err("线程创建错误！");
    }
    printf(" pthread ntid3 return val is %d\n", pthread_join(ntid3, &rval_3));
    printf(" rval_3 is %d\n", (int *)rval_3);

    printf(" main thread!\n");  // 传入参数是3, 会导致整个进程的退出，这一句不会执行了

    return 0;
}
