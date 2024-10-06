#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

#define nullptr NULL

node* new_node(int value) {
    node* _new_node = (node*)malloc(sizeof(node));
    
    if (!is_empty(_new_node)) {
        _new_node->value = value;
        _new_node->next = nullptr;

        return _new_node;
    }

    return nullptr;
}

bool push(node **stack, int value) {
    if (is_empty( *stack)) {
        *stack = new_node(value);
        return true;
    } else {
        node* aux = new_node(value);
        aux->next = *stack;
        *stack = aux;
        return true;
    }

    return false;
}

node* pop(node **stack) {
    if (is_empty(*stack))
        return nullptr;

    node* aux = *stack;
    *stack = aux->next;

    return new_node(aux->value); // novo no com ultimo/primeiro valor, mas nao ligado aos outros no da pilha
}

node* peek(node *stack) {
    if (is_empty(stack)) 
        return nullptr;

    // node* last = stack;
    // last->next = nullptr;
    return new_node(stack->value); // novo no, nao ligado aos outros nos da pilha
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





