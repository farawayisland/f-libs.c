// ~/.config/c-cpp/c/libraries/f-libs/include/fmisc.h
#ifndef FMISC_H_
#define FMISC_H_

#include "fcommon.h"

/* Value swapping */
// Swaps values of two variables of type `int`
extern void swap_int(int *int_ref_1, int *int_ref_2);

// Swaps values of two variables of type `int` if value pointed by first
// argument is bigger
extern bool swap_if_bigger_int(int *int_ref_1, int *int_ref_2);

// Swaps values of two variables of type `int` if value pointed by first
// argument is smaller
extern bool swap_if_smaller_int(int *int_ref_1, int *int_ref_2);

#endif
