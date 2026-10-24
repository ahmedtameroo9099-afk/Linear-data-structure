#include <stdio.h>
#include <stdbool.h>
#include "header.h"

void createStack(brackets *b) {
    b->top = -1;
};

bool isStackEmpty(brackets b) {
    return b.top == -1;
}

bool isStackFull(brackets b) {
    return b.top == MAX-1;
}

bool stackPush(brackets *b, type newValue) {
    if (isStackFull(*b))
        return false;
    else {
        b->stackType[++b->top] = newValue;
        return true;
    }
}

bool stackPop(brackets *b) {
    if (isStackEmpty(*b))
        return false;
    else {
        b->top--;
        return true;
    }
}

bool isOpen(brackets *b, type inserted) {
    if (inserted == '(' || inserted == '[' || inserted == '{')
        return stackPush(b, inserted);   /* false if the stack is full */
    return true;                         /* not an opening bracket: nothing to do */
}

bool isClosed(brackets *b, type inserted) {
    if (inserted != ')' && inserted != ']' && inserted != '}')
        return true;                     /* not a closing bracket: nothing to do */

    if (isStackEmpty(*b))
        return false;                    /* nothing to match */

    if ((b->stackType[b->top] == '(' && inserted == ')') ||
        (b->stackType[b->top] == '[' && inserted == ']') ||
        (b->stackType[b->top] == '{' && inserted == '}')) {
        stackPop(b);
        return true;
    }
    return false;                        /* wrong type of bracket */
}

bool isBalanced(const char *s) {
    brackets b;
    createStack(&b);

    for (int i = 0; s[i] != '\0'; i++) {
        if (!isOpen(&b, s[i]))   return false;
        if (!isClosed(&b, s[i])) return false;
    }
    return isStackEmpty(b);              /* leftover openers = unbalanced */
}