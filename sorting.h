/* Sorting Algorithm */

#include <stdio.h>
#include <stdlib.h>

/* A utility function to exchange the value of two pointers*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Quick Sort */
int Partition(int *, int, int);

void QuickSort(int L[], int low, int high) {
    if (low < high) {
        int pivot = Partition(L, low, high);

        QuickSort(L, low, pivot - 1);
        QuickSort(L, pivot + 1, high);
    }
}

/* Set the first element as the pivot,
 * ensure all elements before pivot
 * lesser than those after pivot */
int Partition(int L[], int low, int high) {
    int pivot = L[low];

    while (low < high) {
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


/* Merge Sort */
void merge(int [], int, int, int);

void MergeSort(int L[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        MergeSort(L, start, mid);
        MergeSort(L, mid + 1, end);

        merge(L, start, mid, end);
    }
}

/* Merge two sorted list into one */
void merge(int L[], int start, int mid, int end) {
    int La[mid - start + 1];
    int Lb[end - mid];

    for (int i = 0; i <= mid - start; ++i) {
        La[i] = L[i + start];
    }
    for (int j = 0; j <= end - mid - 1; ++j) {
        Lb[j] = L[j + mid + 1];
    }

    int m = 0;
    int n = 0;
    int k = start;

    while (m <= mid - start && n <= end - mid - 1) {
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


/* Bubble Sort*/
void BubbleSort(int L[], int length) {
    int i, j;

    for (i = 0; i < length; ++i) {
        for (j = i; j < length; ++j) {
            if (L[j] > L[j + 1]) {
                swap(&L[j], &L[j + 1]);
            }
        }
    }
}


/* Insert Sort */
void InsertSort(int L[], int length) {
    int i, j;

    for (i = 1; i < length; i++) {
        for (j = i; j > 0; j--) {
            if (L[j] < L[j - 1]) {
                swap(&L[j], &L[j - 1]);
            }
        }
    }
}


/* Selection Sort */
void SelectionSort(int L[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (L[j] < L[min])
                min = j;
        }
        swap(&L[i], &L[min]);
    }
}


/* Heap Sort */
void HeapAdjust(int [], int, int);

void HeapSort(int a[], int len) {
    /* Build initial heap */
    for (int i = len / 2 - 1; i >= 0; i--)
        HeapAdjust(a, i, len);

    /* Since the top of the heap is the maximum one, exchange it 
    with the last one, then adjust remaining heap */
    for (int i = len - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        HeapAdjust(a, 0, i);
    }
}

void HeapAdjust(int L[], int k, int len) {
    int rc = L[k];
    int i = 2 * k + 1;
    for (; i < len; i = 2 * i + 1) {
        /* Find the bigger child of k */
        if (i < len - 1 && L[i] < L[i + 1])
            i++;

        /* If the bigger one is less than k, then break */
        if (rc >= L[i])
            break;

        L[k] = L[i];
        k = i;
    }
    L[k] = rc;
}
