#ifndef SORT_FUNCS
#define SORT_FUNCS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Compare_Funcs.h"
#include "Swap.h"
#include "DEBUG_PRINTF.h"

void quick_sort( void * arr, unsigned long long int start, unsigned long long int end,
                 size_t el_size, int(* compare_func) (const void * el1, const void * el));
const size_t Pivot_Buffer_Size = 256;
static char* Pivot = (char*) calloc(Pivot_Buffer_Size, sizeof(char));

#endif
