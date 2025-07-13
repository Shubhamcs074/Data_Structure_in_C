#include <stdio.h>

#define N 10
int count = 0;
int arr[N];

void linear_search(int key, int arr[]) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d.\n", key, i);
            count++;
            break;
        }
    }
    if (count == 0) {
        printf("Not found\n");
    }
}

int main() {
    printf("Enter %d Array Elements: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    linear_search(key, arr);

    return 0;
}
