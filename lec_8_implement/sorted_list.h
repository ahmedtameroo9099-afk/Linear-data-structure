#ifndef SORTEDLIST_H_INCLUDED
#define SORTEDLIST_H_INCLUDED

typedef char myType;

typedef struct {
    int key;
    myType data;
}container;

typedef struct list {
    container info; //instead of list item
    struct list *next; //2 ptr's
    struct list *prev;
}node;

typedef struct {
    node *head;
}sortedList;

#endif