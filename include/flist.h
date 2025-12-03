// ~/.config/c-cpp/c/libraries/f-libs/include/flist.h
#ifndef FLIST_H_
#define FLIST_H_

#include "fstr.h"
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
};

#endif
