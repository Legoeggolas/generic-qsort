# generic-qsort
A generic implementation of quick sort in C.

It is declared as:
```c
void q_sort(void *arr,
            size_t num_elements, size_t size,
            int (*comp)(const void *, const void *),
            int (*pivot)(void *, int, int));
```
where the parameters are defined as
> **arr** 
- Pointer to the first element of the array to be sorted.
> **num**
- Number of elements to be sorted.
>**size**
- Size of an array element.
> **comp**
- Pointer to a function that compares two elements.
Takes two pointers as arguments (both converted to *const void**)
- Must return:
  - **-1** if the first element is larger than the second.
  - **0** if both elements are equal.
  - **1** if the first element is smaller than the second.
>**pivot**
- Pointer to a function that calculates the pivot to be used. Takes a pointer to the array, the starting index of the range being sorted, and the end (exclusive) as its arguments.
- Must return a valid index between the given range to be used as the pivot.


# Examples
Sorting an array of 10 integers in ascending order, using the middle element as the pivot:
```c
int compare(const void *a, const void *b) {
    int a_val = *(const int *)a;
    int b_val = *(const int *)b;
    return a_val - b_val;
}

int pivot(void *arr, int lo, int hi) {
    return lo + (hi - lo) / 2;
}

int main(void) {
    int arr[] = {10, 9, 8, 6, 5, 7, 4, 2, 1, 3};

    q_sort(arr, 10, sizeof(arr[0]), compare, pivot);

    for (int i = 0; i < 10; i++) {
        printf("%d ", *(arr + i));
    }

    return 0;
}
```
Output
```
1 2 3 4 5 6 7 8 9 10
```

<br>

Sorting an array of 10 strings in a descending order depending on their lengths, using the first element as the pivot:
```c
#include <stdio.h>

#include "qsort.h"

int compare(const void *a, const void *b) {
    char *const *a_str = a;
    char *const *b_str = b;

    int a_len = strlen(*a_str);
    int b_len = strlen(*b_str);

    return b_len - a_len;
}

int pivot(void *arr, int lo, int hi) {
    return lo;
}

int main(void) {
    char *arr[] = {"a", "ab", "abcde", "abc", "abcd", "abc", "abc", "abcdefg", "a", "ab"};

    q_sort(arr, 10, sizeof(char *), compare, pivot);

    for (int i = 0; i < 10; i++) {
        printf("%s ", *(arr + i));
    }

    return 0;
}
```

Output:
```
abcdefg abcde abcd abc abc abc ab ab a a
```
