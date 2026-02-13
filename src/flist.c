// ~/.config/c-cpp/c/libraries/f-libs/src/flist.c
#include "flist.h"

/* Singly-Linked List */
// Memory allocations and deallocations for list nodes and lists
struct SList *init_list_s(const char *id, int val) {
  struct SList *new_list = malloc(sizeof(*new_list));
  struct SListNode *new_node = init_node_s(id, val);
  size_t new_len = 1;

  if (!new_list) {
    const char err[] = "ERROR: `malloc()` returned NULL.";
    println_err(err);
    exit(EXIT_FAILURE);
  }

  set_head_list_s(new_list, new_node);
  set_tail_list_s(new_list, new_node);
  set_len_list_s(new_list, new_len);

  return new_list;
}

struct SListNode *init_node_s(const char *id, int val) {
  struct SListNode *new_node = malloc(sizeof(*new_node));
  struct SListNodeData *new_data = malloc(sizeof(*new_data));
  char *new_id = calloc(MAX_SIZE_STR_GENERAL, sizeof(*new_id));

  if (!new_node || !new_data || !new_id) {
    const char err[] = "ERROR: either `malloc()` or `calloc()` returned NULL.";
    println_err(err);
    exit(EXIT_FAILURE);
  }

  snprintf(new_id, MAX_SIZE_STR_GENERAL, "%s", id);
  set_id_dest_data_s(new_data, new_id);
  set_val_data_s(new_data, val);
  set_data_node_s(new_node, new_data);
  set_next_node_s(new_node, NULL);

  return new_node;
}

void free_list_s(struct SList **list_ref) {
  struct SList *list = *list_ref;
  struct SListNode *head = get_head_list_s(list);
  struct SListNode *curr = head;

  while (curr) {
    struct SListNode *temp = curr;
    curr = get_next_node_s(curr);
    free_node_s(&temp);
  }

  head = NULL;
  free(list);
  list = NULL;
  *list_ref = NULL;
}

void free_node_s(struct SListNode **node_ref) {
  struct SListNode *node = *node_ref;
  struct SListNodeData *data = get_data_s(node);
  char *id = get_id_dest_data_s(data);

  free(id);
  id = NULL;
  set_id_dest_data_s(data, NULL);
  free(data);
  data = NULL;
  set_data_node_s(node, NULL);
  set_next_node_s(node, NULL);
  free(node);
  node = NULL;
  *node_ref = NULL;
}

// Operations for list nodes and lists
/// List-node data
char *get_id_data_s(char *str, size_t size, struct SListNodeData *data) {
  if (size < MAX_SIZE_STR_GENERAL) {
    const char err[] = "ERROR: `size` < `MAX_SIZE_STR_GENERAL`.";
    println_err(err);
  } else {
    const char *const id = get_id_dest_data_s(data);
    snprintf(str, MAX_SIZE_STR_GENERAL, "%s", id);
  }

  return str;
}

char *get_id_dest_data_s(struct SListNodeData *data) { return data->id; }

int get_val_data_s(struct SListNodeData *data) { return data->val; }

struct SListNodeData *get_data_s(struct SListNode *node) { return node->data; }

void set_data_node_s(struct SListNode *node, struct SListNodeData *data) {
  node->data = data;
}

void set_id_data_s(struct SListNodeData *data, const char *id) {
  const size_t len = strlen(id);
  const size_t size_min = len + 1;

  if (size_min > MAX_SIZE_STR_GENERAL) {
    const char err[] = "ERROR: `size_min` > `MAX_SIZE_STR_GENERAL`.";
    println_err(err);
  } else {
    char *const old_id = get_id_dest_data_s(data);
    snprintf(old_id, size_min, "%s", id);
  }
}

void set_id_dest_data_s(struct SListNodeData *data, char *id_dest) {
  data->id = id_dest;
}

void set_val_data_s(struct SListNodeData *data, int val) { data->val = val; }

/// Next nodes
struct SListNode *get_next_node_s(struct SListNode *node) { return node->next; }

void set_next_node_s(struct SListNode *node, struct SListNode *next) {
  node->next = next;
}

/// Remove nodes
struct SListNode *remove_node_s(struct SList *list, struct SListNode *target) {
  struct SListNode *removed_node = NULL;
  struct SListNode *head = get_head_list_s(list);
  struct SListNode *tail = get_tail_list_s(list);

  if (target == head) {
    removed_node = pop_head_node_s(list);
  } else if (target == tail) {
    removed_node = pop_tail_node_s(list);
  } else {

    struct SListNode **curr_ref = &list->head;
    struct SListNode *curr = *curr_ref;

    while (curr && (curr != target)) {
      curr_ref = &curr->next;
      curr = *curr_ref;
    }

    if (curr) {

      removed_node = curr;
      struct SListNode *next = get_next_node_s(curr);
      const size_t len = get_len_list_s(list);

      *curr_ref = next;
      set_len_list_s(list, len - 1);
    }
  }

  return removed_node;
}

/// Append and prepend nodes
void append_node_s(struct SList *list, struct SListNode *anchor,
                   struct SListNode *new_node) {
  if (!list || !anchor || !new_node) {
    const char err[] =
        "ERROR: either `list` or `anchor` or `new_node` is NULL.";
    println_err(err);
    return;
  }

  struct SListNode *tail = get_tail_list_s(list);

  if (anchor == tail) {
    push_tail_node_s(list, new_node);
  } else {
    const size_t len = get_len_list_s(list);
    struct SListNode *after_anchor = get_next_node_s(anchor);
    set_next_node_s(new_node, after_anchor);
    set_next_node_s(anchor, new_node);
    set_len_list_s(list, len + 1);
  }
}

