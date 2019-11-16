/* 常见排序算法及其实现 */

#include <stdio.h>
#include <stdlib.h>

/* 辅助函数 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* 快速排序 */
int Partition(int *, int, int);

void QuickSort(int L[], int low, int high) {
    if (low < high) {
        int pivot = Partition(L, low, high);
        /* 一趟排序，得到pivot并以此为界分割数列，然后分别递归调用 */

        QuickSort(L, low, pivot - 1);
        QuickSort(L, pivot + 1, high);
    }
}

/* 保证一次调用之后pivot左边的数均小于pivot右边的数 */
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


/* 归并排序 */
void merge(int [], int, int, int);

void MergeSort(int L[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        MergeSort(L, start, mid);
        MergeSort(L, mid + 1, end);

        merge(L, start, mid, end);
    }
}

/* 将两个有序数列合并成一个有序数列 */
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


/* 冒泡排序 */
void BubbleSort(int L[], int length) {
    int i, j;

    for (i = 0; i < length; ++i) {
        /* 每趟排序之后，将最大的数移动到末尾 */
        for (j = i; j < length; ++j) {
            if (L[j] > L[j + 1]) {
                swap(&L[j], &L[j + 1]);
            }
        }
    }
}


/* 插入排序 */
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


/* 简单选择排序 */
void SelectionSort(int L[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (L[j] < L[min])
                min = j;
        }
        /* 找到最小的数，并放到已排序部分的尾部 */
        swap(&L[i], &L[min]);
    }
}


/* 堆排序 */
void HeapAdjust(int [], int, int);

void HeapSort(int a[], int len) {
    //调整并建立初始大根堆
    for (int i = len / 2 - 1; i >= 0; i--)
        HeapAdjust(a, i, len);

    //首尾互换，调整子堆
    for (int i = len - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        HeapAdjust(a, 0, i);
    }
}

void HeapAdjust(int L[], int k, int len) {
    int rc = L[k];
    int i = 2 * k + 1;
    for (; i < len; i = 2 * i + 1) {
        //找到k的孩子中较大的一个
        if (i < len - 1 && L[i] < L[i + 1])
            i++;

        //若较大的孩子仍小于k，则无需进行调整
        if (rc >= L[i])
            break;

        //否则将较大孩子的值赋值给k，并令k等于i，向下重复检测
        L[k] = L[i];
        k = i;
    }
    L[k] = rc;
}
