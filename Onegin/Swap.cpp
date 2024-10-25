#include "Swap.h"

void Swap (void * el1, void * el2, size_t el_size){

    size_t tmp_el_size = el_size, curr_size = 8;
    while(tmp_el_size>0){

        while(tmp_el_size>=curr_size){

            int64_t tmp = 0;
            memcpy(&tmp,el1, curr_size);
            memcpy(el1,el2, curr_size);
            memcpy(el2, &tmp, curr_size);
            tmp_el_size -= curr_size;
            el1 += curr_size;
            el2 += curr_size;

        }
        curr_size /= 2;

    }

}
