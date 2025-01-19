#include <stdlib.h>
#include <stdio.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (queue->array == NULL) {
        printf("Memory allocation for queue array failed\n");
        free(queue);
        return NULL;
    }
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

int enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return -1;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = value;
    queue->size = queue->size + 1;
    printf("Enqueued value: %d\n", value);
    return 0;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    printf("Dequeued value: %d\n", value);
    return value;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    printf("Front: %d\n", queue->array[queue->front]);
    return 0;
}

int rear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    printf("Rear: %d\n", queue->array[queue->rear]);
    return 0;
}

void iterateQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: \n");
        for (int i = 0; i < queue->size; i++) {
            int index = (queue->front + i) % queue->capacity;
            printf("%d\n", queue->array[index]);
        }
    }
}

void freeQueue(struct Queue* queue) {
    if (queue != NULL) {
        if (queue->array != NULL) {
            free(queue->array);
        }
        free(queue);
    }
}

int main(void) {
    struct Queue* queue = createQueue(10);
    if (queue == NULL) {
        return -1;
    }

    enqueue(queue, 10);
    dequeue(queue);
    enqueue(queue, 20);
    dequeue(queue);
    enqueue(queue, 30);
    dequeue(queue);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    enqueue(queue, 50);
    iterateQueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    iterateQueue(queue);
    enqueue(queue, 10);
    enqueue(queue, 20);

    front(queue);
    rear(queue);


    freeQueue(queue);

    return 0;
}