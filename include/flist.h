// ~/.config/c-cpp/c/libraries/f-libs/include/flist.h
#ifndef FLIST_H_
#define FLIST_H_

#include "fio.h"
#include <stdlib.h>

/* Singly-Linked List */
// List-node data
struct SListNodeData {
  char *id;
  int val;
};

// List node
struct SListNode {
  struct SListNode *next;
  struct SListNodeData *data;
};

// List
struct SList {
  size_t len;
  struct SListNode *head;
  struct SListNode *tail;
};

// Memory allocations and deallocations for list nodes and lists
struct SList *init_list_s(const char *id, int val);
struct SListNode *init_node_s(const char *id, int val);
void free_list_s(struct SList **list_ref);
void free_node_s(struct SListNode **node_ref);

// Operations for list nodes and lists
/// List-node data
char *get_id_data_s(char *str, size_t size, struct SListNodeData *data);
char *get_id_dest_data_s(struct SListNodeData *data);
int get_val_data_s(struct SListNodeData *data);
struct SListNodeData *get_data_s(struct SListNode *node);
void set_data_node_s(struct SListNode *node, struct SListNodeData *data);
void set_id_data_s(struct SListNodeData *data, const char *id);
void set_id_dest_data_s(struct SListNodeData *data, char *id_dest);
void set_val_data_s(struct SListNodeData *data, int val);

/// Next nodes
struct SListNode *get_next_node_s(struct SListNode *node);
void set_next_node_s(struct SListNode *node, struct SListNode *next);

/// Remove nodes
struct SListNode *remove_node_s(struct SList *list, struct SListNode *target);

/// Append and prepend nodes
void append_node_s(struct SList *list, struct SListNode *anchor,
                   struct SListNode *new_node);
void prepend_node_s(struct SList *list, struct SListNode *anchor,
                    struct SListNode *new_node);

/// Head nodes
struct SListNode *get_head_list_s(struct SList *list);
void set_head_list_s(struct SList *list, struct SListNode *head);

//// Push and pop head nodes
struct SListNode *pop_head_node_s(struct SList *list);
void push_head_node_s(struct SList *list, struct SListNode *new_node);

/// Tail nodes
struct SListNode *get_tail_list_s(struct SList *list);
void set_tail_list_s(struct SList *list, struct SListNode *tail);

//// Push and pop tail nodes
struct SListNode *pop_tail_node_s(struct SList *list);
void push_tail_node_s(struct SList *list, struct SListNode *new_node);

// List length
size_t get_len_list_s(struct SList *list);
void recalc_len_list_s(struct SList *list);
void set_len_list_s(struct SList *list, size_t len);

// Print list nodes and lists
void print_list_s(struct SList *list);
void print_node_s(struct SListNode *node);

#endif
