#include "util.h"
#include <string.h>

void copy(student *destination, const student *source)
{
    strcpy(destination->name, source->name);
    strcpy(destination->surname, source->surname);
    destination->test1 = source->test1;
    destination->test2 = source->test2;
    destination->average = calculate_average(source->test1, source->test2);
}

float calculate_average(float test1, float test2)
{
    return (test1 + test2) / 2;
}

void sort_by_average(list *list)
{
    // this use bubble sort to sort that list

    for (int i = 0; i < list->quantity; i++)
    {
        for (int j = 0; j < list->quantity -1; j++)
        {
            if (list->students[j].average > list->students[j+1].average) 
            {
                student aux;
                copy(&aux, &list->students[j]);

                copy(&list->students[j], &list->students[j+1]);

                copy(&list->students[j+1], &aux);
            }
        }
    }
}