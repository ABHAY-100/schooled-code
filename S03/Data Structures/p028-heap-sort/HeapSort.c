#include <stdio.h>

#define SIZE 50

void heapify(int arr[], int n, int i) {
    int temp, largest = i;

    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--) { 
        heapify(arr, n, i);
    }
    
    for (int i = n; i > 1; i--) { 
        int temp = arr[1]; 
        arr[1] = arr[i];   
        arr[i] = temp;     
        heapify(arr, i - 1, 1);
    }
}

int main() {
    int arr[SIZE], n;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 1; i <= n; i++) { 
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 1; i <= n; i++) { 
        printf("%d ", arr[i]);
    }

    return 0;
}