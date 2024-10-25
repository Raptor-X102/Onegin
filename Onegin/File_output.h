#ifndef FILE_OUTPUT
#define FILE_OUTPUT
#include <stdio.h>
#include "onegin_files_data.h"
#include "Str_len.h"
#include "DEBUG_PRINTF.h"

bool file_output(onegin_files_data * onegin_data, line * array_of_ptrs);
bool file_output_init_text(onegin_files_data * onegin_data);
void file_output_console(onegin_files_data * onegin_data, line * array_of_ptrs);

#endif
