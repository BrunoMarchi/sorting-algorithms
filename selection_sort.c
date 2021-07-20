#include "sort.h"

char* ALGORITHM_NAME = "Selection Sort";

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

unsigned long selection_sort(int* array, int length) {
	unsigned long comparisons = 0;
    
    for(int i = 0; i < length-1; ++i) {
        int min = i;
        for (int j = i+1; j < length; ++j) {
            ++comparisons;
            if(array[j] < array[min]) {
                min = j;
            }
        }
        if (i != min) {
            swap(&array[i], &array[min]);
        }
    }
	return comparisons;
}

unsigned long sort(int* array, int length) {
    return selection_sort(array, length);
}