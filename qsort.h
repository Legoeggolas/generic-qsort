#ifndef Q_SORT_H
#define Q_SORT_H

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Sorts an array depending on the provided parameters.
 *
 * @param arr The pointer to the first element of the array to be sorted.
 * @param num_elements The number of elements to be sorted.
 * @param size The size of an array element.
 * @param comp The comparator function used to compare any two elements.
 * @param pivot The function used to calculate the pivot to be used.
 *        Accepts a pointer to the array to facilitate median-of-three optimizations.
 */
void q_sort(void *arr,
            size_t num_elements, size_t size,
            int (*comp)(const void *, const void *),
            int (*pivot)(void *, int, int));

#endif
