#include "list/static_list.h"

int main() 
{
    list list;
    make_list(&list, 100);

    student student1 = {.name="Carlos", .surname="Novela", .test1=14.3, .test2=14.5};
    push_front(&list, &student1);
    student student2 = {.name="Harold", .surname="Novela", .test1=13.3, .test2=14.5};
    push_front(&list, &student2);
    student student3 = {.name="Eleuterio", .surname="Novela", .test1=15.3, .test2=14.5};
    student student4 = {.name="Eloid", .surname="Novela", .test1=17.3, .test2=14.5};
    insert(&list, &student3, 1);
    push_back(&list, &student4);
    // pop_front(&list);
    // pop_front(&list);
    // pop_back(&list);

    // sort_by_average(&list);
    // pop(&list, 2);
    // print_all_in_list(&list);
    student m = get_max_average(&list);
    print_student(&m);
    // printf("%i\n", size(&list));
}