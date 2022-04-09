#include "DisjointSet.h"
#include <stdio.h>

void test0() {
    Set s = makeSet(1);
    Set y = makeSet(2);
    Set yy = makeSet(3);
    Union(s,y);
    Union(y, yy);
    DisjointSetShow(s);
    DisjointSetShow(y);
    if (findSet(s) == findSet(yy)) {
        printf("Belong to the same set\n");
    }
}

void test1() {
    Set arr[17];
    for (int i = 0; i < 17; i++) {
        arr[i] = makeSet(i);
    }
    for (int i = 0; i < 15; i = i + 2) {
        Union(arr[i], arr[i + 1]);
    }
    for (int i = 0; i < 13; i = i + 4) {
        Union(arr[i], arr[i + 2]);
    }
    Union(arr[1], arr[5]);
    Union(arr[11], arr[13]);
    Union(arr[1], arr[10]);
    DisjointSetShow(arr[2]);
    DisjointSetShow(arr[9]);
}

int main() {
    test1();
}