#include <stdio.h>


int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while(left <= right) {
        int mid = (left + right)/2;

        if(arr[mid] == key)
           return mid;
        
        if(arr[mid] < key)
           left = mid + 1;

        else
           right = mid - 1;
    }

    return -1;
}

int main() {
    int arr[100], n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}