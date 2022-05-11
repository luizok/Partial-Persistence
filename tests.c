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

int main() {

    test_new_node();
}
