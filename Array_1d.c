#include <stdio.h>
void traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insert(int arr[], int *size, int element, int position) {
    for (int i = *size; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    (*size)++;
}
void delete(int arr[], int *size, int position) {
    for (int i = position - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
int search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i + 1;
        }
    }
    return -1;
}
void update(int arr[], int size, int element, int position) {
    if (position >= 1 && position <= size) {
        arr[position - 1] = element;
    }
}
int main() {
    printf("Ansh\n230010150012\n");
    int arr[100], size = 0;
    insert(arr, &size, 10, 1);
    insert(arr, &size, 20, 2);
    insert(arr, &size, 30, 3);
    insert(arr, &size, 40, 4);
    printf("Array after insertions:\n");
    traverse(arr, size);
    delete(arr, &size, 2);
    printf("Array after deletion:\n");
    traverse(arr, size);
    int position = search(arr, size, 30);
    if (position != -1) {
        printf("Element 30 found at position %d\n", position);
    } else {
        printf("Element 30 not found\n");
    }
    update(arr, size, 50, 2);
    printf("Array after updating position 2 to 50:\n");
    traverse(arr, size);
    return 0;
}