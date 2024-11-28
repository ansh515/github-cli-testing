#include <stdio.h>
#define MAX 100
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};
void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}
int isFull(struct Queue* queue) {
    return queue->rear == MAX - 1;
}
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->arr[++queue->rear] = value;
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return queue->arr[queue->front];
}
int main() {
    struct Queue queue;
    printf("Ansh\n230010150012\n");
    initQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    printf("Front element is %d\n", peek(&queue));
    printf("%d dequeued from queue\n", dequeue(&queue));
    printf("%d dequeued from queue\n", dequeue(&queue));
    printf("Front element is %d\n", peek(&queue));
    return 0;
}
