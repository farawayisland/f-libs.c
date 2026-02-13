// ~/.config/c-cpp/c/libraries/f-libs/src/test.c
#include "flist.h"

int main(void) {
  int exit_code = SUCCESS;

  struct SList *list = init_list_s("A", 1);

  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  struct SListNode *new_node = init_node_s("C", 3);
  struct SListNode *node_c = new_node;

  append_node_s(list, get_head_list_s(list), node_c);
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  prepend_node_s(list, node_c, init_node_s("B", 2));
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  new_node = init_node_s("Z", 6);
  push_head_node_s(list, new_node);
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  new_node = init_node_s("D", 4);
  push_tail_node_s(list, new_node);
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  struct SListNode *popped_head = pop_head_node_s(list);
  printf("popped_head = ");
  print_node_s(popped_head);
  putchar('\n');

  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  struct SListNode *removed_node = remove_node_s(list, node_c);
  printf("removed_node = ");
  print_node_s(removed_node);
  putchar('\n');

  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  struct SListNode *popped_tail = pop_tail_node_s(list);
  printf("popped_tail = ");
  print_node_s(popped_tail);
  putchar('\n');

  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  const size_t len_list = get_len_list_s(list);
  printf("len_list = %zu\n", len_list);

  free_node_s(&popped_head);
  free_node_s(&removed_node);
  free_node_s(&popped_tail);
  free_list_s(&list);

  // const size_t len = argc - 1;
  // int arr[len];
  //
  // for (size_t i = 0; i < len; ++i) {
  //
  //   parse_int(&arr[i], argv[i + 1]);
  // }
  //
  // const char sorted[] = "sortedness";
  // const size_t len_sorted = strlen(sorted);
  // char *arr_str = "array";
  // int padding = strlen("array_sorted") - strlen(arr_str);
  // padding = abs(padding);
  //
  // printf("%s%*s: arr[%zu] = ", arr_str, padding, "", len);
  // print_arr_int(arr, len);
  // printf(".\n");
  //
  // padding = strlen("array_sorted") - len_sorted;
  // padding = abs(padding);
  // printf("%s%*s: is_sorted_asc_arr_int(arr, %zu) = %s.\n", sorted, padding,
  // "",
  //        len, is_sorted_asc_arr_int(arr, len) ? "true" : "false");
  //
  // printf("%s%*s: is_sorted_desc_arr_int(arr, %zu) = %s.\n", sorted, padding,
  // "",
  //        len, is_sorted_desc_arr_int(arr, len) ? "true" : "false");
  // putchar('\n');
  //
  // arr_str = "array_sorted";
  // padding = strlen("array_sorted") - strlen(arr_str);
  // padding = abs(padding);
  // printf("%s%*s: arr[%zu] = ", arr_str, padding, "", len);
  // // sort_asc_bubble_arr_int(arr, len);
  // sort_asc_quick_arr_int(arr, len);
  // print_arr_int(arr, len);
  // printf(".\n");
  //
  // padding = strlen("array_sorted") - len_sorted;
  // padding = abs(padding);
  // printf("%s%*s: is_sorted_asc_arr_int(arr, %zu) = %s.\n", sorted, padding,
  // "",
  //        len, is_sorted_asc_arr_int(arr, len) ? "true" : "false");
  //
  // printf("%s%*s: is_sorted_desc_arr_int(arr, %zu) = %s.\n", sorted, padding,
  // "",
  //        len, is_sorted_desc_arr_int(arr, len) ? "true" : "false");
  // putchar('\n');

  return exit_code;
}
