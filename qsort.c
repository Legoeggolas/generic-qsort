#include "qsort.h"

// swaps two indices inside the array
void _swap(void *arr, int index_first, int index_second, size_t size) {
    void *temp = malloc(size);
    assert(temp);

    void *a = (char *)arr + index_first * size;
    void *b = (char *)arr + index_second * size;

    memcpy(temp, a, size);
    mempcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

// the partitioning co-routine
// uses pivot() function to decide the pivot's index
// then swaps the pivot element into a position where all elements to the right are strictly greater
// uses comp() to decide ordering
int _partition(void *arr, int lo, int hi, size_t size, int (*comp)(const void *, const void *), int (*pivot)(void *, int, int)) {
    int pvt = pivot(arr, lo, hi);

    assert(pvt >= lo && pvt < hi);

    // put the pivot element at the end of the array
    _swap(arr, pvt, hi - 1, size);

    int index = lo - 1;  // stores the pos after which all elements are larger than our pivot

    for (int seeker = lo; seeker < hi - 1; seeker++) {
        if (comp((void *)((char *)arr + seeker * size), (void *)((char *)arr + (hi - 1) * size)) <= 0) {
            _swap(arr, index + 1, seeker, size);
            index++;
        }
    }
    // place the pivot in its proper position
    _swap(arr, index + 1, hi - 1, size);

    return index + 1;
}

// stack space optimized implementation of quick sort
// takes log(n) auxiliary space on the stack
void _sort(void *arr, int lo, int hi, size_t size, int (*comp)(const void *, const void *), int (*pivot)(void *, int, int)) {
    while (lo < hi) {
        int pvt = _partition(arr, lo, hi, size, comp, pivot);

        // make a recursive call for the smaller subarray
        if (pvt - lo < hi - pvt) {
            _sort(arr, lo, pvt, size, comp, pivot);
            lo = pvt + 1;
        } else {
            _sort(arr, pvt + 1, hi, size, comp, pivot);
            hi = pvt;
        }
    }
}

void q_sort(void *arr, size_t num_elements, size_t size, int (*comp)(const void *, const void *), int (*pivot)(void *, int, int)) {
    if (num_elements <= 1) {
        return;
    }

    _sort(arr, 0, num_elements, size, comp, pivot);
}
