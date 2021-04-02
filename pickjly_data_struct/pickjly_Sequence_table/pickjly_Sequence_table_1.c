#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
typedef int datatype;

typedef struct {
    int _size;
    int _length;
    datatype *_array;
}_sq;

_sq initsq() {
    _sq sq;
    sq._array = (datatype *)malloc(SIZE * (sizeof(datatype)));
    if (!sq._array) {
        exit(-1);
    }
    sq._size = SIZE;
    sq._length = 0;
    return sq;
}

_sq AddElemsq(_sq sq, datatype elem) {
    if(sq._length >= sq._size) {
        return sq;
    } else {
        sq._array[sq._length ++ ] = elem;
    }
    return sq;
}

void Displqysq(_sq sq) {
    int i = 0;
    printf(" %s : ", __FUNCTION__);
    for (i = 0; i < sq._length; i ++) {
        printf(" %d, ", sq._array[i]);
    }
    printf("\n");
}

int Clearsq(_sq sq) {
    for (int i = 0; i < sq._length; i ++) {
        sq._array[i] = 0;
    }
    sq._length = 0;
    free(sq._array);
    return 1;
}

int main() {
    _sq sq = initsq();
    printf("sq.size is %d\n", sq._size);
    printf("sq.length is %d\n", sq._length);
    Displqysq(sq);
    sq = AddElemsq(sq, 5);
    sq = AddElemsq(sq, 4);
    sq = AddElemsq(sq, 3);
    sq = AddElemsq(sq, 2);
    sq = AddElemsq(sq, 1);
    sq = AddElemsq(sq, 0);
    Displqysq(sq);
    printf("sq.length is %d\n", sq._length);
    if (Clearsq(sq) == 1 ) {
        printf(" sq cleared \n");
    }
    return 1;
}