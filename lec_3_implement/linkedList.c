#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

void listCreate(listType *l) {
    l->head = NULL;
}

int isListEmpty(listType *l) {
    return l->head == NULL;
}

int isListFull(listType *l) {
    return 0;
}

void insertItem(listType *l, entryType item,int pos) {
    node *p = (node *)(malloc(sizeof(node)));
    p->entered =item;
    if (pos == 0) {
        p->next = l->head;
        l->head = p;
    }
    else {
        node *q; q = l->head;
        for (int i = 0;i < pos -1;i++) {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
}

void removeItem (listType *l , int pos) {
    if (pos == 0) {
        node *tmp = l->head;
        l->head = l->head->next;
        free(tmp);
    }
    else {
        node *q; q = l->head;
        for (int i = 0;i < pos -1;i++) {
            q = q->next;
        }
        node *tmp;tmp = q->next;
        q->next = tmp->next;
        free(tmp);
    }
}

