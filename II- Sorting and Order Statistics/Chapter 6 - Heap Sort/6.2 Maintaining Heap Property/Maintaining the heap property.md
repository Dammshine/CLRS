## Maintain the heap property ##
Assume, the an array A satifsy heap property, with one index i added to the array. The left and right satisfy heap property, while index i do not. Then, heap will let this value float down

Heapify(A, i) 
l = left(i)
r = right(i)
choose largest among l, r and i. 
If largest != i, exchange the value of i and largest
    Heapify(A, largest)

The worst case is when the bottom level of tree is half full, in this case the running time will be T(n） = T（3/4 * n） + 1. 

### Exercise ###
6.2-1
             |
A = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 7, 9, 0}
                         |
A = {27, 17, 10, 16, 13, 3, 1, 5, 7, 12, 4, 7, 9, 0}
                                               |
A = {27, 17, 10, 16, 13, 9, 1, 5, 7, 12, 4, 7, 3, 0}


6.2-2
MIN_HEAPIFY(A, i) {
    l = left(A, i)
    r = right(A, i)

    min = min_value(A[i], A[l], A[r])
    
    // Done
    if (min == i) return
    
    // Replace i to it's min child
    swap(A, i, min)
    MIN_HEAPIFY(A, min)
}


6.2-3
Then it's done. 


6.2-4
Then, it will have no children. Then it's done. 


6.2-5
bool valid_pos(A, i) {
    // For edge cases
    if (i == A.size() / 2) {
        if (min_value(A[i], A[left(i)]) == i) {
            return true;
        }
    }
    if (i > A.size() / 2) {
        return true;
    }

    if (min_value(A[i], A[left(i)], A[right(i)]) == i) {
        return true;
    }
    return false;
}

6.2-5
MAX_HEPFIFY(A, i) {
    int inspectIndex = i
    while (valid_pos(A, inspectIndex) == false) {
        l = left(A, inspectIndex)
        r = right(A, inspectIndex)
        min = min_value(A[l], A[r])
        swap(A, min, i)
        inspectIndex = min
    }
}


6.2-6
Prior each recursion, it calculte left, right child and compare. Which will take O(1). 
Then, for each recursion, it will each time inspect a index double than original index. Which by solve 2 ^ k = n, k = log(n), we get times of recursion. Hence the worst case would be O(log(n)).