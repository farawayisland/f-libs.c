// ~/.config/c-cpp/c/libraries/f-libs/include/fmath.h
#ifndef FMATH_H_
#define FMATH_H_

#include "fmisc.h"
#include <math.h>
#include <stdlib.h>

/* Parity checking */
// Checks if int is even
extern bool is_even_int(int num);

// Checks if int is odd
extern bool is_odd_int(int num);

// Checks if size_t is even
extern bool is_even_size_t(size_t size);

// Checks if size_t is odd
extern bool is_odd_size_t(size_t size);

/* Sortedness checking */
// Checks if size_t triple is sorted in ascending order
extern bool is_sorted_asc_triple_size_t(size_t size_1, size_t size_2,
                                        size_t size_3);

// Checks if size_t triple is sorted in descending order
extern bool is_sorted_desc_triple_size_t(size_t size_1, size_t size_2,
                                         size_t size_3);

/* Extrema */
// Maxima
/// Calculates maximum of int pair
extern int max_pair_int(int num_1, int num_2);

/// Calculates maximum of size_t pair
extern size_t max_pair_size_t(size_t size_1, size_t size_2);

/// Calculates maximum of int triple
extern int max_triple_int(int num_1, int num_2, int num_3);

/// Calculates maximum of size_t triple
extern size_t max_triple_size_t(size_t size_1, size_t size_2, size_t size_3);

// Minima
/// Calculates minimum of int pair
extern int min_pair_int(int num_1, int num_2);

/// Calculates minimum of size_t pair
extern size_t min_pair_size_t(size_t size_1, size_t size_2);

/// Calculates minimum of int triple
extern int min_triple_int(int num_1, int num_2, int num_3);

/// Calculates minimum of size_t triple
extern size_t min_triple_size_t(size_t size_1, size_t size_2, size_t size_3);

#endif
