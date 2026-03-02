#pragma once
#include <random>
#include <variant>
#include <Monomial.hpp>
#define MAX_LAYER_SKIP_LIST 5


template<class T>
struct LNode {
    T value;
    LNode<T>* next;
    LNode(T value): value(value), next(nullptr) {}
};

enum class Infinity {
    PLUS_INFINITY,
    MINUS_INFINITY
};


static size_t layer_count_randomizer(int max_level) {
    static std::mt19937 rng{std::random_device{}()};
    static std::uniform_int_distribution<uint64_t> dist;
    return (size_t)(dist(rng) % max_level + 1);
}

template<class T>
struct SNode {
    using TNode = SNode<T>;
    TNode* tower[MAX_LAYER_SKIP_LIST];
    size_t active_layer;
    std::variant<Infinity, T> value;

    TNode* next(size_t level) {
        return tower[level];
    }

    bool is_infinity() {
        return std::holds_alternative<Infinity>(value); // проверяет что std::variant хранит infinity
    }

    void set_next(size_t level, TNode* next) {
        tower[level] = next;
    }

    std::variant<Infinity, T> get_value() {
        return value;
    }

    SNode(T value): value(value), active_layer(layer_count_randomizer(MAX_LAYER_SKIP_LIST)) {
        for(int i = 0; i < MAX_LAYER_SKIP_LIST; i++) {
            tower[i] = nullptr;
        }
    }
    SNode(Infinity value, size_t active_layer): value(value), active_layer(active_layer) {
        for(int i = 0; i < MAX_LAYER_SKIP_LIST; i++) {
            tower[i] = nullptr;
        }
    }
};


template<class T = Monomial>
bool operator<(const std::variant<Infinity, T>& op1, const std::variant<Infinity, T>& op2) {
    bool result;
    if (std::holds_alternative<Infinity>(op1) && std::holds_alternative<Infinity>(op2)) {
        if (std::get<Infinity>(op1) == Infinity::MINUS_INFINITY && std::get<Infinity>(op2) == Infinity::PLUS_INFINITY) result = true;
        else result = false;
    }
    else if (std::holds_alternative<T>(op1) && std::holds_alternative<Infinity>(op2)) {
        if (std::get<Infinity>(op2) == Infinity::PLUS_INFINITY) result = true;
        else result = false;
    }
    else if (std::holds_alternative<T>(op2) && std::holds_alternative<Infinity>(op1)) {
        if (std::get<Infinity>(op1) == Infinity::PLUS_INFINITY) result = false;
        else result = true;
    }
    else result = (std::get<T>(op1) < std::get<T>(op2));
    return result;
}

template<class T = Monomial>
bool operator>(const std::variant<Infinity, T>& op1, const std::variant<Infinity, T>& op2) {
    bool result;
    if (std::holds_alternative<Infinity>(op1) && std::holds_alternative<Infinity>(op2)) {
        if (std::get<Infinity>(op1) == Infinity::MINUS_INFINITY && std::get<Infinity>(op2) == Infinity::PLUS_INFINITY) result = false;
        else result = true;
    }
    else if (std::holds_alternative<T>(op1) && std::holds_alternative<Infinity>(op2)) {
        if (std::get<Infinity>(op2) == Infinity::PLUS_INFINITY) result = false;
        else result = true;
    }
    else if (std::holds_alternative<T>(op2) && std::holds_alternative<Infinity>(op1)) {
        if (std::get<Infinity>(op1) == Infinity::PLUS_INFINITY) result = true;
        else result = false;
    }
    else result = (std::get<T>(op1) > std::get<T>(op2));
    return result;
}

template<class T = Monomial>
bool operator==(const std::variant<Infinity, T>& op1, const std::variant<Infinity, T>& op2) {
    return ((!operator<(op1, op2)) && (!operator>(op1, op2)));
}

template<class T = Monomial>
bool operator!=(const std::variant<Infinity, T>& op1, const std::variant<Infinity, T>& op2) {
    return (!operator==(op1, op2));
}

template<class T = Monomial>
bool operator>=(const std::variant<Infinity, T>& op1, const std::variant<Infinity, T>& op2) {
    return (operator==(op1, op2) || operator>(op1, op2));
}

template<class T = Monomial>
bool operator<=(const std::variant<Infinity, T>& op1, const std::variant<Infinity, T>& op2) {
    return (operator==(op1, op2) || operator<(op1, op2));
}