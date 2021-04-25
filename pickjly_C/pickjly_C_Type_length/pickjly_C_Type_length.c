#include <stdio.h>

int main() {
    printf(" size of int    length's %ld\n", sizeof(int));
    printf(" size of char   length's %ld\n", sizeof(char));
    printf(" size of long   length's %ld\n", sizeof(long));
    printf(" size of double length's %ld\n", sizeof(double));
    printf(" size of int *  length's %ld\n", sizeof(int *));
    printf(" size of char * length's %ld\n", sizeof(char *));
    printf(" size of double * length's %ld\n", sizeof(double *));
    printf(" size of long * length's %ld\n", sizeof(long *));
}

//  size of int    length's 4
//  size of char   length's 1
//  size of long   length's 8
//  size of double length's 8
//  size of int *  length's 8
//  size of char * length's 8
//  size of double * length's 8
//  size of long * length's 8