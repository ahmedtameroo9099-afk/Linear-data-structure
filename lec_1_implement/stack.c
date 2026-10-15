#include <stdio.h>
#include "stack.h"

void createStack(stack *s) {
    s->top = -1;
}

int isStackEmpty(stack s) {
    return s.top == -1;
}

int isStackFull(stack s) {
    return s.top == MAX-1;
}

void stackPush(stack *s, type newValue) {
    if (isStackFull(*s))
        printf("stack overflow\n");
    else
        s->stackType[++s->top] = newValue;
        printf("pushed\n");
}

void stackPop(stack *s) {
    if (isStackEmpty(*s))
        printf("stack underflow\n");
    else
        s->top--;
        printf("popped\n");
}