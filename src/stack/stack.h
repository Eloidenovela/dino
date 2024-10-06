// #ifdef STACK_H
// #define STACK_H
#pragma once

#include <stdbool.h>

typedef struct node {
    int value;
    struct node* next;
} node;

node* new_node(int value);
bool push(node** stack, int value);
node* pop(node** stack);
node* peek(node* stack);
bool is_empty(node* stack);
int size(node* stack);

// #endif