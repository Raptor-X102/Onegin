#include "Create_buffer.h"

bool create_buffer(const unsigned long long int size, char** buffer){

    if((*buffer = (char*) calloc(size+2, sizeof(char))) != NULL){

        return true;

    }
    fprintf(stderr, "In function 'Create_buffer'\nERROR: memory was not allocated!\n");
    return false;

}
