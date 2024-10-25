#ifndef ONEGIN_FILES_DATA
#define ONEGIN_FILES_DATA
#include <stdio.h>

struct onegin_files_data {

    char* file_onegin_buffer;
    unsigned long long int file_lenth;
    //char** ptrs_to_str;
    //char** ptrs_to_str_end;
    unsigned long long int ptrs_to_str_len;
    FILE * file_onegin;

};

struct line {

    char* ptrs_to_str;
    char* ptrs_to_str_end;

};

#endif
