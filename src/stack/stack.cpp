#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

#define nullptr NULL

node* new_node(int value) {
    node* _new_node = (node*)malloc(sizeof(node));
    
    if (_new_node != nullptr) {
        _new_node->value = value;
        _new_node->next = nullptr;

        return _new_node;
    }

    return nullptr;
}

void push(node **stack, int value) {
    if (*stack == nullptr) {
        *stack = new_node(value);
        return;
    } else {
        node* aux = new_node(value);
        aux->next = *stack;
        *stack = aux;
    }
}

node* pop(node **stack) {
    if (*stack == nullptr)
        return nullptr;

    node* aux = *stack;
    *stack = aux->next;

    aux->next = nullptr;
    return aux;
}

node* peek(node *stack) {
    if (stack == nullptr) 
        return nullptr;

    node* last = stack;
    last->next = nullptr;
    return last;
}

bool is_empty(node *stack) {
    return (stack == nullptr);
}

int size(node *stack) {
    int _size = 0;
    node* aux_stack = stack;

    while (!is_empty(aux_stack)) {
        _size++;
        pop(&aux_stack);
    } 

    return _size;
}





