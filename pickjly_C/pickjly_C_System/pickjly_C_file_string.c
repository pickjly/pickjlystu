#include <stdio.h>
#include <stdlib.h>
#define N 100

int main() {
    FILE *fp;
    char ch;
    char str[N+1];

    if( (fp=fopen("Demo.txt","rwb")) == NULL ) {
        printf("Fail to open file!\n");
        exit(0);  //退出程序（结束程序）
    } 
    while( fgets(str, N, fp) != NULL ) {    // 从文件读取一行
        printf("%s", str);
    }
    rewind(fp);
    // printf("Input a string:");
    // gets(strTemp);
    // strcat(str, "\n");
    // strcat(str, strTemp);
    // fputs(str, fp);
    putchar('\n');  //输出换行符

    //每次读取一个字节，直到读取完毕
    while( (ch=fgetc(fp)) != EOF ){
        putchar(ch);
    }
    putchar('\n');  //输出换行符

    if( (fp=fopen("Demo.txt","wb+")) == NULL ) {
        printf("Fail to open file!\n");
        exit(0);  //退出程序（结束程序）
    } 
    rewind(fp);
    printf("Input a string:\n");
    //每次从键盘读取一个字符并写入文件
    while ( (ch=getchar()) != '\n' ){
        fputc(ch,fp);
    }
    rewind(fp);
    fclose(fp);
    return 0;
}