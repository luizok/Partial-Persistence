#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "change_log.h"
#include "utils.h"


typedef struct LLNode {
    int value;
    struct LLNode* next;
    struct LLNode* backref_next;
    ChangeLog_t mods[2];
} LLNode_t;


LLNode_t* new_node(int value);
BOOL insert_node(LLNode_t** root, int value);
BOOL remove_node(LLNode_t** root, int value);
int search_node(LLNode_t** root, int value);
int successor_node(LLNode_t** root, int value);
void print_as_list(LLNode_t* root);

#endif
