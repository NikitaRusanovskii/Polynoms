#pragma once
#include <Stack.hpp>


template<class T>
struct Node {
    T val;
    Node *left, *right;
    int balance_factor;
};


template<class T>
class AVLTree {
    private:
        Node<T>* root;

        void small_left_rotation();
        void small_right_rotation();
        void big_left_rotation();
        void big_right_rotation();

        void balance();
    public:
        AVLTree() = default;

        void insert(Node<T>* value) {
            
        }
};