// ~/.config/c-cpp/c/libraries/f-libs/include/fio.h
#ifndef FIO_H_
#define FIO_H_

#include "fstr.h"
#include <stdio.h>

/* Text Processing */
// Store newline-trimmed input from stdin to string buffer
extern char *store_input(char *str, size_t count);

// Parse integer from string
extern int parse_int(int *dest, const char *src);
extern int parse_size_t(size_t *dest, const char *src);

// Print array of ints
extern void print_arr_int(int *arr, size_t len);

// Print newline-appended string to stderr
extern void println_err(const char *str);

#endif
