#include <stdio.h>


void bubbleSort(int arr[], int n, int swaps[]) {
    int temp, totalSwaps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

               
                swaps[arr[j]]++;
                totalSwaps++;
            }
        }
    }

    
    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swaps[arr[i]]);
    }

    printf("Total # of swaps: %d\n\n", totalSwaps);
}


void selectionSort(int arr[], int n, int swaps[]) {
    int temp, min_idx, totalSwaps = 0;

    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
           
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;

       
        swaps[arr[i]]++;
        totalSwaps++;
    }

    
    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swaps[arr[i]]);
    }

    printf("Total # of swaps: %d\n\n", totalSwaps);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    
    int swaps1[100] = {0};
    int swaps2[100] = {0};

    printf("array1:\n");
    bubbleSort(array1, n1, swaps1);

    printf("array2:\n");
    selectionSort(array2, n2, swaps2);

    return 0;
}
