#include "static_queue.h"
#include <stdbool.h>

void initializer(queue *queue)
{
    queue->quantity = 0;
}

bool add(queue *queue, int element)
{
    if (queue->quantity >= 0)
    {
        queue->arr[queue->quantity] = element;
        queue->quantity++;
        return true;
    } return false;
}

bool pop(queue *queue)
{
    if (queue->quantity != 0)
    {
        queue->quantity--;
        return true;
    } return false;
}

int back(const queue *queue)
{
    return queue->arr[0];
}

int front(const queue *queue)
{
    return queue->arr[queue->quantity - 1];
}