#include "File_output.h"

bool file_output(onegin_files_data * onegin_data, line * array_of_ptrs){
    if(onegin_data->file_onegin == NULL){

        fprintf(stderr, "In function 'File_output'\nERROR: file was not opened\n");
        return false;

    }

    for(unsigned long long int i = 0; i<onegin_data->ptrs_to_str_len;i++){

        DEBUG_PRINTF("\n i = %d\n", i);
        DEBUG_PRINTF("\nptrs_to_str_len = %d\n", onegin_data->ptrs_to_str_len);
        DEBUG_PRINTF("%.2s  len* =  %d", array_of_ptrs[i].ptrs_to_str,
                                   array_of_ptrs[i].ptrs_to_str_end - array_of_ptrs[i].ptrs_to_str);
        DEBUG_PRINTF("\nAdresses: start = %p (%d)  end-2 = %p (%d) end-1 = %p (%d) end = %p (%d)\n",
                array_of_ptrs[i].ptrs_to_str,      *(array_of_ptrs[i].ptrs_to_str),
                array_of_ptrs[i].ptrs_to_str_end-2,*(array_of_ptrs[i].ptrs_to_str_end-2),
                array_of_ptrs[i].ptrs_to_str_end-1,*(array_of_ptrs[i].ptrs_to_str_end-1),
                array_of_ptrs[i].ptrs_to_str_end,  *(array_of_ptrs[i].ptrs_to_str_end));

        for(int j = 0; j<array_of_ptrs[i].ptrs_to_str_end - array_of_ptrs[i].ptrs_to_str+1; j++)
            DEBUG_PRINTF("%c", array_of_ptrs[i].ptrs_to_str[j]);

        DEBUG_PRINTF("   ");

        for(int j = 0; j<array_of_ptrs[i].ptrs_to_str_end - array_of_ptrs[i].ptrs_to_str+1; j++)
            DEBUG_PRINTF("%d ", array_of_ptrs[i].ptrs_to_str[j]);
        fwrite(array_of_ptrs[i].ptrs_to_str, sizeof(char), array_of_ptrs[i].ptrs_to_str_end - array_of_ptrs[i].ptrs_to_str+1,
               onegin_data->file_onegin);
        DEBUG_PRINTF("\n");
    }
    //DEBUG_PRINTF(" \\n was inserted");

    fprintf(onegin_data->file_onegin, "%c", '\n');
    return true;
}

bool file_output_init_text(onegin_files_data * onegin_data){

    if(onegin_data->file_onegin == NULL){

        fprintf(stderr, "In function 'File_output_b'\nERROR: file was not opened\n");
        return false;

    }
    fwrite(onegin_data->file_onegin_buffer, sizeof(char), onegin_data->file_lenth, onegin_data->file_onegin);
    return true;
}

void file_output_console(onegin_files_data * onegin_data, line * array_of_ptrs){

    for(unsigned long long int i = 0; i<onegin_data->ptrs_to_str_len;i++){
        for(int j = 0; j<array_of_ptrs[i].ptrs_to_str_end - array_of_ptrs[i].ptrs_to_str+1; j++)
            DEBUG_PRINTF("%c", array_of_ptrs[i].ptrs_to_str[j]);
        //DEBUG_PRINTF("%c", '\n');
    }

    return;

}
