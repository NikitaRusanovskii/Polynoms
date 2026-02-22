#pragma once
#include <random>


static std::mt19937 gen(std::random_device{}());

template<class T>
struct LNode {
    T value;
    LNode<T>* next;
    LNode(T value): value(value), next(nullptr) {}
};


template<class T, int cnt=1>
struct SNode {
    private:
        int pointer_cntr;
    public:
        static_assert(cnt > 0, "cnt must be positive");
        T value;
        SNode<T>* next[cnt];
        SNode(T value): value(value), next{} {
            std::uniform_int_distribution<int> dist(1, cnt);
            pointer_cntr = dist(gen);
        }
};