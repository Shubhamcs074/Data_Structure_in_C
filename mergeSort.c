#include <stdio.h>

#define MAX 1000
int b[MAX];

void merge(int arr[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while(i <= mid && j <= ub){
        if(arr[i] <= arr[j]){
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }

    while(j <= ub) {
        b[k] = arr[j];
        j++;
        k++;
    }

    for(k = lb; k <= ub; k++) {
        arr[k] = b[k];
    }
}

void mergeSort(int arr[], int lb, int ub) {
    if(lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
