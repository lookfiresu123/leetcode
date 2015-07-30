/*
 * created by lookfiresu123 at 2015/07/30
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct {
    int *data;
    int maxSize;
    int top_element;
} MinStack;

int is_full(MinStack *stack) {
    return stack->top_element == stack->maxSize - 1;
}

int is_empty(MinStack *stack) {
    return stack->top_element == -1;
}

void push(MinStack *stack, int element) {
    assert(!is_full(stack));
    stack->top_element += 1;
    stack->data[stack->top_element] = element;
}

void pop(MinStack *stack) {
    assert(!is_empty(stack));
    stack->top_element -= 1;
}

int top(MinStack *stack) {
    assert(!is_empty(stack));
    return stack->data[stack->top_element];
}


void minStackCreate(MinStack *stack, int maxSize) {
    stack->data = (int *)malloc(maxSize * sizeof(int));
    stack->maxSize = maxSize;
    stack->top_element = -1;
}

/*
 * sort the element in the stack from max(%rbp) to min(%rsp)
 */
void minStackPush(MinStack *stack, int element) {
    /* create stack_temp to save some elements poped from stack because it is bigger than the argument element */
    MinStack *stack_temp = (MinStack *)malloc(sizeof(MinStack));
    minStackCreate(stack_temp,stack->maxSize);

    int temp;
    while(!is_empty(stack) && stack->data[stack->top_element] < element) {
        temp = top(stack);
        pop(stack);
        push(stack_temp,temp);
    }
    push(stack,element);
    while(!is_empty(stack_temp)) {
        temp = top(stack_temp);
        pop(stack_temp);
        push(stack,temp);
    }
    free(stack_temp->data);
    free(stack_temp);
}

void minStackPop(MinStack *stack) {
    pop(stack);
}

int minStackTop(MinStack *stack) {
    return top(stack);
}

int minStackGetMin(MinStack *stack) {
    return top(stack);
}

void minStackDestroy(MinStack *stack) {
    free(stack->data);
    free(stack);
}

int main(void) {
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    int maxSize = 5;
    minStackCreate(stack,maxSize);
    minStackPush(stack,-3);
    minStackPush(stack,7);
    minStackPush(stack,5);
    minStackPush(stack,2);
    minStackPush(stack,4);
    int min_stack = minStackGetMin(stack);
    return min_stack;
}


