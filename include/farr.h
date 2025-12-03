// ~/.config/c-cpp/c/libraries/f-libs/include/farr.h
#ifndef FARR_H_
#define FARR_H_

#include "fmisc.h"

/* Array Sizes */
// Calculates size of array of elements of any type
/// Source: https://stackoverflow.com/a/19453814
#define IS_INDEXABLE(arg) (sizeof(arg[0]))
#define IS_ARRAY(arg)                                                          \
  (IS_INDEXABLE(arg) && (((void *)arg) == ((void *)&arg[0])))
#define ARRAY_SIZE(arr) (IS_ARRAY(arr) ? (sizeof(arr) / sizeof(arr[0])) : 0)

/* Sorting */
// Checks if array of ints is sorted in ascending order
extern bool is_sorted_asc_arr_int(int *arr, size_t len);

// Checks if array of ints is sorted in descending order
extern bool is_sorted_desc_arr_int(int *arr, size_t len);

// Sorts array of ints in ascending order
/// Bubble sort
extern void sort_asc_bubble_arr_int(int *arr, size_t len);

/// Quicksort
extern size_t partition_lomuto_arr_int(int *arr, size_t low, size_t high);
extern void sort_asc_quick_arr_int(int *arr, size_t len);
extern void sort_asc_quick_hoare_arr_int(int *arr, size_t len);
extern void sort_asc_quick_lomuto_arr_int(int *arr, size_t len);
extern void sort_asc_quick_lomuto_in_range_arr_int(int *arr, size_t low,
                                                   size_t high);

// Sorts array of ints in descending order
/// Bubble sort
extern void sort_desc_bubble_arr_int(int *arr, size_t len);

#endif
