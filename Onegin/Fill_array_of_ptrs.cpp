#include "Fill_array_of_ptrs.h"

line* fill_ptr_arr(onegin_files_data * onegin_data, line** array_of_ptrs){

    onegin_data->ptrs_to_str_len = find_str_amount(onegin_data->file_onegin_buffer, onegin_data->file_lenth);
    if(!onegin_data->ptrs_to_str_len) {

        fprintf(stderr, "In function 'fill_ptr_arr'\nERROR: amount of strings equals to 0\n");
        return NULL;

    }

    DEBUG_PRINTF("\nptrs_to_str_len = %d\n", onegin_data->ptrs_to_str_len);

    *array_of_ptrs = (line*) calloc(onegin_data->ptrs_to_str_len, sizeof(line));
    if (*array_of_ptrs == NULL){

        fprintf(stderr, "In function 'fill_ptr_arr'\nERROR: memory was not allocated!\n");
        return NULL;

    }

    (*(array_of_ptrs))[0].ptrs_to_str = onegin_data->file_onegin_buffer;

    for(unsigned long long int i = 2, j = 1; i<onegin_data->file_lenth-1; i++){

        if(onegin_data->file_onegin_buffer[i] == '\n'  &&
           onegin_data->file_onegin_buffer[i+1] != EOF &&
           onegin_data->file_onegin_buffer[i-2] != '\n')
        {

            (*(array_of_ptrs))[j-1].ptrs_to_str_end = onegin_data->file_onegin_buffer+i;


            for(; onegin_data->file_onegin_buffer[i+1] == '\r' || onegin_data->file_onegin_buffer[i+1] == '\n';i++);

            (*(array_of_ptrs))[j].ptrs_to_str = onegin_data->file_onegin_buffer+i+1;
            j++;
        }

    }
    int i = onegin_data->file_lenth-1;
    for(; onegin_data->file_onegin_buffer[i] == '\r' || onegin_data->file_onegin_buffer[i] == '\n';i--);

    (*(array_of_ptrs))[onegin_data->ptrs_to_str_len-1].ptrs_to_str_end = onegin_data->file_onegin_buffer+i+2;

    return *array_of_ptrs;

}
