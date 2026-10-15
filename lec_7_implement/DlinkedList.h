#ifndef DLINKEDLIST_H_INCLUDED
#define DLINKEDLIST_H_INCLUDED

typedef int data;
int size;
typedef struct list {
    data info; //instead of list item
    struct list *next; //2 ptr's
    struct list *previous;

}node;

typedef struct {
    node *head;
}doubleList;

#endif