void prepend_node_s(struct SList *list, struct SListNode *anchor,
                    struct SListNode *new_node) {
  if (!list || !new_node) {
    const char err[] = "ERROR: either `list` or `new_node` is NULL.";
    println_err(err);
    return;
  }

  struct SListNode *head = get_head_list_s(list);

  if (anchor == head) {
    push_head_node_s(list, new_node);
  } else {

    struct SListNode *before_anchor = head;

    while (before_anchor && (get_next_node_s(before_anchor) != anchor)) {
      before_anchor = get_next_node_s(before_anchor);
    }

    if (!before_anchor) {
      const char err[] =
          "ERROR: either `head` is NULL or `anchor` is not found in `list`.";
      println_err(err);
      return;
    }

    const size_t len = get_len_list_s(list);
    set_next_node_s(before_anchor, new_node);
    set_next_node_s(new_node, anchor);
    set_len_list_s(list, len + 1);
  }
}

/// Head nodes
struct SListNode *get_head_list_s(struct SList *list) { return list->head; }

void set_head_list_s(struct SList *list, struct SListNode *head) {
  list->head = head;
}

//// Push and pop head nodes
struct SListNode *pop_head_node_s(struct SList *list) {
  struct SListNode *head = NULL;

  if (!list) {
    const char err[] = "ERROR: `list` is NULL.";
    println_err(err);
  } else {

    head = get_head_list_s(list);
    struct SListNode *tail = get_tail_list_s(list);

    if (head && tail) {

      struct SListNode *next = get_next_node_s(head);
      const size_t len = get_len_list_s(list);

      set_head_list_s(list, next);
      set_next_node_s(head, NULL);
      set_len_list_s(list, len - 1);
    }

    if (head == tail) {
      set_tail_list_s(list, NULL);
    }
  }

  return head;
}

void push_head_node_s(struct SList *list, struct SListNode *new_node) {
  if (!list || !new_node) {
    const char err[] = "ERROR: either `list` or `new_node` is NULL.";
    println_err(err);
    return;
  }

  struct SListNode *head = get_head_list_s(list);
  const size_t len = get_len_list_s(list);

  set_head_list_s(list, new_node);
  set_next_node_s(new_node, head);
  set_len_list_s(list, len + 1);
}

/// Tail nodes
struct SListNode *get_tail_list_s(struct SList *list) { return list->tail; }

void set_tail_list_s(struct SList *list, struct SListNode *tail) {
  list->tail = tail;
}

//// Push and pop tail nodes
struct SListNode *pop_tail_node_s(struct SList *list) {
  struct SListNode *tail = NULL;

  if (!list) {
    const char err[] = "ERROR: `list` is NULL.";
    println_err(err);
  } else {

    struct SListNode *head = get_head_list_s(list);
    tail = get_tail_list_s(list);

    if (head && tail) {

      struct SListNode *before_tail = head;

      while (get_next_node_s(before_tail) != tail) {
        before_tail = get_next_node_s(before_tail);
      }

      const size_t len = get_len_list_s(list);

      set_tail_list_s(list, before_tail);
      set_next_node_s(before_tail, NULL);
      set_next_node_s(tail, NULL);
      set_len_list_s(list, len - 1);
    }

    if (head == tail) {
      set_head_list_s(list, NULL);
    }
  }

  return tail;
}

void push_tail_node_s(struct SList *list, struct SListNode *new_node) {
  if (!list || !new_node) {
    const char err[] = "ERROR: either `list` or `new_node` is NULL.";
    println_err(err);
    return;
  }

  struct SListNode *tail = get_tail_list_s(list);
  const size_t len = get_len_list_s(list);

  set_tail_list_s(list, new_node);
  set_next_node_s(tail, new_node);
  set_len_list_s(list, len + 1);
}

// List length
size_t get_len_list_s(struct SList *list) { return list->len; }

void recalc_len_list_s(struct SList *list) {
  if (!list) {
    const char err[] = "ERROR: either `list` is NULL.";
    println_err(err);
    return;
  }

  struct SListNode *head = get_head_list_s(list);
  struct SListNode *curr = head;
  size_t len = 0;

  while (curr) {
    curr = get_next_node_s(curr);
    ++len;
  }

  set_len_list_s(list, len);
}

void set_len_list_s(struct SList *list, size_t len) { list->len = len; }

// Print list nodes and lists
void print_list_s(struct SList *list) {
  struct SListNode *head = get_head_list_s(list);
  struct SListNode *curr = head;

  while (curr) {
    print_node_s(curr);
    const bool is_curr_tail = !get_next_node_s(curr);

    if (!is_curr_tail) {
      const char sep[] = " -> ";
      printf(sep);
    }

    curr = get_next_node_s(curr);
  }
}

void print_node_s(struct SListNode *node) {
  struct SListNodeData *data = get_data_s(node);
  const char format[] = "(%s, %d)";
  char id[MAX_SIZE_STR_GENERAL] = "";
  get_id_data_s(id, MAX_SIZE_STR_GENERAL, data);
  const int val = get_val_data_s(data);

  printf(format, id, val);
}
