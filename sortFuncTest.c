#include <stdio.h>
#include "sorting.h"

int main()
{
    int L[10] = {4,2,67,10,34,12,45,65,89,29};

    InsertSort(L, 10);

    for (int i = 0; i < 10; ++i)
        printf("%d ",L[i]);

    return 0;
}