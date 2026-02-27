#pragma once
#include <random>


template<class T>
struct LNode {
    T value;
    LNode<T>* next;
    LNode(T value): value(value), next(nullptr) {}
};
