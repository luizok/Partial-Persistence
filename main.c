#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "version_ctrl.h"
#include "utils.h"

extern int curr_version;


int main() {

    init_versions();
    LLNode_t* root = NULL;

    insert_node(&root, 0);
    printf("\n");
    insert_node(&root, 1);
    printf("\n");
    insert_node(&root, 2);
    printf("\n");
    insert_node(&root, 3);
    printf("\n");
    insert_node(&root, 4);
    printf("\n");
    insert_node(&root, 5);
    printf("\n");
    insert_node(&root, 6);
    printf("\n");
    insert_node(&root, 7);
    printf("\n");
    insert_node(&root, 8);
    printf("\n");

    // remove_node(&root, 0);
    remove_node(&root, 2);
    // remove_node(&root, 3);
    // remove_node(&root, 1);

    print_as_list_at_version(0);
    printf("\n");
    print_as_list_at_version(1);
    printf("\n");
    print_as_list_at_version(2);
    printf("\n");
    print_as_list_at_version(3);
    printf("\n");
    print_as_list_at_version(4);
    printf("\n");
    print_as_list_at_version(8);
    print_as_list_at_version(9);
    print_as_list_at_version(5);
    printf("\n");


    printf("Latest version: %d\n", curr_version-1);

    return 0;
}
