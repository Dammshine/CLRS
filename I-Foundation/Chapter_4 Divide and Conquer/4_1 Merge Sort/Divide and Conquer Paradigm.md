## Paradigm ##






## 4-2 Parameter-passing costs ##
a. Binary Search, algorithm as follow

// Recursive description
Binary-search(int array[n], int target, int start, int end) {
    if (start > end) return NULL;

    int min = start;
    int max = end;
    int mid = (min + max) / 2;

    if (array[mid] == target) 
        return mid
    if (array[mid] >  target) {
        return Binary-search(array[n], target, mid + 1, end)
    }
    else {
        return Binary-search(array[n], target, mid, end - 1)
    }
}
1. If array passed by pointer, then the algorithm can be describe as
T(n) = 1 * T(n / 2) + 1
a = 1, b = 2, n^log2(1) = 1 and thus f(n) = n^log2(1), and T(n) = O(log(n)).
2. If array passed by copying, then the f(n) would become O(n)
T(n) = 1 * T(n / 2) + c * n
Algorithm become O(nlog(n)), because log(n) times of n element copy occur. 
3. If array passed by copying partial element, then
T(n) = 1 * T(n / 2) + n / 2,
same apply, still theta(n)