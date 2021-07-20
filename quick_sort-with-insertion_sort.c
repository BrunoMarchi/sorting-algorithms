#include "sort.h"

char* ALGORITHM_NAME = "Quick Sort with Insertion Sort";

const int INSERTION_BREAKPOINT = 10;

void insertion_sort(int* array, int start, int end, unsigned long* comparisons) {
	for(int i = start; i < end; ++i) {
		int key = array[i];
		int j = i;
		while((j > 0) && (++(*comparisons)) && (array[j-1] > key)) {
			array[j] = array[j-1];
			--j;
		}
		array[j] = key;
	}
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* array, int start, int end, unsigned long* comparisons) {
	int pivot = array[end];
	int i = start;
	for (int j = start; j < end; ++j) {
		++(*comparisons);
		if (array[j] < pivot) {
			swap(&array[i], &array[j]);
			++i;
		}
	}
	swap(&array[i], &array[end]);
	return i;
}

void quick_sort(int* array, int start, int end, unsigned long* comparisons) {
	if (end > start) {
		int pivot = partition(array, start, end, comparisons);
		if((pivot-1-start) < INSERTION_BREAKPOINT) {
			insertion_sort(array, start, pivot-1, comparisons);
        } else {
            quick_sort(array, start, pivot-1, comparisons);
        }
		if((end+1-pivot) < INSERTION_BREAKPOINT) {
			insertion_sort(array, pivot+1, end, comparisons);
		} else {
			quick_sort(array, pivot+1, end, comparisons);
		}
	}
}

unsigned long sort(int* array, int length) {
    unsigned long comparisons = 0;
    quick_sort(array, 0, length-1, &comparisons);
    return comparisons;
}