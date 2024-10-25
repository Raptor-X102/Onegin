#include "Str_len.h"

int str_len(const char* const str){
    int count = 0;
    //DEBUG_PRINTF("%p ", str);

    for(;str[count] != '\n';count++);

    if(str[count+1] == EOF)
        count++;
    //DEBUG_PRINTF(" %d\n", count);
    return count;
}
