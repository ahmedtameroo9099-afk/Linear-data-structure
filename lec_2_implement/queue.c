#include <stdio.h>
#include "queue.h"

void createQueue(queue *q) {
    q->head = 0;
    q->tail = MAX - 1;
    q->size = 0;
}

int checkQueueEmpty(queue q) {
    return q.size == 0;
}

int checkQueueFull(queue q) {
    return q.size == MAX;
}

int enQueue(queue *q, queueType newValue) {
    if (checkQueueFull(*q)) {
        printf("queue is full\n");
        return 0;               // failure
    }
    q->tail = (q->tail + 1) % MAX;
    q->entered[q->tail] = newValue;   // write the value
    q->size++;
    return 1;                   // success
}

int deQueue(queue *q, queueType *removedValue) {
    if (checkQueueEmpty(*q)) {
        printf("queue is empty\n");
        return 0;               // failure
    }
    *removedValue = q->entered[q->head];
    q->head = (q->head + 1) % MAX;
    q->size--;
    return 1;                   // success
}
