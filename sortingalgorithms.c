#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include <stdlib.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

void swapRecords(Record *a, Record *b) 
{
    Record temp = *a;
    *a = *b;
    *b = temp;
}

void merge(Record *arr, int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    Record *left = (Record *)malloc(n1 * sizeof(Record));
    Record *right = (Record *)malloc(n2 * sizeof(Record));

    for (i = 0; i <  n1; i++) 
        left[i] = arr[p + i];
    for (j = 0; j <  n2; j++) 
        right[j] = arr[q + 1 + j];

    i = 0; 
    j = 0; 
    k = p;
    
    while (i < n1 && j < n2)
    {
        if (left[i].idNumber <= right[j].idNumber)
            arr[k++] = left[i++];
        else 
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2) 
        arr[k++] = right[j++];

    free(left);
    free(right);
}

int partition(Record *arr, int low, int high)
{
    int pivot = arr[high].idNumber;
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) 
    {
        if (arr[j].idNumber <= pivot)
        {
            i++;
            swapRecords(&arr[i], &arr[j]);
        }
    }
    swapRecords(&arr[i + 1], &arr[high]);
    return i + 1;
}

void insertionSort(Record *arr, int n)
{
    int i, j;
    Record key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].idNumber > key.idNumber)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }         
}

void selectionSort(Record *arr, int n)
{
    int i, j, minIdx;

    for (i = 0; i < n - 1; i++)
    {
        minIdx = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j].idNumber < arr[minIdx].idNumber)
                minIdx = j;
        }

        if (minIdx != i)
            swapRecords(&arr[i], &arr[minIdx]);
    }
}

void mergeSort(Record *arr, int p, int r)
{
    int q;

    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/

void quickSort(Record *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

#endif
