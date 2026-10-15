#include <stdio.h>
#include <stdlib.h>
#include "linkedStack.h"
#define MAX 32

void createLqueue(linkedStack *ls) {
    ls->head = NULL;
    ls->size = 0;
}

int isLqueueEmpty(linkedStack *ls) {
    return ls->head == NULL;
}

int isLstackFull(linkedStack *ls) {
    return ls->size >= MAX; 
}

void insertItem(linkedStack *ls,listType item) {
    if(isLstackFull(ls)) {
        printf("above the located memory");
        return;
    }
    else {
        Stack *p = (Stack *)(malloc(sizeof(Stack)));
        p->listItem = item;
        p->next = ls->head;
        ls->head = p;
        ls->size ++;
    }
}

void retreiveLstack(linkedStack *ls) {
    if(isLqueueEmpty(ls)) {
        printf("this is a downflow");
        return;
    }
    else {
        Stack *tmp;
        tmp = ls->head;
        ls->head = tmp->next;
        free(tmp);
        ls->size --;
    }
}

void clearLstack(linkedStack *ls) {
    for (ls->size;(ls->size) > 0;ls->size --) {
        Stack *tmp;
        tmp = ls->head;
        ls->head = tmp->next;
        free(tmp);
    }
}
/* or
void clearLstack(linkedStack *ls) {
    while (ls->head) {
        Stack *tmp = ls->head;
        ls->head = tmp->next;
        free(tmp);
    }
    ls->size = 0;
}
*/
