#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) (*head)->prev = newNode;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != key) temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp == *head) *head = temp->next;
    free(temp);
}
int search(struct Node* head, int key) {
    int position = 1;
    while (head != NULL) {
        if (head->data == key) return position;
        head = head->next;
        position++;
    }
    return -1;
}
void update(struct Node* head, int oldData, int newData) {
    while (head != NULL) {
        if (head->data == oldData) {
            head->data = newData;
            return;
        }
        head = head->next;
    }
}
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printf("Ansh\n230010150012\n");
    printf("Doubly linked list after insertions:\n");
    traverse(head);
    deleteNode(&head, 20);
    printf("Doubly linked list after deletion:\n");
    traverse(head);
    int position = search(head, 30);
    if (position != -1) {
        printf("Element 30 found at position %d\n", position);
    } else {
        printf("Element 30 not found\n");
    }
    update(head, 30, 50);
    printf("Doubly linked list after updating 30 to 50:\n");
    traverse(head);
    return 0;
}
