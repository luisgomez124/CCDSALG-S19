#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>

Record records[100000];
Record copy[100000];

int main()
{
    long startTime, endTime, executionTime;
    int i, n;
    FILE *fp;

    char path[500] = "data/1000.txt";

    fp = fopen(path, "r");
    fscanf(fp, "%d", &n);
    fclose(fp);

    readFile(records, path);

    // insertion sort
    for (i = 0; i < n; i++) copy[i] = records[i];
    startTime = currentTimeMillis();
    insertionSort(copy, n);
    endTime = currentTimeMillis();
    executionTime = endTime - startTime;
    printf("Insertion Sort: %ld ms\n", executionTime);

    // selection sort
    for (i = 0; i < n; i++) copy[i] = records[i];
    startTime = currentTimeMillis();
    selectionSort(copy, n);
    endTime = currentTimeMillis();
    executionTime = endTime - startTime;
    printf("Selection Sort: %ld ms\n", executionTime);

    // merge sort
    for (i = 0; i < n; i++) copy[i] = records[i];
    startTime = currentTimeMillis();
    mergeSort(copy, 0, n - 1);
    endTime = currentTimeMillis();
    executionTime = endTime - startTime;
    printf("Merge Sort: %ld ms\n", executionTime);

    // quick sort
    for (i = 0; i < n; i++) copy[i] = records[i];
    startTime = currentTimeMillis();
    quickSort(copy, 0, n - 1);
    endTime = currentTimeMillis();
    executionTime = endTime - startTime;
    printf("Quick Sort: %ld ms\n", executionTime);

    return 0;
}

