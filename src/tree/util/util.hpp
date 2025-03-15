#pragma once

#include "../b_tree.hpp"

namespace util::tree 
{
namespace b 
{
    std::optional<int> min_value(::tree::b::node *tree);
}
}