
#include <stdio.h>
#include <stdlib.h>

int* selectionSort(int arr[], int n, int* maxElement) {
    int i, j, minIndex, temp;

    *maxElement = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] > *maxElement) {
            *maxElement = arr[i];
        }
    }

    int* swaps = (int*)calloc(*maxElement + 1, sizeof(int));

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            swaps[arr[i]]++;
            swaps[arr[minIndex]]++;
        }
    }

    return swaps;
}

int* bubbleSort(int arr[], int n, int* maxElement) {
    int i, j, temp;

    *maxElement = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] > *maxElement) {
            *maxElement = arr[i];
        }
    }

    int* swaps = (int*)calloc(*maxElement + 1, sizeof(int));

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
            }
        }
    }

    return swaps;
}

void printSwaps(int swaps[], int n) {
    for (int i = 0; i < n; i++) {
        if (swaps[i] > 0) {
            printf("%d: %d\n", i, swaps[i]);
        }
    }
}

void runSelectionSortProgram() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    int maxElement1, maxElement2;

    int* selectionSwaps1 = selectionSort(array1, n1, &maxElement1);
    printf("array1 selection sort:\n");
    printSwaps(selectionSwaps1, maxElement1 + 1);
    int totalSelectionSwaps1 = 0;
    for (int i = 0; i <= maxElement1; i++) {
        totalSelectionSwaps1 += selectionSwaps1[i];
    }
    totalSelectionSwaps1 /= 2;
    printf("Total: %d\n\n", totalSelectionSwaps1);

    int* selectionSwaps2 = selectionSort(array2, n2, &maxElement2);
    printf("array2 selection sort:\n");
    printSwaps(selectionSwaps2, maxElement2 + 1);
    int totalSelectionSwaps2 = 0;
    for (int i = 0; i <= maxElement2; i++) {
        totalSelectionSwaps2 += selectionSwaps2[i];
    }
    totalSelectionSwaps2 /= 2;
    printf("Total: %d\n\n", totalSelectionSwaps2);

    free(selectionSwaps1);
    free(selectionSwaps2);
}

void runBubbleSortProgram() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    int maxElement1, maxElement2;

    int* swaps1 = bubbleSort(array1, n1, &maxElement1);
    printf("array1 bubble sort:\n");
    printSwaps(swaps1, maxElement1 + 1);
    int totalSwaps1 = 0;
    for (int i = 0; i <= maxElement1; i++) {
        totalSwaps1 += swaps1[i];
    }
    totalSwaps1 /= 2;
    printf("Total: %d\n\n", totalSwaps1);

    int* swaps2 = bubbleSort(array2, n2, &maxElement2);
    printf("array2 bubble sort:\n");
    printSwaps(swaps2, maxElement2 + 1);
    int totalSwaps2 = 0;
    for (int i = 0; i <= maxElement2; i++) {
        totalSwaps2 += swaps2[i];
    }
    totalSwaps2 /= 2;
    printf("Total: %d\n\n", totalSwaps2);

    free(swaps1);
    free(swaps2);
}

int main() {
    runSelectionSortProgram();
    runBubbleSortProgram();

    return 0;
}
