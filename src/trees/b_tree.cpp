#include "b_tree.hpp"
#include "../util/trees.hpp"
#include <exception>
#include <iostream>

namespace trees::b {

    bool b::insert(int value) {
        node* new_node = node::new_node(value);
        
        if (this->root == nullptr) {
            this->root = new_node;
            return true;
        }

        node* current_node = this->root;

        while (true) {
            if (current_node->value > value) {
                if (current_node->left == nullptr) {
                    current_node->left = new_node;
                    return true; 
                } else {
                    current_node = current_node->left;
                }
            } else if (current_node->value < value) {
                if (current_node->right == nullptr) {
                    current_node->right = new_node;
                    return true;
                } else {
                    current_node = current_node->right;
                }
            } else {
                break;
            }
        }

        return false;
    }

    bool b::search(int value) const {

        if (root == nullptr) {
            return false;
        } else {
            node* current_node = root;

            try {
                while (true) {
                    if ((current_node->value) == value) {
                        return true;
                    } else {
                        if ((current_node->value) > value) {
                            if ((current_node->left) != nullptr) {
                                current_node = current_node->left;
                            } else {
                                return false;
                            }
                        } else if ((current_node->value) < value) {
                            if (current_node->right != nullptr) {
                                current_node = current_node->right;
                            } else {
                                return false;
                            }
                        }
                    }
                }

            } catch (const std::exception & e) {
                std::cerr << e.what() << std::endl;
            }
        }

        return false;
    }

    bool b::remove(int value) {
        node* current_node = root;
        node* parent = root;

        while (current_node and current_node->value != value) {
            if (current_node != nullptr) {
                parent = current_node;
            }
            if ((current_node->value) > value) {
                current_node = current_node->left;
            } else if ((current_node->value) < value) {
                current_node = current_node->right; 
            }
        }

        if (current_node == nullptr) {
            return false;
        }

        if (!(current_node->left) and !(current_node->right)) {
            // caso 1: o no a ser removido e uma folha

            if (parent->left == current_node) {
                parent->left = nullptr;
            } else if (parent->right == current_node) {
                parent->right = nullptr;
            } else if (current_node == root) {
                root = nullptr;
            }

        } else if ((current_node->left) and (current_node->right)) {
            // caso 2: no a ser removido tem dois filhos
            using namespace util::trees;
            int min_value = util::trees::b::min_value(current_node->right).value();
            remove(min_value);
            current_node->value = min_value;

        } else {
            // caso 2: o no a ser removido tem um filho

            node* child = (current_node->left) ? current_node->left : current_node->right;
            
            if (parent->left == current_node) {
                parent->left = child;
            } else if (parent->right == current_node) {
                parent->right = child;
            } else if (root == current_node) {
                root = child;
            }
        }
        
        return true;
    }

    std::optional<int> b::min_value() const {

        if (util::trees::b::min_value(root).has_value()) {
            return util::trees::b::min_value(root).value();
        }

        return std::nullopt;
    }

    std::optional<int> b::max_value() const {
        if (root != nullptr) {
            node* current_node = root;
            while (current_node->right != nullptr) {
                current_node = current_node->right;
            }

            return current_node->value;
        }

        return std::nullopt;
    }
}