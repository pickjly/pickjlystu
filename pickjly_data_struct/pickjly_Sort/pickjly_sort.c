#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void print_array(int* array, int size) {
    for (int i = 0; i < size; i ++) {
        printf(" %d\t", array[i]);
    }
    printf("\n");
}

int bubble_sort(int* array, int size) {
    if (size <= 0) {
        return -1;
    } else {
        for(int i = 0; i < size; i ++) {
            if ( array[i] > array[i+1]) {
                int tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
            }
        }
        size --;
        bubble_sort(array, size);
    }
}

int select_sort(int*array, int size) {
    if (size <= 0) {
        return -1;
    } else {
        int arrayid = 0;
        for (int i = 0; i < size; i ++) {
            if ( array[i] > array[arrayid] ) {
                arrayid = i;
            }
        }
        int tmp = array[arrayid];
        array[arrayid] = array[size - 1];
        array[size -1] = tmp;

        size --;
        select_sort(array, size);
    }
}

void quick_swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int *array, int size) {
    if (size <= 1) {return;}
    int low = 0, high = size - 1;
    int pivot = array[0];
    int tmp;
    while ( low < high ) {
        while ( low < high && array[high] > pivot ) {
            high --;
        }
        array[low] = array[high];

        while ( low < high && array[low] <= pivot ) {
            low ++;
        }
        array[high] = array[low];
    }

    // 0    1   2   3   4   5   6   7   8   9
    //             low
    array[low] = pivot;

    printf(" low is %d\n", low);
    print_array(array, size);
    quick_sort(array, low);
    quick_sort(&array[low + 1], size - low - 1);
}


int main() {
    int array[10] = {488, 6452, 8163, 1138, 77, 161, 102, 87, 413, 515};
    int sizeof_array = sizeof(array)/sizeof(int);

    print_array(array, sizeof_array);
    // bubble_sort(array, sizeof_array);
    // select_sort(array, sizeof_array);
    quick_sort(array, sizeof_array);
    print_array(array, sizeof_array);
    return 0;
}