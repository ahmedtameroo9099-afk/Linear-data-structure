#include <stdio.h>
#include "stack.h"
#include "stack.c"

int main() {
    stack s;
    createStack(&s);
    stackPush(&s,1);
    stackPush(&s,2);
    stackPush(&s,3);
    stackPop(&s);
    stackPush(&s,4);
}