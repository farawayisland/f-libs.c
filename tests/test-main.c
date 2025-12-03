// ~/.config/c-cpp/c/libraries/f-libs/tests/test-main.c
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

  return exit_code;
}
