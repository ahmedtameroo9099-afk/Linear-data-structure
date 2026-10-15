#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DlinkedList.h"
#define MAX 32

void createDlist(doubleList *dl) {
    dl->head = NULL;
    size = 0;
}

bool isDlistEmpty(doubleList dl) {
    return dl.head == NULL;
}

bool isDlistFull(doubleList dl) {
    return size >= MAX; 
}

void insertItem(doubleList *dl, data item) {
    node *p = (node *)(malloc(sizeof(node)));
    p->info = item;
    if (size == 0) {
        p->previous = NULL;
        dl->head = p;
    }
    else {
        node *q = dl->head;
        while (q->next != NULL)
            q = q->next;
        p->next = q->next;
        q->next->previous = p;
        q->next = p;
        p->previous = q;
    }
    size++;
}

void removeItem(doubleList *dl, int key) {
    node *q = dl->head;
    for (int i = 0; i < key-1;i++) {
        q = q->next;
    }
    node *temp;
    temp = q->next;
    q->next = temp->next;
    q->next->previous = q;
    free(temp);
    size--;
}

void clearSlist(doubleList *dl) {
    node *q = dl->head;
    while (q) {
        node *next = q->next;                    // save before freeing
        free(q);
        q = next;
    }
    dl->head = NULL;
    size = 0;
}


