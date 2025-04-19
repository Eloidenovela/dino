#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
typedef struct node 
{
    int value;
    struct node* next; 
} node;

node* create_node(int value);

bool push_front(node **head, int value);
bool insert(node **head, int value, int x);
bool push_back(node** head, int value);

int pop_front(node** head);
int pop(node **head, int x);
int pop_back(node **head);

int size(node* head);
bool is_empty(node* head);
void print(node* head);

#endif