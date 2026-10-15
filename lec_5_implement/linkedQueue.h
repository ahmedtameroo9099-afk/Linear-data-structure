#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef int listType;
typedef struct list {
    listType listItem;
    struct list *next;

}queue;

typedef struct {
    queue *head;
    int size;
}linkedQueue;

#endif