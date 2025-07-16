#include <stdio.h>

void insertionSort(int arr[], int n){
    int j, i, temp;
    for (i = 1; i <n; i++){
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j]> temp){
            arr[j+1] = arr[j];
            j--;
        } 
        arr[j+1] = temp;
    }
}



int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
