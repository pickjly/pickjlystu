#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

void print_err(char *s) {
    perror(s);
    exit(-1);
}

void *pthread_func1(void *arg) {
    
    sleep(5);   // 在睡眠时，接受到sigquit的信号，线程退出
    // pthread_kill(pthread_self(), SIGQUIT);
    printf(" I wonder if this sentence will be print!\n");
    pthread_exit( (void *)1);
}

int main() {
    pthread_t pid1;
    int errnum = -1, jval = -1;
    void *rval1;

    printf(" I am main thread\n");
    errnum = pthread_create(&pid1, NULL, pthread_func1, NULL);
    if (errnum != 0) {
        print_err(" 函数创建失败！\n");
    }

    // sleep(1);
    int s = pthread_kill(pid1, SIGQUIT);
    printf(" s is %d\n", s);

    printf(" I am main thread\n");
    return 0;
}