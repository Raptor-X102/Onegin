#include "Onegin_data_Ctor.h"

bool Onegin_data_Ctor(onegin_files_data* onegin_data, line ** array_of_ptrs) {

    onegin_data->file_lenth = get_file_size("C:\\Users\\mihai\\Documents\\VSCode\\Onegin\\Onegin.txt");
    onegin_data->file_onegin = fopen("C:\\Users\\mihai\\Documents\\VSCode\\Onegin\\Onegin.txt", "rb");
    if(!(onegin_data->file_lenth) || !(onegin_data->file_onegin)) {

        fprintf(stderr, "File 'Onegin.txt' was not opened or file lenth 0\n");
        return false;

    }
    if(!create_buffer(onegin_data->file_lenth, &onegin_data->file_onegin_buffer))
        return false;

    if(!fread(onegin_data->file_onegin_buffer, sizeof(char), onegin_data->file_lenth, onegin_data->file_onegin)) {

        fprintf(stderr, "File data was not read\n");
        return false;

    }
    if(fclose(onegin_data->file_onegin)) {

        fprintf(stderr, "File 'Onegin.txt' was not closed \n");
        return false;

    }
    if(!(onegin_data->file_onegin = fopen("C:\\Users\\mihai\\Documents\\VSCode\\Onegin\\Onegin_sorted.txt", "a+b"))) {

        fprintf(stderr, "File 'Onegin_sorted.txt' was not opened\n");
        return false;

    }
    if(!fill_ptr_arr(onegin_data, array_of_ptrs))
        return false;

    return true;

}
