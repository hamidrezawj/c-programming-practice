#include <stdio.h>

// Swap two numbers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Put the pivot in its correct position
int partition(int arr[], int low, int high)
{
    // Choose the last element as pivot
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        // If current number is smaller than pivot
        if (arr[j] < pivot)
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }

    // Put pivot after all smaller elements
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        // Sort left side
        quickSort(arr, low, pivotIndex - 1);

        // Sort right side
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Print array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(void)
{
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("After sorting:  ");
    printArray(arr, size);

    return 0;
}
