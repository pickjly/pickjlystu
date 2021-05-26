/***
 * Author : pickjly
 * Email  : 2461789521@qq.com
 * Date   : 2021-05-11
 * Time   : 23:00
 * File   : @pickjly_Linux_Process_communication_test02.c
 * Content:
 *      进程间通信 -- 有名管道
 * ***/

/***
 * 
 * 1 进程空间
 *      程序运行的内存空间，但是os实现了虚拟内存空间到真实的物理空间，所以一般称为虚拟内存空间
 * 
 * ***/

/***
 * 1 信号
 * 
 * 2 管道   -- 实质是操作系统创建的缓存空间， 一个进程可以写数据，另一个进程从中读数据。不
 *      - 有名管道
 *          不相关的进程之间进行通信， 相当与创建一个文件，两个进程共同打开一个文件，进行操作。
 *      - 无名管道
 *          无名管道只能用于亲缘进程之间，因为创建的管道是无名管道，没有文件路径，更没有文件描述符，所以只能通过父进程创建管道之后，fork子进程，由子进程继承管道描述符。
 *          使用无名管道时，只能是单向的数据通信。
 * 
 * 3 消息队列
 * 
 * 4 共享内存
 * 
 * 5 信号量
 * 
 * 6 域套接字
 * 
 * 
 * 
 * 
 * ***/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define FIFONAME "./.fifo"

void print_err(char *s) {
    perror(s);
    exit(-1);
}

void signal_func(int signo) {
    remove(FIFONAME);
    exit(-1);
}

void test02() {

    int ret = -1;
    int fd = -1;
    char buffer[20] = {0};

    signal(SIGINT, signal_func);

    if ( (ret = mkfifo(FIFONAME, 0664)) == -1 && errno != EEXIST) {
        print_err("创建管道错误");
    }
    if ( (fd = open(FIFONAME, O_RDONLY)) == -1 ) {
        print_err("打开管道文件错误");
    }

    while(1) {
        bzero(buffer, sizeof(buffer));
        read(fd, buffer, sizeof(buffer));
        printf("%s", buffer);
    }
}

int main (void) {

    test02();

}