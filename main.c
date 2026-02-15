#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>

void copyRecords(Record *dst, Record *src, int n)
{
    int i;
    for (i = 0; i < n; i++)
        dst[i] = src[i];
}

int main()
{
    static Record original[MAX_RECORDS];
    static Record working[MAX_RECORDS];
    long startTime, endTime, executionTime;

    char *files[] = {
        "data/10.txt",
        "data/100.txt",
        "data/1000.txt",
        "data/10000.txt",
        "data/100000.txt"
    };
    int numFiles = 5;
    int f, n;

    for (f = 0; f < numFiles; f++)
    {
        FILE *fp = fopen(files[f], "r");
        if (!fp) { printf("Cannot open %s\n", files[f]); continue; }
        fscanf(fp, "%d", &n);
        fclose(fp);

        readFile(original, files[f]);
        printf("\n--- %s (n=%d) ---\n", files[f], n);

        copyRecords(working, original, n);
        startTime = currentTimeMillis();
        insertionSort(working, n);
        endTime = currentTimeMillis();
        executionTime = endTime - startTime;
        printf("Insertion Sort: %ld ms\n", executionTime);

        copyRecords(working, original, n);
        startTime = currentTimeMillis();
        selectionSort(working, n);
        endTime = currentTimeMillis();
        executionTime = endTime - startTime;
        printf("Selection Sort: %ld ms\n", executionTime);

        copyRecords(working, original, n);
        startTime = currentTimeMillis();
        mergeSort(working, 0, n - 1);
        endTime = currentTimeMillis();
        executionTime = endTime - startTime;
        printf("Merge Sort:     %ld ms\n", executionTime);

        copyRecords(working, original, n);
        startTime = currentTimeMillis();
        quickSort(working, 0, n - 1);
        endTime = currentTimeMillis();
        executionTime = endTime - startTime;
        printf("Quick Sort:     %ld ms\n", executionTime);
    }

    return 0;
}
