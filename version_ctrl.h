#include "linked_list.h"

#define MAX_VERSIONS 100


void init_versions();
int update_version(LLNode_t* root);
void print_list_at_version(int v);