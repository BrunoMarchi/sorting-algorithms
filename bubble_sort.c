#include "sort.h"

char* ALGORITHM_NAME = "Bubble Sort";

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

unsigned long bubble_sort(int* array, int length) {
	unsigned long comparisons = 0;

    int swapped = 1;

    for(int i = 0; i < length && swapped; ++i) {
        swapped = 0;
        for(int j = i+1; j < length; ++j) {
            ++comparisons;
			if(array[i] > array[j]) {
                swap(&array[i], &array[j]);
                swapped = 1;
            }
        }
    }

	return comparisons;
}

unsigned long sort(int* array, int length) {
    return bubble_sort(array, length);
}