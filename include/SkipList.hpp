#pragma once
#include <Node.hpp>


template<class T>
class SkipList {
    private:
        using TNode = SNode<T>;
        TNode* create(T value) {
            TNode* new_node = new TNode(value);
            return tmp;
        }
    public:
        void push_back(T value);
        void push_front(T value);
        bool search(T value);
        void remove(T value);
        void clear();
        size_t size();
        bool empty();

        friend std::ostream& operator<<(std::ostream& ostr, const LinkedList& l);
};