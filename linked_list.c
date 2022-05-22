#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "version_ctrl.h"
#include "utils.h"


extern int curr_version;


void log_change(LLNode_t* node,
                int version,
                char* field_name,
                char* field_addr,
                int field_size) {
    ChangeLog_t* cl = new_change_log(version,
                                     field_name,
                                     field_addr,
                                     field_size);
    if(node->curr_mod < 2) {
        node->mods[node->curr_mod] = cl;
        node->curr_mod++;
        return;
    }

    // Create new node and update
}


LLNode_t* new_node(int value) {

    LLNode_t* node = (LLNode_t*) malloc(sizeof(LLNode_t));
    node->value = value;
    node->next = NULL;
    node->backref_next = NULL;
    node->curr_mod = 0;

    return node;
}

BOOL insert_node(LLNode_t** root, int value) {

    LLNode_t* new = new_node(value);

    if(!(*root)) {
        *root = new;
        update_version(*root);
        return TRUE;
    }
    
    LLNode_t* curr_node = *root;
    while(curr_node->next)
        curr_node = curr_node->next;

    new->backref_next = curr_node;
    curr_node->next = new;

    log_change(curr_node,
               curr_version+1,
               "next",
               (char*) &new,
               sizeof(LLNode_t*));

    update_version(*root);

    return TRUE;
}

BOOL remove_node(LLNode_t** root, int value) {

    if(!(*root)) {
        update_version(*root);
        return FALSE;
    }

    LLNode_t* prev_node = NULL;
    LLNode_t* curr_node = *root;
    while(curr_node) {
        if(curr_node->value == value) {
            if(prev_node) {
                // prev_node->next = curr_node->next;
                log_change(prev_node,
                           curr_version+1,
                           "next",
                           (char*) &curr_node->next,
                           sizeof(LLNode_t*));
                if(curr_node->next)
                    curr_node->next->backref_next = prev_node;
            } else {
                *root = curr_node->next;
                if(*root)
                    (*root)->backref_next = NULL;
            }

            update_version(*root);
            return TRUE;
        }

        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    update_version(*root);
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
            "at: %p, v: %d, backref v: %d, mods: ",
            root, root->value,
            root->backref_next ? root->backref_next->value : -1
        );
        for(int i=0; i < MODS_SIZE; i++) {
            if(root->mods[i]) {
                printf("(v%d, %s, 0x",
                        root->mods[i]->version,
                        root->mods[i]->field_name);
                for(int k=0; k < root->mods[i]->field_size-1; k++)
                    printf("%02x",  (BYTE) root->mods[i]->field_value[k]);
                printf("), ");
            }
        }
        printf("\n");
            
        root = root->next;
    }
}