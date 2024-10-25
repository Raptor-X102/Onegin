#include "Free.h"

void Free(int num_of_files, ...) {

    va_list valist;
    va_start(valist, num_of_files);
    for(int i = 0; i < num_of_files; i++){
        FILE * file = va_arg(valist, FILE*);
        if(file)
            free(file);

    }

}
