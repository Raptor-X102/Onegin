#include <TXLib.h>
#include "File_output.h"
#include "Onegin_data_Ctor.h"
#include "Quick_sort.h"
#include "DEBUG_PRINTF.h"
#include "Free.h"
#include <assert.h>

int main(){
    //fclose(stdout);
    onegin_files_data onegin_data = {};
    line* array_of_ptrs = NULL;

    if(!Onegin_data_Ctor(&onegin_data, &array_of_ptrs))
        goto stop;

    quick_sort(array_of_ptrs, 0, onegin_data.ptrs_to_str_len-1, sizeof(line), Compare_Structs_beg);

    //file_output_console(&onegin_data, array_of_ptrs);
    if(!file_output(&onegin_data, array_of_ptrs))
        goto stop;

    quick_sort(array_of_ptrs, 0, onegin_data.ptrs_to_str_len-1, sizeof(line), Compare_Structs_end);
    DEBUG_PRINTF("8\n");
    //file_output_console(&onegin_data, array_of_ptrs);

    if(!file_output(&onegin_data, array_of_ptrs))
        goto stop;

    if(!file_output_init_text(&onegin_data))
        goto stop;

    stop:
    if(fclose(onegin_data.file_onegin)) {

        fprintf(stderr, "File 'Onegin_sorted.txt' was not closed");

    }

    Free(2, onegin_data.file_onegin_buffer, array_of_ptrs);

}
