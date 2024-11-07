#include "BSTNode.hpp"

template <typename T>
BSTNode<T>::BSTNode() : data(T()), left(nullptr), right(nullptr), parent(nullptr) {}

template <typename T>
BSTNode<T>::BSTNode(const BSTNode<T>& other) : data(other.data), left(nullptr), right(nullptr), parent(nullptr) {
    if (other.left) {
        left = new BSTNode<T>();
        *left = *other.left;
        left->parent = this;
    }
    if (other.right) {
        right = new BSTNode<T>();
        *right = *other.right;
        right->parent = this;
    }
}


template <typename T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode<T>& other) {
    if (this != &other) {
        data = other.data;

        // Delete existing left and right subtrees
        delete left;
        delete right;

        // Copy left subtree
        if (other.left) {
            left = new BSTNode<T>();
            *left = *other.left;
            left->parent = this;
        } else {
            left = nullptr;
        }

        // Copy right subtree
        if (other.right) {
            right = new BSTNode<T>();
            *right = *other.right;
            right->parent = this;
        } else {
            right = nullptr;
        }
    }
    return *this;
}

template <typename T>
BSTNode<T>* BSTNode<T>::treeMin() {
    BSTNode<T>* current = this;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template <typename T>
BSTNode<T>* BSTNode<T>::treeMax() {
    BSTNode<T>* current = this;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

template <typename T>
void BSTNode<T>::printPreOrderTraversal() const {
    cout << data << " ";
    if (left)
        left->printPreOrderTraversal();
    if (right)
        right->printPreOrderTraversal();
}

template <typename T>
void BSTNode<T>::printInOrderTraversal() const {
    if (left)
        left->printInOrderTraversal();
    cout << data << " ";
    if (right)
        right->printInOrderTraversal();
}

template <typename T>
void BSTNode<T>::printPostOrderTraversal() const {
    if (left)
        left->printPostOrderTraversal();
    if (right)
        right->printPostOrderTraversal();
    cout << data << " ";
}
