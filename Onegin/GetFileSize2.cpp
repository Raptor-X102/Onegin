#include "GetFileSize2.h"

uint64_t get_file_size(const char* filename){

    int descriptor = open( filename, O_RDONLY);

    if (descriptor != -1) {
        FILE *file = fdopen(descriptor, "rb");
        struct stat statistics = {};
        if (file) {

            fstat(descriptor, &statistics);
            fclose(file);
        }
        close(descriptor);
        return statistics.st_size;
    }
    fprintf(stderr, "In function 'Get_File_Size'\nERROR: file was not read\n");
    return 0;

}
