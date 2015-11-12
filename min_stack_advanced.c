#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    int index;
    struct NODE *next;
} Node;

typedef struct {
    int count;
    int maxSize;
    Node *head;
} MinStack;

void minStackCreate (MinStack *stack, int maxSize) {
    stack->count = 0;
    stack->maxSize = maxSize;
    stack->head = NULL;
}

void minStackPush (MinStack *stack, int element) {
    if (stack->count == stack->maxSize)     // full
        perror("the stack is full\n");
    else {
        stack->count += 1;
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = element;
        new_node->index = stack->count;
        new_node->next = NULL;

        Node *current = stack->head;
        Node *parent = NULL;
        while (current && current->data < new_node->data) {
            parent = current;
            current = current->next;
        }
        new_node->next = current;
        if (! parent)
            stack->head = new_node;
        else
            parent->next = new_node;
    }
}

void minStackPop (MinStack *stack) {
    // find the count index node and delete it
    if (stack->count == 0)
        perror("the stack is empty\n");
    else {
        Node *current = stack->head;
        Node *parent = NULL;
        while (current) {
            if (current->index == stack->count)
                break;
            parent = current;
            current = current->next;
        }
        if (! parent)
            stack->head = current->next;
        else
            parent->next = current->next;

        free(current);
        stack->count -= 1;
    }
}

int minStackTop (MinStack *stack) {
    if (stack->count == 0) {
        perror("the stack is empty\n");
        return -1;
    } else {
        Node *current = stack->head;
        while (current) {
            if (current->index == stack->count)
                return current->data;
            current = current->next;
        }
    }
}

int minStackGetMin (MinStack *stack) {
    if (stack->count == 0) {
        perror("the stack is empty\n");
        return -1;
    } else
        return stack->head->data;
}

void minStackDestroy (MinStack *stack) {
    if (stack->count == 0)
        free(stack);
}

int main(void) {
    MinStack stack;
    int maxSize = 1;
    minStackCreate(&stack,maxSize);
    minStackPush(&stack,-3);
    // minStackPush(stack,7);
    // minStackPush(stack,5);
    // minStackPush(stack,2);
    // minStackPush(stack,4);
    int min_stack = minStackGetMin(&stack);
    return min_stack;
}
