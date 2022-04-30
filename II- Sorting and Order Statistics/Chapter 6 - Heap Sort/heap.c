#include "heap.h"
#include <stdlib.h>
#include <stdbool.h>


#define DEFAULT_SIZE        512

bool validIndex(Heap h, int index);
void swap(Heap h, int a, int b);
void heapFloatDown(Heap h, int index);

struct heap {
    int *array;
    int curr;
    int maxSize;
    int (*cmp)(int, int);
};

// Return greater index among two
int greater(int a, int b) {
    return a > b ? a : b;
}

int greaterHeap(Heap h, int a, int b) {
    if (h->cmp(h->array[a], h->array[b]) > 0) return a;
    return b;
}


// Return smaller int among two
int smaller(int a, int b) {
    return a <= b ? a : b;
}




// Heap supported operation
// Supply argument will build MAX_HEAP or MIN_HEAP
Heap heapInitialize(int mode) {
    // Initialize the heap
    Heap newHeap = malloc(sizeof(*newHeap));
    newHeap->curr = 1;
    newHeap->maxSize = DEFAULT_SIZE;
    newHeap->array = calloc(DEFAULT_SIZE, sizeof(int));
    
    // set the mode
    if (mode == MAX_HEAP) {
        newHeap->cmp = greater;
    }
    else {
        newHeap->cmp = smaller;
    }
    return newHeap;
}

// Heapify an array to the heap
// Assume the heap is initialu empty
void heapify(Heap h, int *array, int size) {
    // Incremenet maxSize
    while (h->maxSize < size) {
        h->array = realloc(h->array, 2 * h->maxSize);
        h->maxSize *= 2;
    }

    // load element into heap
    for (int i = 0; i < size; i++) {
        h->array[i] = array[i];
    }
    h->curr = size;
    
    // Heapify all element from bottom to top that isn't leave node
    for (int i = size / 2; i >= 0; i--) {
        heapFloatDown(h, i);
    }
}

// retrive element, the max or min element from heap
int heapRetrive(Heap h) {
    return 0;
}

// insert an element to the heap
void heapInsert(Heap h, int i) {
    return;
}


// --------------------------------------------------
//              Devloper's function


bool validIndex(Heap h, int index) {
    if (index > 0 && index <= h->curr) {
        return true;
    }
    return false;
}

void swap(Heap h, int a, int b) {
    int temp = h->array[a];
    h->array[a] = h->array[b];
    h->array[a] = temp;
}


// Pre condition:  left, right child of index is heap
void heapFloatDown(Heap h, int index) {
    // Step 1 : Check if this index is a valid index
    if (index > (h->curr / 2)) return;
    
    // calculate left, right index
    int l = 2 * index;
    int r = 2 * index + 1;
    int newRoot = index;
    if (validIndex(h, l) == true) {
        newRoot = greaterHeap(h, l, index);
    }
    if (validIndex(h, r) == true) {
        newRoot = greaterHeap(h, r, index);
    }

    // cases
    // done
    if (newRoot == index) return;

    // swap and contine this process
    swap(h, index, newRoot);
    heapFloatDown(h, newRoot);
}


