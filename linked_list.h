#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define MODS_SIZE 2

#include "change_log.h"
#include "utils.h"


typedef struct LLNode {
    int value;
    struct LLNode* next;
    struct LLNode* backref_next;
    ChangeLog_t* mods[MODS_SIZE];
    int curr_mod;
} LLNode_t;


LLNode_t* new_node(int value);
BOOL insert_node(LLNode_t** root, int value);
BOOL remove_node(LLNode_t** root, int value);
int search_node(LLNode_t** root, int value);
int successor_node(LLNode_t** root, int value);
void print_as_list_at_version(int version);

#endif
