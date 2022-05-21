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

    new->backref_next = curr_node;
    curr_node->next = new;
    curr_node->next = new;

    return TRUE;
}

BOOL remove_node(LLNode_t** root, int value) {

    if(!(*root))
        return FALSE;

    LLNode_t* prev_node = NULL;
    LLNode_t* curr_node = *root;
    while(curr_node) {
        if(curr_node->value == value) {
            if(prev_node) {
                prev_node->next = curr_node->next;
                if(curr_node->next)
                    curr_node->next->backref_next = prev_node;
            } else {
                *root = curr_node->next;
                if(*root)
                    (*root)->backref_next = NULL;
            }

            return TRUE;
        }

        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    return FALSE;
}

int search_node(LLNode_t** root, int value) {

    return -1;
}

int successor_node(LLNode_t** root, int value) {

    return -1;
}

void print_as_list(LLNode_t* root) {

    printf("LISTA\n");
    while(root) {
        printf(
            "at: %p, v: %d, backref v: %d\n",
            root, root->value,
            root->backref_next ? root->backref_next->value : -1
        );
        root = root->next;
    }
}