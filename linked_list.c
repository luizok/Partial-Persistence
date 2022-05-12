#include <stdlib.h>

#include "linked_list.h"
#include "utils.h"


LLNode_t* new_node(int value) {

    LLNode_t* node = (LLNode_t*) malloc(sizeof(LLNode_t));
    node->value = value;
    node->next = NULL;

    return node;
}


BOOL insert_node(LLNode_t** root, int value) {

    LLNode_t* new = new_node(value);
    if(!(*root)) {
        *root = new;
        return TRUE;
    }
    
    LLNode_t* curr_node = *root;
    while(curr_node->next)
        curr_node = curr_node->next;    
    
    curr_node->next = new;

    return TRUE;
}

BOOL remove_node(LLNode_t** root, int value) {

    return TRUE;
}

int search_node(LLNode_t** root, int value) {

    return -1;
}

int successor_node(LLNode_t** root, int value) {

    return -1;
}
