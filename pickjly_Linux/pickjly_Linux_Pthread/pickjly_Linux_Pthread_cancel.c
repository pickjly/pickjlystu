#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void print_err(char *s) {
    perror(s);
    exit(-1);
}

void *pthread_func1(void *arg) {
    
    // 创建一个取消点
    int cancelstate_flag = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    if (cancelstate_flag != 0) {
        printf(" 创建取消点失败！\n");
    }
    printf(" pthread create 1\n");
    sleep(4);

    printf(" enable thread cancel!\n");
    cancelstate_flag = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    printf(" this is a thread cancel point!\n");

    return (void *)1;
}

int main() {
    pthread_t pid1;
    int errnum = -1;
    void *rval1 = NULL;
    int cval, jval;

    errnum = pthread_create(&pid1, NULL, pthread_func1, NULL);
    if (errnum != 0) {
        print_err("函数创建失败！\n");
    }
    sleep(2);

    cval = pthread_cancel(pid1);
    if (cval != 0) {
        printf("取消线程失败！\n");
    }

    jval = pthread_join(pid1, &rval1);
    if (jval != 0) {
        printf(" no joined thread!\n");
    }
    printf(" thread pid1 return with value %d\n", (int *)rval1);
    return 0;
}