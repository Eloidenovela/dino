// #include "list/static_list.h"
// #include "queue/static_queue.h"
#include <stdio.h>
#include "list/linked_list/linked_list.h"

int main() 
{

    node* list = NULL;
    push_back(&list, 10);
    push_back(&list, 50);
    push_back(&list, 40);
    push_back(&list, 30);
    push_front(&list, 18);
    push_front(&list, 183);
    insert(&list, 255, 3);
    insert(&list, 245, 3);

    // pop_back(&list);
    // pop_back(&list);
    // pop_front(&list);
    // pop_front(&list);
    pop(&list, 3);



    print(list);
    // queue queue;
    // initializer(&queue);
    // add(&queue, 10);
    // add(&queue, 14);
    // add(&queue, 89);
    // add(&queue, 78);
    // add(&queue, 8);

    // while (queue.quantity != 0)
    // {
    //     printf("%i ", front(&queue));
    //     pop(&queue);
    // }
}