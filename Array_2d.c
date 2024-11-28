#include <stdio.h>
void traverse(int arr[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void insert(int arr[10][10], int *rows, int *cols, int element, int row, int col) {
    if (row <= *rows && col <= *cols) {
        arr[row - 1][col - 1] = element;
    }
}
void delete(int arr[10][10], int *rows, int *cols, int row, int col) {
    if (row <= *rows && col <= *cols) {
        arr[row - 1][col - 1] = 0;
    }
}
int search(int arr[10][10], int rows, int cols, int element) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == element) {
                return 1;
            }
        }
    }
    return 0;
}
void update(int arr[10][10], int rows, int cols, int element, int row, int col) {
    if (row <= rows && col <= cols) {
        arr[row - 1][col - 1] = element;
    }
}
int main() {
    printf("Ansh\n230010150012\n");
    int arr[10][10] = {0};
    int rows = 3, cols = 3;
    insert(arr, &rows, &cols, 10, 1, 1);
    insert(arr, &rows, &cols, 20, 1, 2);
    insert(arr, &rows, &cols, 30, 1, 3);
    insert(arr, &rows, &cols, 40, 2, 1);
    printf("Array after insertions:\n");
    traverse(arr, rows, cols);
    delete(arr, &rows, &cols, 1, 2);
    printf("Array after deletion:\n");
    traverse(arr, rows, cols);
    if (search(arr, rows, cols, 30)) {
        printf("Element 30 found\n");
    } else {
        printf("Element 30 not found\n");
    }
    update(arr, rows, cols, 50, 2, 2);
    printf("Array after updating position (2, 2) to 50:\n");
    traverse(arr, rows, cols);
    return 0;
}
