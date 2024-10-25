#include "Quick_sort.h"

void quick_sort( void * arr, unsigned long long int start, unsigned long long int end,
                 size_t el_size, int(* compare_func) (const void * el1, const void * el))
{
    long long int L = 0, R = 0;
    if ( start >= end ) return;
    L = start; R = end;
    DEBUG_PRINTF("Pivot = %p   arr = %p  ((char*)arr+((L+R)/2)*el_size) = %p  R = %d L = %d \n", Pivot , arr, ((char*)arr+((L+R)/2)*el_size), R, L);
    memcpy(Pivot, ((char*)arr+((L+R)/2)*el_size), el_size);

    while ( L <= R ) {
        while ( compare_func(((char*)arr+(L)*el_size) ,  Pivot) < 0 ) {
            L++;
            assert(L <= end);
            //DEBUG_PRINTF("\nR = %d\n", L);
        }
        while ( compare_func(((char*)arr+(R)*el_size) ,  Pivot) > 0 ) {
            R--;
            assert(R >=0);
            //DEBUG_PRINTF("\nR = %d\n", R);
        }
        if ( L <= R ) {
            Swap(((char*)arr+(L)*el_size), ((char*)arr+(R)*el_size), el_size);
            L ++; //DEBUG_PRINTF("\nR = %d\n", L);
            R --; //DEBUG_PRINTF("\nR = %d\n", R);

            assert(R>=0);
            assert(L <= end);
        }
    }
    quick_sort (arr, start, R, el_size, compare_func);
    quick_sort (arr, L, end, el_size, compare_func);
}
