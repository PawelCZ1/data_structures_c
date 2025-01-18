#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned size;
    int* array;
};

struct Stack* createStack(unsigned size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    stack->size = size;
    stack->top = -1;
    stack->array = (int*)malloc(stack->size * sizeof(int));
    if (stack->array == NULL) {
        printf("Memory allocation for stack array failed\n");
        free(stack);
        return NULL;
    }
    return stack;
}

void push(struct Stack* stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("Stack is full\n");
    } else {
        stack->array[++stack->top] = value;
        printf("\nValue pushed into the stack: %d\n", stack->array[stack->top]);
    }
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    printf("\nValue popped from the stack: %d\n", stack->array[stack->top]);
    return stack->array[stack->top--];
}

int peek(struct Stack* stack, int* value) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    *value = stack->array[stack->top];
    return 0;
}

int main(void) {
    struct Stack* stack = createStack(5);
    if (stack == NULL) {
        return -1;
    }

    int value;

    if (peek(stack, &value) == 0) {
        printf("Top value: %d\n", value);
    } else {
        printf("Failed to get top value\n");
    }

    push(stack, 10);

    if (peek(stack, &value) == 0) {
        printf("Top value: %d\n", value);
    } else {
        printf("Failed to get top value\n");
    }

    push(stack, 15);

    if (peek(stack, &value) == 0) {
        printf("Top value: %d\n", value);
    } else {
        printf("Failed to get top value\n");
    }

    value = pop(stack);

    if (peek(stack, &value) == 0) {
        printf("Top value: %d\n", value);
    } else {
        printf("Failed to get top value\n");
    }

    free(stack->array);
    free(stack);

    return 0;
}

