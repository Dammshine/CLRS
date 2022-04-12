## Hash Table ##
The down-side of direct-address table is obvious, if the element's range is too big and element's size if too small. It's a waste of memory. And, there is no garuntee that we could store the range of element into an array(this also require a contiguous block). 

Thus, we may design a random(still determinstc) function, that able to map a eleent in big range M, to a smaller range N. 

## Hash Collision ##
Hash Collision occurs when hash function maps two distinct key to the same slot. 

### Hash COllision By Chaining ###
One way to overcom Hash Collision is to store a doubly linked list in the given slot derived by hashing.
And there is few operation we want to support
1. INSERT. Insert at front. O(1)
2. SEARCH. Asymptopically to the length of linked-list at given slot. O(n/m) or O(a).
3. DELETE. Given doubly linked list, O(1). 

For the worst case, all element chained up in one given slot, make search O(n) which is just a linked list.
We consider the average case, we assume that all elements are equally distributed in a given range, we call this assumption simple uniform hashing. Then, the length of each chain would  be n/m. 


#### Theorem 11.1 ####
In a hash table in which colluisons are resolved by chaining, an unsuccessful search takes average-case time big-Omega(1 + a), under the assumption of simple uniform hashing. 

Proof. The search step consist of two step,
1. Find corresponding spot for the key.
2. Search element in the linked list.
For finding corresponding spot, we assume it takes O(1) time. 
By assumption, we assume the array is equally distributed with each length of m/a. Then by perform searching, with no key in the linked-list, we have to scan all array in order to determine if the given key exist. This process will take O(n/m). Which is O(1 + n/m). 

If the search is successful, it will also takes O(1 + a), as it's index is proporational to the length.

#### Theorem 11.2 ####
In a hash table in which colluisons are resolved by chaining, an unsuccessful search takes average-case time big-Omega(1 + a), under the assumption of simple uniform hashing. 


11.2-1
Using pigeonhole theorem, for a given n element into array of m, we can expect following
1. For m >= n, then no collision will occur.
2. For n > m, then let each slot of m fills one element, which result n - m elements have no slot. And in this case, by add arbitary element into arbitary slot will cause collision, then results n - m collision in total. 


11.2-2
By perform mod 9, we have {5, 1, 1, 6, 2, 6, 3, 8, 1}
Then observe duplicate, it causes two collision. 


11.2-3
By make linked list in sorted order makes
1. INSERT. Insert in sorted order, hence proportion to the length of list. O(1 + a).
2. SEARCH. By search, one can perform binary search. O(1 + log(a)).
3. DELETE. Given doubly linked list, O(1). Since delete do not affect order. 

By professor Marley, it can reduce time for search, but increase complexity for insert. If the number a is relatively small, log(n) will not boost performance, neither the insert. So it won't affcect overall performance. For the a is really big cases, the chain implementation would not be ideal, as for Marley's case it decrease performance of insert substantially, and if not sorted case, the search will be affect substantially. Either choose a bigger m to lower a, or figure out another implementation would be ideal. 


