#include "sort.h"

char* ALGORITHM_NAME = "Insertion Sort";

unsigned long insertion_sort(int* array, int length) {
	unsigned long comparisons = 0;

	for(int i = 1; i < length; ++i) {
		int key = array[i];
		int j = i;
		while((j > 0) && (++comparisons) && (array[j-1] > key)) {
			array[j] = array[j-1];
			--j;
		}
		array[j] = key;
	}
	return comparisons;
}

unsigned long sort(int* array, int length) {
    return insertion_sort(array, length);
}