#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "utils.h"


ChangeLog_t* new_change_log(int version, char* field_name, int new_value) {

    ChangeLog_t* change_log = (ChangeLog_t*) malloc(sizeof(ChangeLog_t));
    change_log->version = version;
    change_log->new_value = new_value;

    strncpy(change_log->field_name, field_name, 32);

    return change_log;
}
