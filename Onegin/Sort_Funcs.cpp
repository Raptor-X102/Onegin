#include "Sort_Funcs.h"


void Sort_beginnigs(char** first_ptr_to_ptr, unsigned long long int size_of_ptrs_arr){

    for(unsigned long long int i = 0; i<size_of_ptrs_arr-1; i++){

        for(unsigned long long int j = 0; j < size_of_ptrs_arr - i - 1; j++){

            for(size_t k1 = 0, k2 = 0; first_ptr_to_ptr[j][k1] != '\n' && first_ptr_to_ptr[j+1][k2] != '\n';){

                if(!isalpha(first_ptr_to_ptr[j][k1])){
                    k1++;
                    continue;
                }
                if(!isalpha(first_ptr_to_ptr[j+1][k2])){
                    k2++;
                    continue;
                }
                int delta = toupper(first_ptr_to_ptr[j][k1]) - toupper(first_ptr_to_ptr[j+1][k2]);
                if(delta>0){

                    char* tmp = first_ptr_to_ptr[j];
                    first_ptr_to_ptr[j] = first_ptr_to_ptr[j+1];
                    first_ptr_to_ptr[j+1] = tmp;
                    break;

                }
                if(delta<0){

                    break;

                }
                k1++;
                k2++;

            }

        }

    }

}
void Sort_endings(char** first_ptr_to_ptr, unsigned long long int size_of_ptrs_arr){

    for(unsigned long long int i = 0; i<size_of_ptrs_arr-1; i++){

        for(unsigned long long int j = 0; j < size_of_ptrs_arr - i - 1; j++){

            for(long int k1 = str_len(first_ptr_to_ptr[j]), k2 = str_len(first_ptr_to_ptr[j+1]); k1>= 0 && k2>=0;){

                if(!isalpha(first_ptr_to_ptr[j][k1])){
                    k1--;
                    continue;
                }
                if(!isalpha(first_ptr_to_ptr[j+1][k2])){
                    k2--;
                    continue;
                }
                int delta = toupper(first_ptr_to_ptr[j][k1]) - toupper(first_ptr_to_ptr[j+1][k2]);
                if(delta>0){

                    char* tmp = first_ptr_to_ptr[j];
                    first_ptr_to_ptr[j] = first_ptr_to_ptr[j+1];
                    first_ptr_to_ptr[j+1] = tmp;
                    break;

                }
                if(delta<0){

                    break;

                }
                k1--;
                k2--;

            }

        }

    }

}

