#include <stdio.h>
#include "sorting.h"

int main()
{
    int L[11] = {0,2,87,39,49,34,62,53,6,44,98};


    HeapSort(L, 11);

    for (int i = 0; i < 11; ++i) {
        printf("%d ",L[i]);
    }
    return 0;
}