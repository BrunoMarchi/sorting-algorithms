#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "sort.h"

typedef enum {ASCENDING = 0, DESCENDING, RANDOM} order;

typedef struct {
    order order;
    unsigned long comparisons;
    double time;
} sortResult;

int readArguments(int argc, char *argv[], int* seed, int* length) {
    int opt;

    char* usageString = "Usage: %s [-s seed] [-l length]\n";

    if(argc <= 1) {
        fprintf(stdout, usageString, argv[0]);
        return -1;
    }

    while((opt = getopt(argc, argv, "s:l:")) != -1) {
        switch (opt) {
            case 's':
                if(optarg == NULL) {
                    fprintf(stdout, usageString, argv[0]);
                    return -1;
                }
                (*seed) = atoi(optarg);
                break;
            case 'l':
                if(optarg == NULL) {
                    fprintf(stdout, usageString, argv[0]);
                    return -1;
                }
                (*length) = atoi(optarg);
                break;
            default:
                fprintf(stdout, usageString, argv[0]);
                return -1;
        }
    }
    return 0;
}

void fill_array_random(int* array, int length, int seed) {
    srand(seed);

    for(int i = 0; i < length; ++i) {
        array[i] = rand()%1000;
    }
}

void fill_array_descending(int* array, int length) {
    for(int i = 0; i < length; ++i) {
        array[i] = length-1-i;
    }
}

void fill_array_ascending(int* array, int length) {
    for(int i = 0; i < length; ++i) {
        array[i] = i;
    }
}

int* fill_array(int* array, int length, int seed, order order) {

    switch(order) {
        case ASCENDING:
            fill_array_ascending(array, length);
            break;
        case DESCENDING:
            fill_array_descending(array, length);
            break;
        case RANDOM:
            fill_array_random(array, length, seed);
            break;
    }

    return array;
}

bool is_sorted(int* array, int length) {
    int previous = array[0];
    for(int i = 1; i < length; i++) {
        if(previous > array[i]) {
            return false;
        }
    }
    return true;
}

sortResult* _sort(int* array, int length, order order) {
    clock_t start, end;
    sortResult* result = (sortResult*) malloc(sizeof(sortResult));
    
    (*result).order = order;

    start = clock();
    (*result).comparisons = sort(array, length);
    end = clock();

    (*result).time = ((double)(end - start) / (CLOCKS_PER_SEC));

    return result;
}

int main(int argc, char* argv[]) {
    int seed, length;
    char* orderString[] = {"Ascending", "Descending", "Random"};

    sortResult* results[3];

    int ret = readArguments(argc, argv, &seed, &length);
    if(ret != 0) return ret;

    if(length <= 0) return -2;

    fprintf(stdout, "\nRunning - %s\nSeed: %d, Length: %d\n", ALGORITHM_NAME, seed, length);

    int* array = (int*) malloc(length * sizeof(int));
    if(array == NULL) {
        fprintf(stdout, "\nERROR: Array was not alocated\n");
        return -3;
    }
    
    for(int i = ASCENDING; i <= RANDOM; ++i) {
        array = fill_array(array, length, seed, i);
        results[i] = _sort(array, length, i);
        if(!is_sorted(array, length)) fprintf(stdout, "ERROR: Array is not sorted in %s\n", orderString[i]);
    }

    free(array);

    for(int i = ASCENDING; i <= RANDOM; ++i) {
        fprintf(stdout, "%-10s order: \tcomparisons: %lu\ttime: %lfs\n", orderString[results[i]->order], results[i]->comparisons, results[i]->time);
        free(results[i]);
    }

    return 0;
}