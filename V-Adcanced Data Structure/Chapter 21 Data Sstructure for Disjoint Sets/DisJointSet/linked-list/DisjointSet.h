#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdbool.h>

typedef struct set *Set;
typedef struct collection* Collection;


// Create a new set with only one member
Set makeSet(int x);


// Merge two set, u,v can be still used
void Union(Set a, Set b);


// Find set
// Return a pointer to a set
Collection findSet(Set a);


// Print out the element in this set in "%d, " format
void DisjointSetShow(Set x);


#endif