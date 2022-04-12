## Heap ##
The binary-heap structure is a complete binary-tree like array. By providing the index, one can find it's parent, left child, right child.

There are two kind of binary-heap, max-heap which is root greater than children, and vice versa for min-heap. 

We define height as same as BST. And heap have property
1. Add element, remove element from Heap. O(log(n)).
2. Build-heap, O(n)
3. Heap-sort, O(nlog(n))


## Exercise ##
6.1-1
For h >= 1. 
Minimum, 2^h
Maximum, 2^(h + 1) -1 


6.1-2
Consider above, suppose n-element lies between 2^h and 2^(h+1) - 1, then the height of n-element is h. Which is floor(log(n)).


6.1-3
Suppose an heap contains n element, and maintain max-heap property. By pick an arbitary index between 1 to n, say k.
If k == 1, then it's root, proof end.
If k != 1, then consider k is smaller then it's own root, which is floor(k/2). And repeat this process, we will have the element in array denote by index
        k <= floor(k/2) <= floor(floor(k/2)/2) ... <= 1.
Thus, the root of heap always contain the greatest number. 