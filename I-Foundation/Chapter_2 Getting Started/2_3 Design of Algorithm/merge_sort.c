#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void mergesort_helper(int *array, int start, int end) {
    // Base case - Only one element contained
    if (start == end) {
        return;
    }
    // Recursive case - Divide
    // Divide array into two equal(off by 1) part
    int middle = (start + end) / 2;
    mergesort_helper(array, start, middle);
    mergesort_helper(array, middle + 1, end);
    // Base case - Combine
    // Two array 
    //      A[start..middle] and A[middle+1..end] sorted
    // Step 1: Create two array store element of each subset of array
    int *array1 = malloc(sizeof(int) * (middle - start + 2));
    for (int counter = 0; counter < middle - start + 1; counter++) {
        array1[counter] = array[start + counter];
    }
    array1[middle - start + 1] = INT_MAX;
    int *array2 = malloc(sizeof(int) * (end - middle + 1));
    for (int counter = 0; counter < end - middle; counter++) {
        array2[counter] = array[middle + counter + 1];
    }
    array2[end - middle] = INT_MAX;

    // Step 2: combine two array
    int array1_index = 0;
    int array2_index = 0;
    for (int counter = 0; counter < end - start + 1; counter++) {
        if (array1[array1_index] <= array2[array2_index]) {
            array[start + counter] = array1[array1_index];
            array1_index++;
        }
        else {
            array[start + counter] = array2[array2_index];
            array2_index++;
        }
    }
    free(array1);
    free(array2);
}

int *mergesort(int *array, int size) {
    mergesort_helper(array, 0, size - 1);
    return array;
}