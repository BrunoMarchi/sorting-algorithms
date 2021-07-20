# Sorting algorithms

## Compiling

### Make compile

Will compile any file that ends in sort.c, binaries will have ***.exec*** as an extension.
***sort.h*** is a dependency that defines a common interface that the sorting algorithms need to follow to compile with ***test.c***, which contains the main.

> ***test.c*** has some functions to help running the tests and parsing the input, and validating that the arrays are sorted.

### Make clean

Will delete all ***.exec*** files.

## Usage

Example usage

> bubble_sort.exec -s 10 -l 1000

This will print the number of comparisons and the time it took for the algorithm to run in 3 different scenarios:

- Array is already sorted
- Array is in reverse order
- Array is randomized

Flags usage

> - **-s** option is used to define the seed that will be used by the random number generator to populate the array
> - **-l** is used to define the array size and is expected to be greater than 0, otherwise the program will exit with -2 code.

## Included test script

***run_tests.sh*** is used to run all the algorithms with the same input so they be compared
