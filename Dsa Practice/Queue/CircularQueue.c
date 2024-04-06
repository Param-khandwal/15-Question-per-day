#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
    int size;
};

struct CircularQueue* createQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isFull(struct CircularQueue* queue) {
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1);
}

int isEmpty(struct CircularQueue* queue) {
    return queue->front == -1;
}

void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    queue->size++;
    printf("Enqueued %d to the queue.\n", value);
}

int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int removed = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    queue->size--;
    printf("Dequeued %d from the queue.\n", removed);
    return removed;
}

void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue->items[i]);
    }
    printf("%d\n", queue->items[i]);
}

int main() {
    struct CircularQueue* queue = createQueue();
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
