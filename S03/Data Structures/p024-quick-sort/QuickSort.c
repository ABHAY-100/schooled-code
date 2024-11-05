#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int first, int last)
{
    int pivot = arr[last];
    int i = first - 1;

    for (int j = first; j < last; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[last]);
    return i + 1;
}

void quickSort(int arr[], int first, int last)
{
    if (first < last)
    {
        int pivotIndex = partition(arr, first, last);

        quickSort(arr, first, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, last);
    }
}

int main()
{
    int arr[50], n, i;

    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
