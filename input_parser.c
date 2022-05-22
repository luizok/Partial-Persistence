#include <string.h>

#include "input_parser.h"
#include "linked_list.h"
#include "utils.h"


extern LLNode_t* root;


void parse_file(char *filename) {

    FILE* fp = fopen(filename, "r");
    char cmd[4];
    int params[2];

    while(!feof(fp)) {
        fscanf(fp, "%s %d %d\n", cmd, &params[0], &params[1]);
        // printf("cmd: %s, p1: %d, p2: %d\n", cmd, params[0], params[1]);
        if(strcmp(cmd, "INC") == 0) {
            insert_node(&root, params[0]);
        } else if(strcmp(cmd, "REM") == 0) {
            remove_node(&root, params[0]);
        } else if(strcmp(cmd, "SUC") == 0) {
            printf("NOT IMPLEMENTED - SUC");
        } else if(strcmp(cmd, "IMP") == 0) {
            print_as_list_at_version(params[0]);
        }
    }
}