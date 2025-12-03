// ~/.config/c-cpp/c/libraries/f-libs/str/fstr.c
#include "fstr.h"

/* Text Processing */
// Trims newline from null-terminated byte string
char *trim_newline(char *str) {
  str[strcspn(str, "\n")] = '\0';

  return str;
}
