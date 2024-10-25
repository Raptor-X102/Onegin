#include <stdio.h>
#include <TXLib.h>
#include "GetFileSize2.h"
#include "Create_buffer.h"
#include "Compare_Funcs.h"
#include "Quick_sort.h"


int main(){

    int arr[] = {'M', 'I', 'H', 'B', 'C', 'W', 'Y', 'A', 'B', 'A', 'T', 'W', 'T', 'T', 'B', 'I', 'F', 'L', 'W', 'T', 'O', 'W', 'I', 'H', 'I', 'B'};
    quick_sort(arr, 0, sizeof(arr)/sizeof(arr[0])-1, sizeof(int), Compare_int);
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) DEBUG_PRINTF("%d ", arr[i]);
}
