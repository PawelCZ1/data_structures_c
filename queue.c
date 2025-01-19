#include <stdlib.h>
#include <stdio.h>

struct Queue {
  int size;
  unsigned capacity;
  int *array;
};

struct Queue* createQueue(unsigned capacity) {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  if (queue == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }
  queue->capacity = capacity;
  queue->size = 0;
  queue->array = (int*)malloc(queue->capacity * sizeof(int));
  if (queue->array == NULL) {
    printf("Memory allocation for queue array failed\n");
    free(queue);
    return NULL;
  }
  return queue;
}

int isFull(struct Queue* queue) {
  return queue->size == queue->capacity;
}

int isEmpty(struct Queue* queue) {
  return (queue->size == 0);
}

int enqueue(struct Queue* queue, int value) {
   if (isFull(queue)) {
     printf("Queue is full\n");
     return -1;
   }
   queue->array[queue->size++] = value;
   printf("Enqueued value: %d\n", value);
   return 0;
}

int dequeue(struct Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return -1;
  }

  int value = queue->array[0];

  for (int i = 0; i != queue->size - 1; i++) {
    queue->array[i] = queue->array[i + 1];
  }
  queue->size--;

  printf("Dequeued value: %d\n", value);
  return 0;
}

void showFirst(struct Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
  } else {
    int value = queue->array[0];
    printf("First value: %d\n", value);
  }
}

void showLast(struct Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
  } else {
    int value = queue->array[queue->size - 1];
    printf("Last value: %d\n", value);
  }
}

void iterateQueue(struct Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
  } else {
    printf("Queue: \n");
    for (int i = 0; i != queue->size; i++) {
      int value = queue->array[i];
      printf("%d\n", value);
    }
  }
}

int main(void) {
  struct Queue* queue = createQueue(10);
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);

  iterateQueue(queue);

  dequeue(queue);

  showFirst(queue);
  showLast(queue);

  dequeue(queue);
  dequeue(queue);
  showFirst(queue);
  showLast(queue);
  dequeue(queue);
  dequeue(queue);

  iterateQueue(queue);

  free(queue->array);
  free(queue);
  return 0;
}