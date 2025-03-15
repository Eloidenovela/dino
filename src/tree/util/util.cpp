#include "util.hpp"

namespace util::tree 
{
namespace b 
{
    using node = ::tree::b::node;

    std::optional<int> min_value(node* tree) {
        if (tree != nullptr) {
            node* current_node = tree;
            while (current_node->left != nullptr) {
                current_node = current_node->left;
            }
            return current_node->value;
        }
        return std::nullopt;
    }
}
}