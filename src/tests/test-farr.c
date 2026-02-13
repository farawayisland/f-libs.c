// ~/.config/c-cpp/c/libraries/f-libs/src/tests/test-farr.c
#include "fio.h"
#include <stdlib.h>

int main(int argc, char **argv) {
  int exit_code = SUCCESS;

  const size_t len = argc - 1;
  int arr[len];

  for (size_t i = 0; i < len; ++i) {

    parse_int(&arr[i], argv[i + 1]);
  }

  const char sorted[] = "sortedness";
  const size_t len_sorted = strlen(sorted);
  char *arr_str = "array";
  int padding = strlen("array_sorted") - strlen(arr_str);
  padding = abs(padding);

  printf("%s%*s: arr[%zu] = ", arr_str, padding, "", len);
  print_arr_int(arr, len);
  printf(".\n");

  padding = strlen("array_sorted") - len_sorted;
  padding = abs(padding);
  printf("%s%*s: is_sorted_asc_arr_int(arr, %zu) = %s.\n", sorted, padding, "",
         len, is_sorted_asc_arr_int(arr, len) ? "true" : "false");

  printf("%s%*s: is_sorted_desc_arr_int(arr, %zu) = %s.\n", sorted, padding, "",
         len, is_sorted_desc_arr_int(arr, len) ? "true" : "false");
  putchar('\n');

  arr_str = "array_sorted";
  padding = strlen("array_sorted") - strlen(arr_str);
  padding = abs(padding);
  printf("%s%*s: arr[%zu] = ", arr_str, padding, "", len);
  // sort_asc_bubble_arr_int(arr, len);
  sort_asc_quick_arr_int(arr, len);
  print_arr_int(arr, len);
  printf(".\n");

  padding = strlen("array_sorted") - len_sorted;
  padding = abs(padding);
  printf("%s%*s: is_sorted_asc_arr_int(arr, %zu) = %s.\n", sorted, padding, "",
         len, is_sorted_asc_arr_int(arr, len) ? "true" : "false");

  printf("%s%*s: is_sorted_desc_arr_int(arr, %zu) = %s.\n", sorted, padding, "",
         len, is_sorted_desc_arr_int(arr, len) ? "true" : "false");
  putchar('\n');

  return exit_code;
}
