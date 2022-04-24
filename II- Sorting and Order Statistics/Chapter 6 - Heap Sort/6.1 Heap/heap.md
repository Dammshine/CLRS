## Heap ##
The binary-heap structure is a complete binary-tree like array. By providing the index, one can find it's parent, left child, right child.

There are two kind of binary-heap, max-heap which is root greater than children, and vice versa for min-heap. 

We define height as same as BST. And heap have property
1. Add element, remove element from Heap. O(log(n)).
2. Build-heap, O(n)
3. Heap-sort, O(nlog(n))

In an array, the parent, child of index which denoting the node as the index, can be calculated. 
1. Parent(i) = i / 2
2. left(i)   = 2 * i
3. right(i)  = 2 * i + 1


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

6.1-4
In max-heap, it have property that root always greater than the leave. So by interpreting heap as the binary tree, if a node that have leave, then it can not be lowest as it's leave always smaller or equal to such node. Hence the smallest element will reside on one of it's leave. 

6.1-5
Yes. Consider for any particular node n, in array. It have two child 2 * n and 2 * n + 1, which will always have a greater value since the array is sorted. Hence it will satisfy min-heap property. 

6.1-6
No. 7 is 6's right child, and it's greater than 6. Violate property. 

6.1-7
A node that is leave, is when it does not have any children. Then, we can define a number k,
if 2 * k <= n, then k is not a leave node as it at least have left children.
if 2 * k >  n, then k is a leave node, as it don't have any children. 

We can observe another property, suppose k is a leave, then any index greater than k is also leave node. Then, once we find the minimum num of k, we can then find rest index of leave node given as [k..n]. We let it be m.

m = { min(k), for 2 * k > n }
  = { if n is odd , then k = ceiling(n / 2) = floor(n / 2) + 1.
      if n is even, then k = floor(n / 2) + 1. }
      
Hence we can conclude, the leave node in an n-element arrayt are the node index by,  floor(n / 2) + 1 ..n. 

