## Heap ##
The binary-heap structure is a complete binary-tree like array. By providing the index, one can find it's parent, left child, right child.

There are two kind of binary-heap, max-heap which is root greater than children, and vice versa for min-heap. 

We define height as same as BST. And heap have property
1. Add element, remove element from Heap. O(log(n)).
2. Build-heap, O(n)
3. Heap-sort , O(nlog(n))

In an array, the parent, child of index which denoting the node as the index, can be calculated. 
1. Parent(i) = i / 2
2. left(i)   = 2 * i
3. right(i)  = 2 * i + 1


## Maintain the heap property ##
Assume, the an array A satifsy heap property, with one index i added to the array. The left and right satisfy heap property, while index i do not. Then, heap will let this value float down

Heapify(A, i) 
l = left(i)
r = right(i)
choose largest among l, r and i. 
If largest != i, exchange the value of i and largest
    Heapify(A, largest)

The worst case is when the bottom level of tree is half full, in this case the running time will be T(n） = T（3/4 * n） + 1. 


## Building a heap ##
Prior heapify, we have an array. We can use heapify apply to every index that have child, and build up the heap. The sequence of visiting is from bottom and build up, as one can oberserve, the pre-condition fo MAX_HEAPIFY is it's two children are already heap. By apply MAX-HEAPIFY from bottom, we can make sure this property will hold.

BUILD_MAX_HEAP(A)
for (i = A.size() / 2 .. 1)
    MAX_HEAPIFY(A, i)

Now, we shall start to analysis the correctness.

1. Initialization. Prior the for loop, we can view the leave node in original array already being heapify as these nodes don't have children, which makes it valid. Then we would have floor(A.size() / 2) + 1 .. A.size(), are already heap. 
2. Maintenance. We can assume that before every MAX_HEAPIFY(A, i) executed, the index i + 1.. A.size() have already heapfiied. This will hold prior first iteration.  And then, the MAX-HEAPIFY(A, i) will make the array heapify from i .. A.size(). 
3. Termination. After last iteration, which would be i = 1. We will have 1 .. A.size() being heapify. Thus, we conclude the heap being build.

After analysis of correctness, we shall discuss the time complexity of BUILD_MAX_HEAP(A). 

Firstly, we can note that MAX_HEAPIFY(A, i) have timeplexity of at most O(log(n)), and it being called for abs(A.size() / 2 .. 1) times, which is O(n) times. And it's upper-bound would be O(n * log(n)). 
$\lfloor f \rfloor$

Then, by oberving the time complexity of MAX_HEAPIFY(A, i) correlates to it's position i (height of this position), we can further derive a tighter upperbound. By visualting a complete BST, one simple property we can ultilize is that there is at most floor(n / 2 ^ h) nodes, in a given height. And, the running time of MAX_HEAPIFY(A, i) will be h. 
Then, the running time would be sum of h [ max_height .. 1( h * (n / 2 ^ h)) ]
                                         = n * sum of h (h / 2 ^ h )          (n is constant here )
                                         = 2 * n                              (By sum of sequence)

So that we have O(n). 