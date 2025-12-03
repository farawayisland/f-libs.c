// ~/.config/c-cpp/c/libraries/f-libs/src/farr.c
#include "farr.h"

/* Sorting */
// Checks if array of ints is sorted in ascending order
bool is_sorted_asc_arr_int(int *arr, size_t len) {
  bool flag = true;

  for (size_t i = 1; i < len; i++) {
    if (arr[i - 1] > arr[i]) {
      flag = false;
      break;
    }
  }

  return flag;
}

// Checks if array of ints is sorted in descending order
bool is_sorted_desc_arr_int(int *arr, size_t len) {
  bool flag = true;

  for (size_t i = 1; i < len; i++) {
    if (arr[i - 1] < arr[i]) {
      flag = false;
      break;
    }
  }

  return flag;
}

// Sorts array of ints in ascending order
/// Bubble sort
void sort_asc_bubble_arr_int(int *arr, size_t len) {
  bool swap_occurs = false;

  for (size_t i = 0; i < len - 1; ++i) {
    for (size_t j = 0; j < len - i - 1; ++j) {
      swap_occurs = swap_if_bigger_int(&arr[j], &arr[j + 1]);
    }
  }

  if (!swap_occurs) {
    return;
  }
}

/// Quicksort
size_t partition_lomuto_arr_int(int *arr, size_t low, size_t high) {
  size_t index_pivot = low;
  int pivot = arr[high];

  for (size_t i = low; i < high; ++i) {
    if (arr[i] <= pivot) {
      swap_int(&arr[i], &arr[index_pivot++]);
    }
  }

  swap_int(&arr[index_pivot], &arr[high]);

  return index_pivot;
}

void sort_asc_quick_arr_int(int *arr, size_t len) {
  sort_asc_quick_hoare_arr_int(arr, len);
}

void sort_asc_quick_hoare_arr_int(int *arr, size_t len) {
  if (len < 2) {
    return;
  }

  const size_t mid = len / 2;
  const int pivot = arr[mid];

  size_t i = 0;
  size_t j = len - 1;
  for (; true; ++i, --j) {
    while (arr[i] < pivot) {
      ++i;
    }

    while (arr[j] > pivot) {
      --j;
    }

    if (i >= j) {
      break;
    }

    swap_int(&arr[i], &arr[j]);
  }

  sort_asc_quick_hoare_arr_int(arr, i);
  sort_asc_quick_hoare_arr_int(arr + i, len - i);
}

void sort_asc_quick_lomuto_arr_int(int *arr, size_t len) {
  if (len < 2) {
    return;
  }

  sort_asc_quick_lomuto_in_range_arr_int(arr, 0, len - 1);
}

void sort_asc_quick_lomuto_in_range_arr_int(int *arr, size_t low, size_t high) {
  if (low >= high) {
    return;
  }

  int index_pivot = partition_lomuto_arr_int(arr, low, high);
  sort_asc_quick_lomuto_in_range_arr_int(arr, low, index_pivot - 1);
  sort_asc_quick_lomuto_in_range_arr_int(arr, index_pivot + 1, high);
}

// Sorts array of ints in descending order
/// Bubble sort
void sort_desc_bubble_arr_int(int *arr, size_t len) {
  bool swap_occurs = false;

  for (size_t i = 0; i < len - 1; ++i) {
    for (size_t j = 0; j < len - i - 1; ++j) {
      swap_occurs = swap_if_smaller_int(&arr[j], &arr[j + 1]);
    }
  }

  if (!swap_occurs) {
    return;
  }
}
