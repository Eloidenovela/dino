// #include "util/b_tree.hpp"
#include <iostream>
#include "trees/b_tree.hpp"

using b = trees::b::b;

int main() {
    b av;
    av.insert(10);
    av.insert(19);

    std::cout << av.remove(9) << std::endl;

    std::cout << av.search(9) << std::endl;

    std::cout << av.max_value().value() << std::endl;

    std::cout << av.min_value().value() << std::endl;
}