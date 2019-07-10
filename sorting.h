/* 常见排序算法及其实现 */

#include <stdio.h>
#include <stdlib.h>

/* 快速排序 */

int Partition(int *, int, int);

void QuickSort(int L[], int low, int high)
{
    if (low < high){
        int pivot = Partition(L, low, high);
        QuickSort(L, low, pivot-1);
        QuickSort(L, pivot+1, high);
    }
}

int Partition(int L[], int low, int high)
{
    int pivot = L[low];

    while(low < high)
    {
        while (L[high] >= pivot)
            high--;
        L[low] = L[high];

        while (low < high && L[low] <= pivot)
            low++;
        L[high] = L[low];
    }
    L[low] = pivot;

    return low;
}

/* 归并排序 */

void merge(int [], int, int, int);

void mergesort(int L[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergesort(L, start, mid);
        mergesort(L, mid + 1, end);

        merge(L, start, mid, end);
    }
}

void merge(int L[], int start, int mid, int end)
{
    int La[mid - start + 1];
    int Lb[end - mid];

    for (int i = 0; i <= mid - start; ++i) {
        La[i] = L[i + start];
    }
    for (int j = 0; j <= end - mid - 1 ; ++j) {
        Lb[j] = L[j + mid + 1];
    }

    int m = 0;
    int n = 0;
    int k = start;

    while (m <= mid - start && n <= end - mid - 1)
    {
        if (La[m] >= Lb[n])
            L[k++] = Lb[n++];
        else
            L[k++] = La[m++];
    }

    while (m <= mid - start)
        L[k++] = La[m++];

    while (n <= end - mid - 1)
        L[k++] = Lb[n++];
}