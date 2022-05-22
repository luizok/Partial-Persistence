#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "version_ctrl.h"
#include "utils.h"


extern LLNode_t** versions;
extern int curr_version;


LLNode_t* get_node_next_field_at_version(LLNode_t* node, int version) {

    ChangeLog_t* last_cl = NULL;
    for(int i=0; i < MODS_SIZE; i++)
        if(node->mods[i])
            if(node->mods[i]->version <= version) {
                last_cl = node->mods[i];
            }

    if(last_cl)     
        return (LLNode_t*) last_cl->field_value;

    return NULL;
}

LLNode_t* get_node_next_field_latest(LLNode_t* node) {

    if(!node)
        return NULL;

    return get_node_next_field_at_version(node, curr_version-1);
}

void log_change(LLNode_t** node,
                int version,
                char* field_name,
                char* field_addr,
                int field_size) {
    ChangeLog_t* cl = new_change_log(version,
                                     field_name,
                                     field_addr,
                                     field_size);

    if((*node)->curr_mod < 2) {
        (*node)->mods[(*node)->curr_mod] = cl;
        (*node)->curr_mod++;
        return;
    }

    printf("BIXOU\n");
    LLNode_t* new = new_node((*node)->value);
    new->next = (LLNode_t*) (*node)->mods[1]->field_value;
    new->backref_next = (*node)->backref_next;

    log_change(&new,
               version,
               field_name,
               (char*) &(new->next),
               sizeof(LLNode_t*));

    if(new->backref_next)
        log_change(&(new->backref_next),
                   version,
                   field_name,
                   (char*) &new,
                   sizeof(LLNode_t*));
}


LLNode_t* new_node(int value) {

    LLNode_t* node = (LLNode_t*) malloc(sizeof(LLNode_t));
    node->value = value;
    node->next = NULL;
    node->backref_next = NULL;
    node->curr_mod = 0;

    for(int i=0; i < MODS_SIZE; i++)
        node->mods[i] = NULL;

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
    LLNode_t* latest_next_node = get_node_next_field_latest(curr_node);
    while(latest_next_node && (latest_next_node->value < value)) {
        curr_node = get_node_next_field_latest(curr_node);
        latest_next_node = get_node_next_field_latest(curr_node);
    }

    printf("new: %p\n", new);
    printf("curr: %p\n", curr_node);
    printf("next: %p\n", latest_next_node);
    printf("\n");

    new->backref_next = curr_node;
    if(latest_next_node)
        latest_next_node->backref_next = new;

    log_change(&new,
               curr_version,
               "next",
               (char*) &latest_next_node,
               sizeof(LLNode_t*));

    log_change(&curr_node,
               curr_version,
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
    LLNode_t* next_latest_node = NULL;
    while(curr_node) {
        if(curr_node->value == value) {
            if(prev_node) {
                // prev_node->next = curr_node->next;
                next_latest_node = get_node_next_field_latest(curr_node);
                log_change(prev_node == *root ? root : &prev_node,
                           curr_version,
                           "next",
                           (char*) &next_latest_node,
                           sizeof(LLNode_t*));
            } else {
                *root = get_node_next_field_latest(curr_node);
                if(*root)
                    (*root)->backref_next = NULL;
            }

            update_version(*root);
            return TRUE;
        }

        prev_node = curr_node;
        curr_node = get_node_next_field_latest(curr_node);
    }

    update_version(*root);
    return FALSE;
}

int search_node(LLNode_t** root, int value) {

    return -1;
}

int successor_node(int value, int version) {

    int v = version >= curr_version ? curr_version-1 : version; 
    LLNode_t* root = versions[v];
    LLNode_t* prev = NULL;
    while(root) {
        if(root->value > value)
            return root->value;

        root = get_node_next_field_at_version(root, version);
    }

    return -1;
}

void print_as_list_at_version(int version) {

    int v = version >= curr_version ? curr_version-1 : version;
    print_as_list_debug(versions[v], v);
    // print_as_list(versions[v], v);
}

void print_as_list(LLNode_t* root, int version) {
    
    printf("V%d: ", version);
    while(root) {
        printf("%d ", root->value);
        root = get_node_next_field_at_version(root, version);
    }
    printf("\n");
}

void print_as_list_debug(LLNode_t* root, int version) {

    printf("LISTA V%d\n", version);
    while(root) {
        printf(
            "at: %p, v: %d, backref v: %d, mods: ",
            root, root->value,
            root->backref_next ? root->backref_next->value : -1
        );
        for(int i=0; i < MODS_SIZE; i++) {
            if(root->mods[i]) {
                printf("(v%d, %s, %p) ",
                        root->mods[i]->version,
                        root->mods[i]->field_name,
                        root->mods[i]->field_value);
            }
        }
        printf("\n");
            
        // root = root->next;
        root = get_node_next_field_at_version(root, version);
    }
}