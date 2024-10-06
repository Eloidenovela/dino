#pragma once

typedef struct node {
    int value;
    struct node* next;
} node;

node* new_node(int value);
void push(node** queue, int value);
