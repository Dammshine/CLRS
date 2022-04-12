## Direct-address tables ##


## Exercises ##
11.1-1
Since S is a dynamic set represended by hash table. Then we can scan through the array
MAX-ELEMENT(Array M) {
    Element max = negative infinity
    for (i = 0..m) {
        if M[i] not NIL 
            max = MAX(max, M[i])
    }
    return max;
}

This procedure takes O(m) times, directly proporation to the length of array. If we have a set of key, then we can ignore the element that is empty.


11.1-2 
If the element without satellite data, then the data structure only require to tell if the element exist in the data set. Then
INSERT(bit-vector v, index i) {
    assert 0 < i < m
    t = (left shift 1 by index i)
    v UNION t
}

DELETE(bit-vector v, index i) {
    assert 0 < i < m
    t = invert (left shift 1 by index i)
    v AND t
}

FIND(bit-vector v, index i) {
    assert 0 < i < m
    t = (left shift 1 by index i) 
    return (v AND t)
}


11.1-3
Store a double-linked list in the key-corresponding spot. 
INSERT at different spot always take O(1), Insert at same spot can insert element in front take O(1). 
SEARCH will return the first element in that linked list, user will have to do some search to find the specific one. O(1)
DELETE will replace itself with it's next pointer, and clear it's next element. If delete itself is the last element, use double link back and destroy it. O(1)
