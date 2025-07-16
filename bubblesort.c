#include <stdio.h>

int flag;

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        flag = 0;
        for(int j = 0; j < n - 1 - i; j++){  // Optimization: avoid already sorted end part
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
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

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
