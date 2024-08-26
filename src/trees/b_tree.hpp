#pragma once

#include <bits/types/FILE.h>
#include <memory>
#include <optional>

namespace trees {
    
    namespace b {

        struct node { 
            int value;
            struct node* left;
            struct node* right;

            static node* new_node(int value) {
                node* new_node = new node();
                new_node->value = value;
                new_node->right = nullptr;
                new_node->left = nullptr;
                return new_node;
            }
        };

        class b {
            node* root;
            public:
                b(): root(nullptr) { }

                bool insert(int value);
                bool search(int value) const;
                bool remove(int value);
                std::optional<int> min_value() const;
                std::optional<int> max_value() const;
        };
    }
}