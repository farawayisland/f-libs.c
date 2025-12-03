// ~/.config/c-cpp/c/libraries/f-libs/src/fstat.c
#include "fstat.h"

/* Measures of central tendency */
// Median
/// Calculates the median of int triple
int median_triple_int(int num_1, int num_2, int num_3) {
  int median = max_pair_int(min_pair_int(num_1, num_2),
                            min_pair_int(max_pair_int(num_1, num_2), num_3));

  return median;
}

/// Calculates the median of size_t triple
size_t median_triple_size_t(size_t size_1, size_t size_2, size_t size_3) {
  size_t median =
      max_pair_size_t(min_pair_size_t(size_1, size_2),
                      min_pair_size_t(max_pair_size_t(size_1, size_2), size_3));

  return median;
}
