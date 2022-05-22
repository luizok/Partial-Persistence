#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "version_ctrl.h"


LLNode_t** versions;
int curr_version = 0;

void init_versions() {

    versions = (LLNode_t**) malloc(MAX_VERSIONS * sizeof(LLNode_t*));
}

int update_version(LLNode_t* root) {

    versions[curr_version] = root;
    curr_version++;
}
