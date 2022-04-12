## A weighted-union heuristic ##
Theorem 21.1
By using the linked-list representation of disjoint sets and the weighted-union heuristic, a sequence of m MAKE-SET, UNION and FIND-SET operation, n of which are MAKE-SET operations, takes O(m + n*lgn) time. 

Consider correspond to n MAKE-SET operation, there is at most n - 1 UNION operation. Thus the UNION part have complexity of form (n-1)*O(UNION). 
Then, we determine the complexity of UNION operation, UNION operation consist of 
1. Update the size of one UNION, destroy the other O(1).
2. And update the new Collection pointer. Will be O(sizeof(min(U, V))).
Then, we consider for a set x, prior any UNION operation, x will be size 1. For each time, x update the resulting set would be 2 * size(x). That is, for a k element Set, the each individual set x, would update at most log(n) times. And since t. And there is total n sets start with, and each set will updated at most log(n) time, thus the complexity on UNION would be O(n*log(n)). 

And there is m other operation, all have O(1). Then the total complexity would be O(m + n*lgn). 


## Exercise ##
21.2-1 (Complete by using C)

21.2-2 (Tested by using C)

Two set are the same
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15


