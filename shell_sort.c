#include "sort.h"

char* ALGORITHM_NAME = "Shell Sort";

int calculate_gap(int gap) {
	gap /= 2;

	if((gap > 1) && (gap % 2 == 0)) {
        gap += 1;
    }
    return gap;
}

unsigned long shell_sort(int* array, int length) {
	unsigned long comparisons = 0;

    for(int gap = length/2; gap >= 1; gap = calculate_gap(gap)) {
        for(int i = gap; i < length; ++i) {
            int temp = array[i];
            int j;
            for(j = i; (++comparisons) && (j >= gap) && (array[j-gap] > temp); j -= gap) {
                array[j] = array[j-gap];
            }
            array[j] = temp;
        }
    }
	return comparisons;
}

unsigned long sort(int* array, int length) {
    return shell_sort(array, length);
}