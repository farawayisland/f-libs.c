// ~/.config/c-cpp/c/libraries/f-libs/tests/test-main.c
#include "flist.h"

int main(void) {
  int exit_code = SUCCESS;

  struct SList *list = init_empty_list_s();
  struct SListNode *node_a = init_node_s("A", 1);
  struct SListNode *node_b = init_node_s("B", 2);
  struct SListNode *node_c = init_node_s("C", 3);
  struct SListNode *node_d = init_node_s("D", 4);
  struct SListNode *node_e = init_node_s("E", 5);
  struct SListNode *node_x = init_node_s("X", 24);
  struct SListNode *node_y = init_node_s("Y", 25);
  struct SListNode *node_z = init_node_s("Z", 26);

  push_head_node_s(list, node_c);
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  push_tail_node_s(list, node_y);
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  push_mid_node_s(list, node_x);
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  push_mid_node_s(list, node_d);
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  prepend_node_s(list, node_c, node_a);
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  append_node_s(list, node_y, node_z);
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  append_node_s(list, node_a, node_b);
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  prepend_node_s(list, node_x, node_e);
  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  struct SListNode *popped_head = pop_head_node_s(list);
  struct SListNode *popped_mid = pop_mid_node_s(list);
  struct SListNode *popped_tail = pop_tail_node_s(list);
  struct SListNode *removed_node = remove_node_s(list, node_e);
  struct SListNode *head = get_head_list_s(list);
  struct SListNode *mid = get_mid_list_s(list);
  struct SListNode *tail = get_tail_list_s(list);

  printf("list = ");
  print_list_s(list);
  printf("\n\n");

  printf("popped_head = ");
  if (popped_head) {
    print_node_s(popped_head);
  }
  printf("\n\n");

  printf("popped_mid = ");
  if (popped_mid) {
    print_node_s(popped_mid);
  }
  printf("\n\n");

  printf("popped_tail = ");
  if (popped_tail) {
    print_node_s(popped_tail);
  }
  printf("\n\n");

  printf("removed_node = ");
  if (removed_node) {
    print_node_s(removed_node);
  }
  printf("\n\n");

  printf("head = ");
  if (head) {
    print_node_s(head);
  }
  printf("\n\n");

  printf("mid = ");
  if (mid) {
    print_node_s(mid);
  }
  printf("\n\n");

  printf("tail = ");
  if (tail) {
    print_node_s(tail);
  }
  printf("\n\n");

  const size_t len = get_len_list_s(list);
  printf("len = %zu\n", len);

  free_node_s(&popped_head);
  free_node_s(&popped_mid);
  free_node_s(&popped_tail);
  free_node_s(&removed_node);
  free_list_s(&list);

  return exit_code;
}
