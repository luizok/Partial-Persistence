#ifndef CHANGE_LOG_H
#define CHANGE_LOG_H


typedef struct ChangeLog {
    int version;
    char field_name[32];
    char* field_value;
    int field_size; 
} ChangeLog_t;


ChangeLog_t* new_change_log(int version,
                            char* field_name,
                            char* field_addr,
                            int field_size);

#endif
