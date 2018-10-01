#include <stdio.h>

void print_array (int *arr, int sz);

void debug_steps (int *arr, int low, int high, int pivot) {
    static int step = 1;
    printf("\n-----\nDebug step: %d\n", step);
    print_array(arr, 10);
    printf("Low = %d    High = %d   Pivot = %d\n", low, high, pivot);
    step++;
}

void swap (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];

    int i = (low - 1), j;

    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort (int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void print_array (int *arr, int sz) {
    int i;
    printf("Array: [");
    for (i = 0; i < sz; i++) {
        printf("%d", arr[i]);

        if (i != (sz - 1))
            printf(", ");
    }
    printf("]\n");
}

int main () {
    int array[] = {10, 9, 8, 6, 7, 4, 5, 2, 1, 3};
    int sz = sizeof(array)/sizeof(int);
    //printf("\nPartition: %d\n", partition(array, 0, 9));

    print_array(array, sz);

    quicksort(array, 0, sz - 1);

    print_array(array, sz);

    return 0;
}