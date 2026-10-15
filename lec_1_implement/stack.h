#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAX 32
typedef int type;

typedef struct {
    int top;
    type stackType[MAX];
} stack;

void createStack(stack *s);
int  isStackEmpty(stack s);
int  isStackFull(stack s);
void stackPush(stack *s, type newValue);
void stackPop(stack *s);

#endif