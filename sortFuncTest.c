#include <stdio.h>
#include "sorting.h"

int main()
{
    int L[10] = {10,2,4,67,34,12,45,65,89,29};

    mergesort(L, 0, 9);

    for (int i = 0; i < 10; ++i)
        printf("%d ",L[i]);

    return 0;
}