#pragma once
#include <Node.hpp>
#include <stdexcept>
#include <iostream>
#include <functional>


template<class T>
class Iterator {
    private:
        using TNode = LNode<T>;
        TNode* node;
    public:
        Iterator(TNode* node): node(node){}


        bool has_next() { return (node != nullptr); }
        void next() {
            if(!has_next()){
                throw -1;
            }
            node = node->next;
        }
        T current() {
            return node->value;
        }
        bool end() {
            return (node == nullptr);
        }
};


template<class T>
class LinkedList {
    private:
        using TNode = LNode<T>;
        TNode* create(T value) {
            return new TNode(value);
        }
        TNode* head;
        size_t _size;
    public:
        void push_back(T value) {
            _size++;
            TNode* new_node = create(value);
            if(!head) {
                head = new_node;
                return;
            }
            TNode* current = head;
            while(current->next) {
                current = current->next;
            }
            current->next = new_node;
        }

        void push_front(T value) {
            _size++;
            TNode* node = create(value);
            if(!head) {
                head = node;
            }
            else { 
                node->next = head;
                head = node;
            }
        }

        void ordered_push(T value, std::function<bool(T a, T b)> comparator) {
            _size++;
            TNode* node = create(value);
            if (!head || comparator(value, head->value)) {
                node->next = head;
                head = node;
                return;
            }

            TNode* current = head;
            while (current->next && comparator(current->next->value, value)) {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }

        bool search(T value) {
            if(!head) return false;
            TNode* current = head;
            while(current->next) {
                if(current->value == value) return true;
                current = current->next;
            }
            return false;
        }

        void remove(T value) {
            if(!head) return;
            TNode* current = head;
            if (current->value == value) {
                head = head->next;
                delete current;
            }
            while(current->next) {
                if (current->next->value == value) {
                    TNode* tmp = current->next;
                    current->next->next ? current->next = current->next->next : current->next = nullptr;
                    delete tmp;
                }
            }
            _size--;
        }

        void clear() {
            while(head) {
                TNode* tmp = head;
                head = head->next;
                delete tmp;
            }
            _size = 0;
        }

        size_t size() const {
            return _size;
        }

        bool empty() {
            return (_size==0);
        }

        friend std::ostream& operator<<(std::ostream& ostr, LinkedList& l) {
            Iterator<T> iter = l.iterator();
            while(iter.has_next()) {
                ostr << "[" << iter.next() << "] ";
            }
            ostr << "\n";
            return ostr;
        }

        Iterator<T> iterator() {
            return Iterator<T>(head);
        }


        LinkedList(T value): head(nullptr), _size(0) {}
        LinkedList(): head(nullptr), _size(0) {}

        LinkedList(const LinkedList& l): _size(0) {
            head = nullptr;
            TNode* temp = l.head;
            _size = l.size();
            while(temp) {
                push_back(temp->value);
                temp = temp->next;
            }
        }

        LinkedList& operator=(const LinkedList& l) {
            if (this == &l) return *this;
            _size = l._size;
            TNode* tmp = l.head;
            while(tmp) {
                push_back(tmp->value);
                tmp = tmp->next;
            }
            return *this;
        }

        ~LinkedList() {
            clear();
        }
};