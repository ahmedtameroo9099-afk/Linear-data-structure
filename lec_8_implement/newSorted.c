#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sorted_list.h"
#define MAX 128

void createSlist(sortedList *sl) {
    sl->head = NULL;
    sl->head->info.key = 0;
}

bool isSlistEmpty(const sortedList *sl) {
    return sl->head == NULL;
}

bool isSlistFull (sortedList sl) {
    return sl.head->info.key >= MAX;
}

bool insertItem(sortedList *sl, container item) {

    node *p = malloc(sizeof(node));
    if (!p) return false;
    p->info = item;

    node *prev = NULL, *cur = sl->head;
    while (cur && cur->info.key < item.key) {   // stop at first bigger-or-equal key
        prev = cur;
        cur = cur->next;
    }

    p->prev = prev;
    p->next = cur;
    if (cur)  cur->prev = p;
    if (prev) prev->next = p;
    else      sl->head = p;                      // inserting at the front
    return true;
}

node *findItem(const sortedList *sl, int key) {
    for (node *q = sl->head; q && q->info.key <= key; q = q->next)
        if (q->info.key == key) return q;        // sorted, so we can stop early
    return NULL;
}

bool removeItem(sortedList *sl, int key) {
    node *q = findItem(sl, key);
    if (!q) return false;

    if (q->prev) q->prev->next = q->next;
    else         sl->head = q->next;             // removing the head
    if (q->next) q->next->prev = q->prev;

    free(q);
    return true;
}

void clearSlist(sortedList *sl) {
    node *q = sl->head;
    while (q) {
        node *next = q->next;                    // save before freeing
        free(q);
        q = next;
    }
    sl->head = NULL;
}