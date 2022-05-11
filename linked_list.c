#include <stdlib.h>

#include "linked_list.h"
#include "utils.h"


LLNode_t* new_node(int value) {

    LLNode_t* node = (LLNode_t*) malloc(sizeof(LLNode_t));
    node->value = value;
    node->next = NULL;

    return node;
}


BOOL insert_node(LLNode_t* root, int value) {

    return FALSE;
}

BOOL remove_node(LLNode_t* root, int value) {

    return TRUE;
}

int search_node(LLNode_t* root, int value) {

    return -1;
}

int successor_node(LLNode_t* root, int value) {

    return -1;
}
