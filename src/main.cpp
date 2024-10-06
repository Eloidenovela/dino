// #include "util/b_tree.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
// #include "trees/b_tree.hpp"
#include "algorithm/sort/sort.hpp"
#include "algorithm/search/search.hpp"
#include "stack/stack.h"

// using b = trees::b::b;

node *new_ = (node*)malloc(sizeof(node));

int main() {


    node* stack = NULL;

    push(&stack, 10);
    push(&stack, 100);
    push(&stack, 104);

    std::cout << size(stack) << std::endl;
    // std::cout << is_empty(stack) << std::endl;
    std::cout << pop(&stack)->value << std::endl;
    std::cout << peek(stack)->value << std::endl;
    std::cout << pop(&stack)->value << std::endl;
    std::cout << peek(stack)->value << std::endl;
    // int arr[] = {9, 4, -2, 178, 17};

    // std::cout << search::binary(arr, 0, 5, 1) << std::endl;

    // algo::sort::insertion(arr, 5);

    // for (auto& i: arr)
    //     std::cout << i << " ";
    
}