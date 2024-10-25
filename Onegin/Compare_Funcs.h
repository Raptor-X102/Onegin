#ifndef COMP_FUNCS
#define COMP_FUNCS
#include <ctype.h>
#include "Str_len.h"
#include "onegin_files_data.h"

int Compare_Strings_beg (const void* str1, const void* str2);
int Compare_Strings_end (const void* str1, const void* str2);
int Compare_int(const void* int1, const void* int2);
int Compare_Structs_beg (const void* str1, const void* str2);
int Compare_Structs_end (const void* str1, const void* str2);

#endif
