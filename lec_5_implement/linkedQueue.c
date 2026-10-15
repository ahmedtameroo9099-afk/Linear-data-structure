#include <stdio.h>
#include <stdlib.h>
#include "linkedQueue.h"
#define MAX 32

void createLqueue(linkedQueue *lq) {
    lq->head = NULL;
    lq->size = 0;
}

int isLqueueEmpty(linkedQueue *lq) {
    return lq->head == NULL;
}

int isLqueueFull(linkedQueue *lq) {
    return lq->size >= MAX; 
}

void insertItem(linkedQueue *lq,listType item) {
    if(isLqueueFull(lq)) {
        printf("above the located memory");
        return;
    }
    else {
        queue *p = (queue*)(malloc(sizeof(queue)));
        p->listItem = item;
        queue *q; q = lq->head;
        for(int i = 0;i < lq->size -1;i++) {
            q = q->next;
        }
        q->next = p;
        lq->size ++;
    }
}

void retreiveLqueue(linkedQueue *lq) {
    if(isLqueueEmpty(lq)) {
        printf("this is a downflow");
        return;
    }
    else{
        queue *tmp; tmp = lq->head;
        lq->head = tmp->next;
        free(tmp);
        lq->size --;
    }
}

void clearLqueue(linkedQueue *lq) {
    while (lq->head) {
        queue *tmp = lq->head;
        lq->head = tmp->next;
        free(tmp);
    }
    lq->size = 0;
}