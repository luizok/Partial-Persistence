#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "change_log.h"
#include "utils.h"


ChangeLog_t* new_change_log(int version,
                            char* field_name,
                            char* field_addr,
                            int field_size) {

    ChangeLog_t* change_log = (ChangeLog_t*) malloc(sizeof(ChangeLog_t));
    change_log->version = version;
    memcpy(change_log->field_name, field_name, 32);

    change_log->field_value = (char*) malloc(field_size);
    memcpy((char*) &(change_log->field_value), field_addr, field_size);
    change_log->field_size = field_size;

    return change_log;
}
