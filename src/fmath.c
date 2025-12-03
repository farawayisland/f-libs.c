// ~/.config/c-cpp/c/libraries/f-libs/src/fmath.c
#include "fmath.h"

/* Parity checking */
// Checks if int is even
bool is_even_int(int num) { return ((num & 1) == 0); }

// Checks if int is odd
bool is_odd_int(int num) { return !is_even_int(num); }

// Checks if size_t is even
bool is_even_size_t(size_t size) { return ((size & 1) == 0); }

// Checks if size_t is odd
bool is_odd_size_t(size_t size) { return !is_even_size_t(size); }

/* Sortedness checking */
// Checks if size_t triple is sorted in ascending order
bool is_sorted_asc_triple_size_t(size_t size_1, size_t size_2, size_t size_3) {
  return (size_1 <= size_2) && (size_2 <= size_3);
}

// Checks if size_t triple is sorted in descending order
bool is_sorted_desc_triple_size_t(size_t size_1, size_t size_2, size_t size_3) {
  return (size_1 >= size_2) && (size_2 >= size_3);
}

/* Extrema */
// Maxima
/// Calculates maximum of int pair
int max_pair_int(int num_1, int num_2) {
  return (num_1 >= num_2) ? num_1 : num_2;
}

/// Calculates maximum of size_t pair
size_t max_pair_size_t(size_t size_1, size_t size_2) {
  return (size_1 >= size_2) ? size_1 : size_2;
}

/// Calculates maximum of int triple
int max_triple_int(int num_1, int num_2, int num_3) {
  return max_pair_int(max_pair_int(num_1, num_2), num_3);
}

/// Calculates maximum of size_t triple
size_t max_triple_size_t(size_t size_1, size_t size_2, size_t size_3) {
  return max_pair_size_t(max_pair_size_t(size_1, size_2), size_3);
}

// Minima
/// Calculates minimum of int pair
int min_pair_int(int num_1, int num_2) {
  return (num_1 <= num_2) ? num_1 : num_2;
}

/// Calculates minimum of size_t pair
size_t min_pair_size_t(size_t size_1, size_t size_2) {
  return (size_1 <= size_2) ? size_1 : size_2;
}

/// Calculates minimum of int triple
int min_triple_int(int num_1, int num_2, int num_3) {
  return min_pair_int(min_pair_int(num_1, num_2), num_3);
}

/// Calculates minimum of size_t triple
size_t min_triple_size_t(size_t size_1, size_t size_2, size_t size_3) {
  return min_pair_size_t(min_pair_size_t(size_1, size_2), size_3);
}
