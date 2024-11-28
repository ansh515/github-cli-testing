#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void traverse(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) temp = temp->next;
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;
    struct Node *temp = *head, *prev = NULL;
    if (temp->data == key && temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data == key) {
        if (temp == *head) {
            struct Node* last = *head;
            while (last->next != *head) last = last->next;
            last->next = temp->next;
            *head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}
int search(struct Node* head, int key) {
    if (head == NULL) return -1;
    struct Node* temp = head;
    int position = 1;
    do {
        if (temp->data == key) return position;
        temp = temp->next;
        position++;
    } while (temp != head);
    return -1;
}
void update(struct Node* head, int oldData, int newData) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        if (temp->data == oldData) {
            temp->data = newData;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}
int main() {
    printf("Ansh\n230010150012\n");
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printf("Circular linked list after insertions:\n");
    traverse(head);
    deleteNode(&head, 20);
    printf("Circular linked list after deletion:\n");
    traverse(head);
    int position = search(head, 30);
    if (position != -1) {
        printf("Element 30 found at position %d\n", position);
    } else {
        printf("Element 30 not found\n");
    }
    update(head, 30, 50);
    printf("Circular linked list after updating 30 to 50:\n");
    traverse(head);

    return 0;
}
