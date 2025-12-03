// ~/.config/c-cpp/c/libraries/f-libs/src/fmisc.c
#include "fmisc.h"

/* Value swapping */
// Swaps values of two variables of type `int`
void swap_int(int *int_ref_1, int *int_ref_2) {
  int temp = *int_ref_1;
  *int_ref_1 = *int_ref_2;
  *int_ref_2 = temp;
}

// Swaps values of two variables of type `int` if value pointed by first
// argument is bigger
bool swap_if_bigger_int(int *int_ref_1, int *int_ref_2) {
  bool swap_occurs = false;

  if (*int_ref_1 > *int_ref_2) {
    swap_int(int_ref_1, int_ref_2);
    swap_occurs = true;
  }

  return swap_occurs;
}

// Swaps values of two variables of type `int` if value pointed by first
// argument is smaller
bool swap_if_smaller_int(int *int_ref_1, int *int_ref_2) {
  bool swap_occurs = false;

  if (*int_ref_1 < *int_ref_2) {
    swap_int(int_ref_1, int_ref_2);
    swap_occurs = true;
  }

  return swap_occurs;
}
