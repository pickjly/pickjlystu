#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/***
 * 交换排序
 * 
 *      冒泡排序
 *      快速排序
 * 
 * 插入排序
 * 
 *      简单插入排序
 *      希尔排序
 * 
 * 选择排序
 * 
 *      简单选择排序
 *      堆排序
 * 
 * 归并排序
 * 
 *      二路归并排序
 *      多路归并排序
 * 
 * ***/

// 打印数组
void print_array(int* array, int size) {
    for (int i = 0; i < size; i ++) {
        printf(" %d\t", array[i]);
    }
    printf("\n");
}

// 
void Insert_sort_real(int *array, int val_i) {
    if(val_i == 0) {
        return;
    }
    if (array[val_i - 1] < array[val_i]) {
        return;
    } else {
        int tmp = array[val_i];
        // printf(" array[%d] is %d\n", val_i, array[val_i]);
        // print_array(array, val_i);
        int tmp_id = 0;
        for( int i = 0; i < val_i; i ++) {
            if ( array[i] > tmp ) {
                tmp_id = i;
                break;
            }
        }
        for( int j = val_i - 1; j >= tmp_id; j -- ) {
            array[j+1] = array[j];
        }
        array[tmp_id] = tmp;
    }
}

// 交换排序 -- 冒泡排序 
void bubble_sort(int* array, int size) {
    if (size <= 0) {
        return;
    } else {
        int needswap = 0;
        for(int i = 0; i < size - 1; i ++) {
            if ( array[i] > array[i+1]) {
                int tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
                needswap = 1;
            }
        }
        if (needswap == 0) {
            return;
        }
        bubble_sort(array, --size);
    }
}

// 交换排序 -- 快速排序
void quick_sort(int *array, int size) {
    if (size <= 1) {
        return;
    }
    int low = 0, high = size - 1;
    int pivot = array[low];
    int tmp = 0;

    while(low < high) {
            while ( low < high && array[high] > pivot ) {
                    high --;
            }
            array[low] = array[high];
            while ( low < high && array[low] <= pivot) {
                    low ++;
            }
            array[high] = array[low];
    }
    array[low] = pivot;

    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    //         low
    quick_sort(array, low);
    quick_sort(&array[low + 1], size - low - 1);
}

// 选择排序 -- 简单选择排序
void select_sort(int*array, int size) {
    if (size <= 1) {
        return;
    } else {
        int arraymaxid = 0;
        int arrayminid = 0;
        for (int i = 0; i < size; i ++) {
            if ( array[i] > array[arraymaxid] ) {
                arraymaxid = i;
            }
            if ( array[i] < array[arraymaxid] ) {
                arrayminid = i;
            }
        }

        int tmpmax = array[arraymaxid];
        int tmpmin = array[arrayminid];
        array[arraymaxid] = array[size - 1];
        array[arrayminid] = array[0];
        array[size -1]    = tmpmax;
        array[0]          = tmpmin;

        select_sort(++ array, --size);
    }
}

// 插入排序 -- 简单插入排序
void Insert_sort(int *array, int size) {
    if (size <= 1) {
        return;
    } else {
        for (int i = 1; i < size; i ++) {
            Insert_sort_real(array, i);
            // print_array(array, size);
        }
        
    }
}

int main() {
    int array[10] = {488, 6452, 8163, 1138, 77, 161, 102, 87, 413, 515};
    int sizeof_array = sizeof(array)/sizeof(int);

    printf(" before sort:\t\t");
    print_array(array, sizeof_array);

    printf("\n after bubble sort: \t");
    bubble_sort(array, sizeof_array);
    print_array(array, sizeof_array);

    printf("\n after select sort: \t");
    select_sort(array, sizeof_array);
    print_array(array, sizeof_array);

    printf("\n after quick sort: \t");
    quick_sort(array, sizeof_array);
    print_array(array, sizeof_array);

    printf("\n after insert sort: \t");
    Insert_sort(array, sizeof_array);
    print_array(array, sizeof_array);

    return 0;
}