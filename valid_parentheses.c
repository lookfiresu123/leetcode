/*
 * created by lookfiresu123 at 2015/07/30
 */


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define STACK_SIZE 1000
#define STACK_TYPE char

static STACK_TYPE stack[STACK_SIZE];//the array to carry the stack
static int top_element = -1;//the top point of the stack

int is_empty(void) {
    int result = (top_element == -1 ? 1 : 0);
    return result;
}

int is_full(void) {
    int result = (top_element == STACK_SIZE - 1 ? 1 : 0);
    return result;
}

/* push one element to the stack */
void push(STACK_TYPE new_element) {
    //assert(!is_full());//judge whether the stack is not full
    top_element++;
    stack[top_element] = new_element;
}

STACK_TYPE pop(void) {
    //assert(!is_empty());//judge whether the stack is not empty
    STACK_TYPE result = stack[top_element];
    top_element--;
    return result;
}

int is_pair(STACK_TYPE x,STACK_TYPE y) {
    int flag = 0;
    if((x == '[' && y == ']') || (x == ']' && y == '['))
        flag = 1;
    else if((x == '{' && y == '}') || (x == '}' && y == '{'))
        flag = 1;
    else if((x == '(' && y == ')') || (x == ')' && y == '('))
        flag = 1;
    return flag;
}

bool isValid(char* s) {
    STACK_TYPE temp;
    while(*s != '\0') {
        if(is_empty() == 1) {
            push(*s);
            s++;
        }
        else{
            temp = pop();
            if(is_pair(*s,temp))
                s++;
            else{
                push(temp);
                push(*s);
                s++;
            }
        }
    }
    /* judge whether the stack is empty, if it is empty,then result is true, otherwise the result is false */
    if(is_empty() == 1)
        return true;
    else
        return false;
}

int main(void) {
    char *s = "]";
    bool result = true;
    result = isValid(s);
    return 0;
}
