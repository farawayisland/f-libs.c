// ~/.config/c-cpp/c/libraries/f-libs/src/fio.c
#include "fio.h"

/* Text Processing */
// Store newline-trimmed input from stdin to string buffer
char *store_input(char *str, size_t count) {
  const char err[] = "ERROR: `fgets()` returned NULL.";

  if (count > 0) {
    if (!fgets(str, count, stdin)) {

      println_err(err);
      str = NULL;

    } else {

      trim_newline(str);
    }
  }

  return str;
}

// Parse integer from string
int parse_int(int *dest, const char *src) {
  int num_args_read = sscanf(src, "%d", dest);

  if (num_args_read != 1) {
    num_args_read = ERROR_INVALID_INPUT;
  }

  return num_args_read;
}

int parse_size_t(size_t *dest, const char *src) {
  int temp = 0;
  int num_args_read = sscanf(src, "%d", &temp);

  if (num_args_read != 1 && temp < 0) {
    num_args_read = ERROR_INVALID_INPUT;
  } else {
    *dest = temp;
  }

  return num_args_read;
}

// Print array of ints
void print_arr_int(int *arr, size_t len) {
  for (size_t i = 0; i < len; i++) {

    const bool is_index_start = i == 0;
    const bool is_index_end = i == len - 1;
    const char *format =
        !is_index_end ? (is_index_start ? "{%d, " : "%d, ") : "%d}";

    printf(format, arr[i]);
  }
}

// Print newline-appended string to stderr
void println_err(const char *str) { fprintf(stderr, "%s\n", str); }
