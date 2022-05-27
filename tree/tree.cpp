#include "tree.hpp"

auto tree::insert(int val) -> tree_node * {
    tree_node* newNode = new tree_node();
    newNode->value = val;
    auto currNode = tree::root;
    while (true) {
        if (currNode->value > val) {
            if (currNode->left == nullptr) {
                newNode->up = currNode;
                currNode->left = newNode;
                break;
            } else {
                currNode = currNode->left;
            }
        } 
        else if (currNode->value < val) {
            if (currNode->right == nullptr) {
                newNode->up = currNode;
                currNode->right = newNode;
                break;
            } else {
                currNode = currNode->right;
            }
        } else {
            return currNode;
        }
    }

    return newNode;
}

auto tree::remove(int val) -> bool {
    tree_node *curr = this->root;
    tree_node *parent = nullptr;
    while (curr && curr->value != val) {
        parent = curr;
        if (curr->value > val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if (!curr) {
        return false;
    }
    if (curr->left == nullptr) {
        if (parent && parent->left == curr) {
            parent->left = curr->right;
        }
        if (parent && parent->right == curr) {
            parent->right = curr->right;
        }
        return true;
    }
    else if (curr->right == nullptr) {
        if (parent && parent->left == curr) {
            parent->left = curr->left;
        }
        if (parent && parent->right == curr) {
            parent->right = curr->left;
        }
        return true;
    } else {
        tree_node *replace = curr->right;
        while (replace->left) {
            replace = replace->left;
        }
        int replace_val = replace->value;
        remove(replace_val);
        curr->value = replace_val;
        return true;
    }
}
