#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

typedef int listType;
typedef struct list {
    listType listItem;
    struct list *next;

}Stack;

typedef struct {
    Stack *head;
    int size;
}linkedStack;


#endif