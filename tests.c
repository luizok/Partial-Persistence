#include <stdio.h>
#include <stdlib.h>


#include "linked_list.h"
#include "utils.h"


int test_new_node() {

    printf("> Test new_node\n");

    LLNode_t* node = new_node(1);

    printf("\tnode->value = 1? %d\n", node->value == 1);
    printf("\tnode->next = NULL? %d\n", node->next == NULL);
}

int test_insert_node_not_root() {

    printf("> Test insert_node not root\n");

    LLNode_t* root = new_node(1);
    BOOL done = insert_node(&root, 3);

    printf("\tis done? %d\n", done);
    printf("\troot->next->value = 3? %d\n", root->next->value == 3);
}

int test_insert_node_root() {

    printf("> Test insert_node root\n");

    LLNode_t* root = NULL;
    BOOL done = insert_node(&root, 3);

    printf("\tis done? %d\n", done);
    printf("\troot->value = 3? %d\n", root->value == 3);
}

int test_remove_node_not_root() {

    printf("> Test remove_node not root\n");

    LLNode_t* root = new_node(1);
    insert_node(&root, 2);
    insert_node(&root, 3);
    BOOL done = remove_node(&root, 2);

    printf("\tis done? %d\n", done);
    printf("\troot->next->value == 3? %d\n", root->next->value == 3);
}

int test_remove_node_root() {

    printf("> Test remove_node root\n");

    LLNode_t* root = new_node(1);
    insert_node(&root, 2);
    insert_node(&root, 3);
    BOOL done = remove_node(&root, 1);

    printf("\tis done? %d\n", done);
    printf("\troot->value == 2? %d\n", root->value == 2);
}

int _main() {

    test_new_node();
    test_insert_node_not_root();
    test_insert_node_root();
    test_remove_node_not_root();
    test_remove_node_root();
}
