#ifndef CHANGE_LOG_H
#define CHANGE_LOG_H


typedef struct ChangeLog {
    int version;
    char field_name[32];
    int new_value;
} ChangeLog_t;


ChangeLog_t* new_change_log(int version, char* field_name, int new_value);

#endif
