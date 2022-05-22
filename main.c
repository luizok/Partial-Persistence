#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "version_ctrl.h"
#include "input_parser.h"
#include "utils.h"

extern int curr_version;
LLNode_t* root;


int main(int argc, char** argv) {

    init_versions();

    root = NULL;
    parse_file(argv[1]);
    int v = 0;

    // for(int v=0; v < curr_version; v++)
    //     print_as_list_at_version(v);

    // printf("\n");

    printf("Latest version: %d\n", curr_version-1);

    return 0;
}
