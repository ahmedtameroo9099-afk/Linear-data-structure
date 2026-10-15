#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef int entryType;

typedef struct listNode {
    entryType entered;
    struct listNode *next;
}node;

typedef struct {
    node* head;
}listType;

#endif