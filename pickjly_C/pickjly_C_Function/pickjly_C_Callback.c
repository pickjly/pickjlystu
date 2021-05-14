/***
 * Author : pickjly
 * Email  : 2461789521@qq.com
 * Date   : 2021-05-11
 * Time   : 23:00
 * File   : @pickjly_C_Callback.c
 * Content:
 *      回调函数
 * ***/

#include <stdio.h>

int (*pfunc)(int data); // 直接声明函数指针
typedef int (*pfunc1)(int data);    // 声明一种函数类型
typedef struct gfun{    // 结构提函数指针
	int (*pfun)(int);	
}gfun;

int myfunction(int data) {
    printf(" %s : get data is %d\n", __FUNCTION__, data);
    return 0;
}

int rt_data(int data,int (*tr_fun)())
{
	return ((*tr_fun)(data));
} 

int main() {
    pfunc=myfunction;
    (*pfunc)(10);

    pfunc1 pfunc2 = myfunction;
    pfunc2(100);

    gfun gfunc = {
        .pfun = myfunction
    };
    gfunc.pfun(5);

    int ret = rt_data(100,gfunc.pfun);
	printf("return data:%d\n",ret);

    return 1;
}