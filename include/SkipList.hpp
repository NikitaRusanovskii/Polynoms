#pragma once
#include <Node.hpp>


template<class T>
class SkipListIterator {
    private:
        using TNode = SNode<T>;
        TNode* node;
    public:
        SkipListIterator(TNode* node): node(node){}
        bool has_next();
        void next();
        std::variant<Infinity, T> current();
        bool end();
};


template<class T>
class SkipList {
    private:
        using TNode = SNode<T>;
        TNode* create(T value) {
            return new TNode(value);
        }

        TNode* create(Infinity value, size_t layer) {
            return new TNode(value, layer);
        }

        size_t _size;
        TNode *head, *tail;

        std::variant<Infinity, T> extend_type(T value) {
            return std::variant<Infinity, T>(value);
        }
    public:
  
  
      void push_back(T value) {
            TNode* current = head;
            TNode* new_node = create(value);
            int current_layer = MAX_LAYER_SKIP_LIST - 1;
            auto extended_value = extend_type(value);
            

            while(current_layer > -1) {
                if(current->next(current_layer)->get_value() >= extended_value) {
                    if (new_node->active_layer >= current_layer) {
                        TNode* tmp = current->next(current_layer);
                        current->set_next(current_layer, new_node);
                        new_node->set_next(current_layer, tmp);
                    }
                    current_layer -= 1;
                }
                else if (current->next(current_layer)->get_value() < extended_value) current = current->next(current_layer);
            }
            _size++;
        }
        void push_front(T value) {
            push_back(value);
        }
        void ordered_push(T value, std::function<bool(T a, T b)> comparator) {
            push_back(value);
        }
        TNode* search(T value) {
            TNode* current = head;
            size_t current_layer = MAX_LAYER_SKIP_LIST - 1;
            auto extended_value = extend_type(value);

            while(true) {
                if(current->next(current_layer)->get_value() > extended_value) {
                    if (current_layer == 0) return nullptr;
                    else current_layer -= 1;
                }
                else if(current->next(current_layer)->get_value() < extended_value) {
                    current = current->next(current_layer);
                }
                else return current->next(current_layer);
            }
        }


        void remove(T value) {
            TNode* to_remove = search(value);
            if(to_remove == nullptr) throw -1; // исключение, чтобы не удалить несуществующий узел

            TNode* current = head;
            size_t current_layer = MAX_LAYER_SKIP_LIST - 1;

            while(current->next(current_layer) != to_remove) {
                if (current->next(current_layer)->get_value() > to_remove->get_value()) {
                    current_layer -= 1;
                }
                else if(current->next(current_layer)->get_value() < to_remove->get_value()) {
                    current = current->next(current_layer);
                }
            }

            for(size_t i = 0; i < current->active_layer; i++) {
                current->set_next(i, to_remove->next(i));
            }

            delete to_remove;
        }
        void clear() {
            TNode* current = head->next(0);
            while(current != tail) {
                TNode* to_remove = current;
                current = current->next(0);
                delete to_remove;
            }

            for(int i = 0; i < MAX_LAYER_SKIP_LIST;i++) {
                head->set_next(i, tail);
            }
            _size=0;
        }


        size_t size() { return _size; }
        bool empty() { return _size == 0; }


        friend std::ostream& operator<<(std::ostream& ostr, SkipList& s) {
            if (std::holds_alternative<T>(s.head->next(0)->get_value())) {
                ostr << std::get<T>(s.head->next(0)->get_value());
            } 
            ostr << std::endl;
            return ostr;
        }


        SkipListIterator<T> iterator();


        SkipList(T value): head(create(Infinity::MINUS_INFINITY, MAX_LAYER_SKIP_LIST)),
                           tail(create(Infinity::PLUS_INFINITY, MAX_LAYER_SKIP_LIST)),
                           _size(0) {
            
                                        for(size_t i = 0; i < MAX_LAYER_SKIP_LIST; i++) {
                                            head->set_next(i, tail);
                                        }
                                        push_back(value);
                                    }
        SkipList(): head(create(Infinity::MINUS_INFINITY, MAX_LAYER_SKIP_LIST)),
                    tail(create(Infinity::PLUS_INFINITY, MAX_LAYER_SKIP_LIST)),
                    _size(0)    {
                                    for(size_t i = 0; i < MAX_LAYER_SKIP_LIST; i++) {
                                        head->set_next(i, tail);
                                    }
                                }
        SkipList(const SkipList& s) = default;
        SkipList& operator=(const SkipList& l) = default;

        ~SkipList() {
            clear();
            delete head;
            delete tail;
        }
};