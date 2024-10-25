#include "Find_str_amount.h"

unsigned long long int find_str_amount(char* buffer, const unsigned long long int size){
    unsigned long long int count = 0;
    //DEBUG_PRINTF("\nStart\n");
    for(unsigned long long int i = 2; i< size; i++){
        //DEBUG_PRINTF("%c", buffer[i]);
        if(buffer[i] == '\n' && buffer[i-2] != '\n'){

            count++;
            //DEBUG_PRINTF("count = %d \n", count);

        }

    }
    //DEBUG_PRINTF("\nEnd\n");
    return count;

}
