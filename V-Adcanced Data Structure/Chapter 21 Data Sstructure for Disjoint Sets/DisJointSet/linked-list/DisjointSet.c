#include <stdio.h>
#include <stdlib.h>
#include "DisjointSet.h"



struct set {
    int val;
    Collection head;
    Set next;
};

struct collection {
    Set first;
    Set last;
    int size;
};


// Create a new set with only one member
Set makeSet(int x) {
    // Create Set
    Set newSet = malloc(sizeof(*newSet));
    newSet->val = x;
    newSet->next = NULL;

    // Make collection store head, tail of this new Set
    Collection coll = malloc(sizeof(*coll));
    coll->first = coll->last = newSet;
    coll->size = 1;

    // Connect two
    newSet->head = coll;
    return newSet;
}


// Merge two set, u,v can be still used
void Union(Set a, Set b) {
    // UNION being done
    if (a->head == b->head) return;

    // Compare the size, always choice merge smaller set to a bigger set
    int sizeA = a->head->size;
    int sizeB = b->head->size;


    Set appendedSet = NULL;
    Collection appendedColl = NULL;
    Collection destroyedColl = NULL;
    if (sizeA >= sizeB) {
        // Append Set b to Set a
        appendedSet = b->head->first;
        appendedColl = a->head;
        destroyedColl = b->head;
    }
    else {
        appendedSet = a->head->first;
        appendedColl = b->head;
        destroyedColl = a->head;
    }

    // Modify the size
    appendedColl->size += destroyedColl->size;

    // Change appendedSet's new head
    while (appendedSet != NULL) {
        appendedSet->head = appendedColl;
        appendedSet = appendedSet->next;
    }

    // Merge two list
    appendedColl->last->next = destroyedColl->first;
    appendedColl->last = destroyedColl->last;
    free(destroyedColl);
}


// Find set
// Return a pointer to a set
Collection findSet(Set a) {
    return a->head;
}


// Print out the element in this set in "%d, " format
void DisjointSetShow(Set x) {
    Set first = x->head->first;
    while (first != NULL) {
        printf("%d ", first->val);
        first = first->next;
    }
    printf("\n");
}

