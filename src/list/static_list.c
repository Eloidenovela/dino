#include "static_list.h"
#include "util/util.h"
#include <stdio.h>

void make_list(list *list, int capacity)
{
    list->capacity = capacity;
    list->quantity = 0;   
}

int size(const list *list)
{
    return list->quantity;
}

bool is_empty(const list *list)
{
    return (list->quantity == 0);
}

bool is_fully(const list *list)
{
    return (list->quantity == list->capacity);
}

void print_student(const student *student)
{
    printf("Name: %s\nSurname: %s\nTests: %.2f, %.2f\nAverage: %.2f", 
        student->name, student->surname, student->test1, student->test2, student->average
    );
}

void print_all_in_list(const list *list)
{
    for (int i = 0; i < list->quantity; i++)
    {
        print_student(&list->students[i]);
        printf("\n\n");
    }
}

bool push_front(list *list, const student *new_student)
{
    if (!(is_fully(list)))
    {   
        if (list->quantity != 0) 
        {
            for (int i = list->quantity; i >= 1; i--)
            {
                copy(&list->students[i], &list->students[i-1]);
            }
        }
        copy(&list->students[0], new_student);
        list->quantity++;
        return true;
    } return false;
}

bool insert(list *list, const student *new_student, int position)
{
    if (!(is_fully(list)) && (position >= 0 && position < list->quantity))
    {
        for (int i = list->quantity; i > position; i--)
        {
            copy(&list->students[i], &list->students[i-1]);
        }
        copy(&list->students[position], new_student);
        list->quantity++;
        return true;
    }
    return false;
}

bool push_back(list *list, const student *new_student)
{
    if (!is_fully(list))
    {
        copy(&list->students[list->quantity], new_student);
        list->quantity++;
        return true;
    } return false;
}

bool pop_front(list *list)
{
    if (!is_empty(list))
    {
        for (int i = 0; i < list->quantity-1; i++)
        {
            copy(&list->students[i], &list->students[i+1]);
        }
        list->quantity--;
        return true;
    }
    return false;
}

bool pop(list *list, int position)
{
    if (!is_fully(list) && (position >= 0 && position < list->quantity))
    {
        for (int i = position; i < list->quantity - 1; i++)
        {
            copy(&list->students[i], &list->students[i+1]);
        }
        list->quantity--;
        return true;
    }
    return false;
}

bool pop_back(list *list)
{
    if (!is_fully(list))
    {
        list->quantity--;
        return true;
    }
    return true;
}

student get_max_average(const list *list)
{
    struct list aux = *list;
    sort_by_average(&aux);

    return aux.students[aux.quantity-1];
}