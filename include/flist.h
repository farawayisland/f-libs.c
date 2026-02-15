// ~/.config/c-cpp/c/libraries/f-libs/include/flist.h
#ifndef FLIST_H_
#define FLIST_H_

#include "fio.h"
#include "fstat.h"

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
  bool sorted_asc;
  bool sorted_desc;
  size_t len;
  struct SListNode *head;
  struct SListNode *mid;
  struct SListNode *tail;
};

// Memory allocations and deallocations for list nodes and lists
extern struct SList *init_empty_list_s(void);
extern struct SList *init_list_s(const char *id, int val);
extern struct SListNode *init_empty_node_s(void);
extern struct SListNode *init_node_s(const char *id, int val);
extern void free_list_s(struct SList **list_ref);
extern void free_node_s(struct SListNode **node_ref);

// Operations for list nodes and lists
/// List-node data
extern char *get_id_data_s(char *str, size_t size, struct SListNodeData *data);
extern char *get_id_dest_data_s(struct SListNodeData *data);
extern int get_val_data_s(struct SListNodeData *data);
extern struct SListNodeData *get_data_s(struct SListNode *node);
extern void set_data_node_s(struct SListNode *node, struct SListNodeData *data);
extern void set_id_data_s(struct SListNodeData *data, const char *id);
extern void set_id_dest_data_s(struct SListNodeData *data, char *id_dest);
extern void set_val_data_s(struct SListNodeData *data, int val);

/// Next nodes
extern struct SListNode *get_next_node_s(struct SListNode *node);
extern void set_next_node_s(struct SListNode *node, struct SListNode *next);

/// Remove nodes
extern struct SListNode *remove_node_s(struct SList *list,
                                       struct SListNode *target);

/// Append and prepend nodes
extern void append_node_s(struct SList *list, struct SListNode *anchor,
                          struct SListNode *new_node);
extern void prepend_node_s(struct SList *list, struct SListNode *anchor,
                           struct SListNode *new_node);

/// Head nodes
extern struct SListNode *get_head_list_s(struct SList *list);
extern void set_head_list_s(struct SList *list, struct SListNode *head);

//// Push and pop head nodes
extern struct SListNode *pop_head_node_s(struct SList *list);
extern void push_head_node_s(struct SList *list, struct SListNode *new_node);

/// Middle nodes
extern struct SListNode *get_mid_list_s(struct SList *list);
extern void set_mid_list_s(struct SList *list, struct SListNode *mid);

//// Push and pop middle nodes
extern struct SListNode *pop_mid_node_s(struct SList *list);
extern void push_mid_node_s(struct SList *list, struct SListNode *new_node);

//// Recalculate middle-nodes
extern void recalc_mid_list_s(struct SList *list);

/// Tail nodes
extern struct SListNode *get_tail_list_s(struct SList *list);
extern void set_tail_list_s(struct SList *list, struct SListNode *tail);

//// Push and pop tail nodes
extern struct SListNode *pop_tail_node_s(struct SList *list);
extern void push_tail_node_s(struct SList *list, struct SListNode *new_node);

// List length
extern size_t get_len_list_s(struct SList *list);
extern void recalc_len_list_s(struct SList *list);
extern void set_len_list_s(struct SList *list, size_t len);

// Print list nodes and lists
extern void print_list_s(struct SList *list);
extern void print_node_s(struct SListNode *node);

#endif
