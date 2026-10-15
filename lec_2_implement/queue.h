#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MAX 128
typedef int queueType;
typedef struct {
    int head,tail,size;
    queueType entered[MAX];
}queue;

void createQueue (queue *q);
int checkQueueEmpty(queue q);
int checkQueueFull(queue q);
int enQueue(queue *q, queueType newValue);
int deQueue(queue *q, queueType *removedValue);

#endif