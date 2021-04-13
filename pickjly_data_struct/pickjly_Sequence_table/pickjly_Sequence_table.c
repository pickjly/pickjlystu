#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef int datatype;

typedef struct {
    int _length;
    int _size;
    datatype *_array;
}_sq;

int init(_sq *sq) {
    sq->_array = (datatype *)malloc( SIZE * (sizeof(datatype)));
    if (!sq->_array) {
        printf(" %s : error init sq\n", __FUNCTION__);
        return -1;
    }
    sq -> _length = 0;
    sq -> _size   = SIZE;
    return 1;
}

void printSq(_sq *sq) {
    printf(" sq : ");
    for (int i = 0; i < sq->_length; i ++) {
        printf(" %d, ", sq->_array[i]);
    }
    printf("\n");
}

int AddElementSq(_sq *sq, datatype elem) {
    if (sq->_length >= sq->_size) {
        printf(" Not enough memory \n");
        return -1;
    } else {
        sq->_array[sq->_length ++] = elem;
    }
    return 1;
}

int InsertElemsq(_sq *sq, datatype elem, int position) {
    if (sq->_length >= sq->_size) {
        printf(" %s : this sequence is full \n", __FUNCTION__);
        return -1;
    }
    if (position < 0 || position > sq->_size) {
        printf(" %s : Invalid position \n", __FUNCTION__);
        return -1;
    }
    for (int i = sq->_length; i >= position; i --) {
        sq->_array[i] = sq->_array[i - 1];
    }
    sq->_array[position] = elem;
    sq->_length ++;
    return 1;
}

int DeleteElemsq(_sq *sq, datatype elem, int position) {
    if (sq->_length < 0) {
        printf(" %s : this sequence is NULL \n", __FUNCTION__);
        return -1;
    }
    if (position < 0 || position > sq->_length) {
        printf(" %s : Invalid position \n", __FUNCTION__);
        return -1;
    }
    for ( int i = position; i < sq->_length; i ++) {
        sq->_array[i] = sq->_array[i + 1];
    }
    sq->_length --;
    return 1;
}

int FindElemSq(_sq *sq, datatype elem) {
    if (sq->_length < 0) {
        printf(" %s : Sequence is NULL \n", __FUNCTION__);
        return -1;
    } else {
        for (int i = 0; i < sq->_length; i ++) {
            if (sq->_array[i] == elem ) {
                return i;
            }
        }
    }
}

int Clearsq(_sq *sq) {
    for (int i = 0; i < sq->_length; i ++) {
        sq->_array[i] = 0;
    }
    sq->_length = 0;
    free(sq->_array);
    return 1;
}

int ChangeElemSq(_sq *sq, datatype elem, int position) {
    if (position > sq->_length) {
        printf(" %s : Here is NULL\n", __FUNCTION__);
        return -1;
    }
    sq->_array[position] = elem;
    return 1;
}

int main() {
    _sq sq;
    init(&sq);
    printSq(&sq);
    AddElementSq(&sq, 2);
    AddElementSq(&sq, 3);
    AddElementSq(&sq, 4);
    AddElementSq(&sq, 5);
    AddElementSq(&sq, 6);
    AddElementSq(&sq, 7);
    printSq(&sq);
    ChangeElemSq(&sq, 9, 3);
    printSq(&sq);
    InsertElemsq(&sq, 1, 1);
    printSq(&sq);
    DeleteElemsq(&sq, 1, 1);
    printSq(&sq);
    printf(" find Elem 3 is %d\n", FindElemSq(&sq, 9));
    if (Clearsq(&sq) == 1 ) {
        printf(" sq cleared \n");
    }
    return 0;
}