#include <stdlib.h>
#include "sort.h"

char* ALGORITHM_NAME = "Merge Sort";

void merge(int* array, int min, int mid, int max, unsigned long* comparions) {

    int i = min, j = mid+1, k = 0;

    int* auxArray = (int*)malloc(sizeof(int)*(max+1));
    
    if(auxArray == NULL) return;

    while ((i <= mid) && (j <= max)) {
		++(*comparions);
        if(array[i] < array[j]) {
            auxArray[k] = array[i];
            ++i;
        } else {
            auxArray[k] = array[j];
            ++j;
        }
        ++k;
    }

    while(i <= mid) {
        auxArray[k] = array[i];
        ++k;
        ++i;
    }

    while(j <= max) {
        auxArray[k] = array[j];
        ++k;
		++j;
    }

    for(k = (k-1); k >= 0; --k) {
        array[min+k] = auxArray[k];
    }
	free(auxArray);
}

void merge_sort(int* array, int min, int max, unsigned long* comparisons) {
	if(min < max) {
        int mid = (max+min)/2;
        merge_sort(array, min, mid, comparisons);
        merge_sort(array, mid+1, max, comparisons);
        merge(array, min, mid, max, comparisons);
    }
}

unsigned long sort(int* array, int length) {
    unsigned long comparisons = 0;
    merge_sort(array, 0, length-1, &comparisons);
    return comparisons;
}