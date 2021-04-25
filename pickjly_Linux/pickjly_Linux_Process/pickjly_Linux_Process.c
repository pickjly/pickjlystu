#include <stdio.h>
#include <unistd.h>

int main() {

// 调用 fork 函数的进程被称为 父进程(parent process)，使用 fork 函数创建出来的进程被称为 子进程(child process)。

/* 区分父进程和子进程 */
/* 子进程只是父进程的拷贝，所以它们几乎所有的情况都一样，包括内存映像、变量、寄存器等。
区分的关键在于 fork 函数调用后的返回值，如果 fork 后返回一个非零值，这个非零值即是子进程的 进程标识符(Process Identiier, PID)，*/
    printf("process %d is parent process \n", getpid());
    pid_t pid = -1;
    if ( (pid = fork() )< 0 ) {
        printf("child process created failed");   // pid < 0,创建失败
        return(-1);
    }
    else if ( pid == 0 ) {
        printf("child process %d will continue this print\n", getpid());
    }
    else {
        sleep(1);
        printf("parent process %d will continue this print\n", getpid());
    }

    printf("process %d will continue this print out \n", getpid());
}

// process 2867 is parent process 
// child process 2868 will continue this print
// process 2868 will continue this print out 
// parent process 2867 will continue this print
// process 2867 will continue this print out 
