#include "Compare_Funcs.h"

int Compare_Strings_beg (const void* str1, const void* str2){
    const char* real_str1 = * (const char**) str1;
    const char* real_str2 = * (const char**) str2;

    for(long int k1 = 0, k2 = 0; real_str1[k1] != '\n' && real_str2[k2] != '\n';){

        if(!isalpha(real_str1[k1])){
            k1++;
            continue;
        }
        if(!isalpha(real_str2[k2])){
            k2++;
            continue;
        }
        if(int delta = toupper(real_str1[k1]) - toupper(real_str2[k2])){

            return delta;

        }

        k1++;
        k2++;

    }
    return 0;

}

int Compare_Strings_end (const void* str1, const void* str2){
    const char* real_str1 = * (const char**) str1;
    const char* real_str2 = * (const char**) str2;
    if(real_str1[0] == '\n' || real_str2[0] == '\n') return -1;
    for(long int k1 = str_len(real_str1), k2 = str_len(real_str2); k1>= 0 && k2>=0;){

        if(!isalpha(real_str1[k1])){
            k1--;
            continue;
        }
        if(!isalpha(real_str2[k2])){
            k2--;
            continue;
        }
        if(int delta = toupper(real_str1[k1]) - toupper(real_str2[k2])){
            //DEBUG_PRINTF("delta = %d", delta);
            return delta;

        }

        k1--;
        k2--;

    }

    return 0;

}

int Compare_int(const void* int1, const void* int2){

    return -(*(int*)int1 - *(int*)int2);

}

int Compare_Structs_beg (const void* str1, const void* str2){
    const line real_str1 = * (line*) str1;
    const line real_str2 = * (line*) str2;
    if(real_str1.ptrs_to_str[0] == '\r' || real_str2.ptrs_to_str[0] == '\r') return -1;
    for(long int k1 = 0, k2 = 0; real_str1.ptrs_to_str[k1] != '\n' && real_str2.ptrs_to_str[k2] != '\n';){

        if(!isalpha(real_str1.ptrs_to_str[k1])){
            k1++;
            continue;
        }
        if(!isalpha(real_str2.ptrs_to_str[k2])){
            k2++;
            continue;
        }
        if(int delta = toupper(real_str1.ptrs_to_str[k1]) - toupper(real_str2.ptrs_to_str[k2])){
            //DEBUG_PRINTF("delta = %d", delta);
            return delta;

        }

        k1++;
        k2++;

    }

    return 0;

}

int Compare_Structs_end (const void* str1, const void* str2){
    const line real_str1 = * (line*) str1;
    const line real_str2 = * (line*) str2;

    for(long int k1 = real_str1.ptrs_to_str_end-real_str1.ptrs_to_str,
                 k2 = real_str2.ptrs_to_str_end-real_str2.ptrs_to_str;
                 k1>= 0 && k2>=0;)
    {

        if(!isalpha(real_str1.ptrs_to_str[k1])){
            k1--;
            continue;
        }
        if(!isalpha(real_str2.ptrs_to_str[k2])){
            k2--;
            continue;
        }
        if(int delta = toupper(real_str1.ptrs_to_str[k1]) - toupper(real_str2.ptrs_to_str[k2])){
            //DEBUG_PRINTF("delta = %d", delta);
            return delta;

        }

        k1--;
        k2--;

    }

    return 0;

}

