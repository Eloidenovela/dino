#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

node* create_node(int value)
{
    node* new = (node*) malloc(sizeof(node));
    if (new)
    {
        new->value = value;
        new->next = NULL;
        return new;
    }
    return NULL;
}

bool push_front(node **head, int value)
{
    node* new = create_node(value);
    if (new)
    {
        new->next = *head;
        *head = new;
        return true;
    } return false;
}

bool insert(node **head, int value, int x)
{
    if ((x >= 0) && (x <= size(*head)))
    {
        node* aux = *head;
        for (int i = 0; (i < x - 1) && !is_empty(aux); i++)
            aux = aux->next;
        if (aux)
        {
            node* new = create_node(value);
            if (new)
            {
                new->next = aux->next;
                aux->next = new;
                return true;
            }
        } 
    } return false;
}

bool push_back(node **head, int value)
{
    node* new = create_node(value);
    if (new)
    {
        if (!(*head))
        {
            *head = new;
            return true; 
        } else  
        {
            node *aux = *head;

            while (! is_empty(aux->next))
            {
                aux = aux->next;
            }
            aux->next = new;
            return true;
        }
    }

    return false;
}

int pop_front(node **head)
{
    if (*head)
    {
        node* aux = *head;
        int value = aux->value;
        aux = aux->next;
        *head = aux;
        return value;
    } return (-1);
}

int pop(node **head, int x)
{
    if ((x >= 0) && (x <= size(*head)))
    {
        node *aux = *head;
        for (int i = 0; (i < x - 1) && ! is_empty(aux); i++)
            aux = aux->next;
        if (aux->next)
        {
            int value = aux->value;
            aux->next = aux->next->next;
            return value; 
        }
    } return (-1);
}

int pop_back(node **head)
{
    if (*head) 
    {
        node* aux = *head;
        int value;
        if (! aux->next)
        {
            value = aux->value;
            *head = NULL;
        } else
        {
            while (!is_empty(aux->next->next)) 
            {
                aux = aux->next;
            }
            value = aux->next->value;
            aux->next = NULL;
        } return value;
        
    } return (-1);
}

bool is_empty(node *head) { return (head == NULL); }

int size(node *head)
{
    int length = 0;
    while (! is_empty(head))
    {
        head = head->next;
        length++;
    } return length;
}

void print(node *head)
{
    while (! is_empty(head))
    {
        printf("%i ", head->value);
        head = head->next;
    }
}