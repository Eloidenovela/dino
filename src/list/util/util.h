#ifndef UTIL_H
#define  UTIL_H

#include "../static_list.h"

void copy(student* destination, const student* source);
float calculate_average(float test1, float test2);

void sort_by_average(list *list);

#endif