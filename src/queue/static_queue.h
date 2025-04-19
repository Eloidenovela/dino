#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdbool.h>

#define MAX 100

typedef struct 
{
    int arr[MAX];
    int quantity;
} queue;


void initializer(queue *queue);
bool add(queue *queue, int element);
bool pop(queue *queue);

int back(const queue *queue);
int front(const queue *queue);

#endif