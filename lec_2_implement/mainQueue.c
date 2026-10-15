#include <stdio.h>
#include "queue.h"
#include "queue.c"

int main(){
    queue q;
    createQueue(&q);
    enQueue(&q, 10);
    enQueue(&q, 20);
}