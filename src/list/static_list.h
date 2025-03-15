#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <stdbool.h>
#define MAX 10

typedef struct student 
{
    char name[20];
    char surname[20];
    float test1, test2;
    float average;
} student;

typedef struct list
{
    student students[MAX];
    int quantity;
    int capacity;
} list;

void make_list(list* list, int capacity);
// student make_student(const char* name, const char* surname, float test1, float test2);
int size(const list* list);
bool is_empty(const list* list);
bool is_fully(const list* list);

bool push_front(list* list, const student* new_student);
bool insert(list* list, const student* new_student, int position);
bool push_back(list* list, const student* new_student);

bool pop_front(list* list);
bool pop(list* list, int position);
bool pop_back(list *list);

void print_student(const student* student);
void print_all_in_list(const list* list);

student get_max_average(const list* list);

#endif