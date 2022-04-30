#ifndef HEAP_H
#define HEAP_H

#define MAX_HEAP    1
#define MIN_HEAP    0
typedef struct heap *Heap;

// Heap supported operation
// Supply argument will build MAX_HEAP or MIN_HEAP
Heap heapInitialize(int mode);

// Heapify an array to the heap
void heapify(Heap h, int *array, int size);

// retrive element, the max or min element from heap
int heapRetrive(Heap h);

// insert an element to the heap
void heapInsert(Heap h, int i);


#endif