#pragma once
#include <Node.hpp>
#include <stdexcept>
#include <iostream>


template<class T>
class LinkedList {
    private:
        using TNode = LNode<T>;
        TNode* create(T value) {
            TNode* tmp = new TNode(value);
            return tmp;
        }
        TNode* head;
        size_t list_size;
    public:
        void push_back(T value) {
            TNode* node = create(value);
            list_size++;
            if (!head) head = node;
            else {
                TNode* current = head;
                while(current->next) {
                    current = current->next;
                }
                current->next = node;
            }
        }

        void push_front(T value) {
            TNode* node = create(value);
            list_size++;
            if(!head) head = node;
            else { 
                node->next = head;
                head = node;
            }
        }

        bool search(T value) {
            TNode* current = head;
            while(current->next) {
                if(current->value == value) return true;
                current = current->next;
            }
            return false;
        }

        void remove(T value) {
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
        }

        void clear() {
            while(head) {
                TNode* tmp = head;
                head = head->next;
                delete tmp;
            }
            list_size = 0;
        }

        size_t size() {
            return list_size;
        }

        bool empty() {
            return (head ? false : true);
        }

        friend std::ostream& operator<<(std::ostream& ostr, const LinkedList& l) {
            TNode* temp = l.head;
            while(temp) {
                ostr << "[" << temp->value << "] ";
                temp = temp->next;
            }
            ostr << "\n";
            return ostr;
        }


        LinkedList(T value): head(create(value)), list_size(0) {}
        LinkedList(): head(nullptr), list_size(0) {}

        LinkedList(const LinkedList& l) {
            TNode* temp = l->head;
            list_size = l.list_size;
            while(temp) {
                push_back(temp->value);
            }
        }

        ~LinkedList() {
            clear();
        }
};