#pragma once

#include "../trees/b_tree.hpp"

namespace util::trees {
    namespace b {
        std::optional<int> min_value(::trees::b::node *tree);
    }
}