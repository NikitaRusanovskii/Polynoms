#pragma once
#include <LinkedList.hpp>
#include <Monomial.hpp>
#include <iostream>


class Polynomial {
    private:
        LinkedList<Monomial> monomials;
        
        static bool monomial_comparator(Monomial a, Monomial b);
        void add_monomial(Monomial m);

        double x, y, z;
    public:

        void add(double coefficient = 0, signed char x_degree = 0, signed char y_degree = 0, signed char z_degree = 0);
        double solve();


        friend Polynomial operator+(Polynomial& p1, Polynomial& p2);
        friend Polynomial operator-(const Polynomial& p1, const Polynomial& p2);
        friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2);
        Polynomial& operator+=(const Polynomial& p1);
        Polynomial& operator-=(const Polynomial& p1);
        Polynomial& operator*=(const Polynomial& p1);

        friend std::ostream& operator<<(std::ostream& ostr, Polynomial& p);

        size_t size() {
            return monomials.size();
        }

        Iterator<Monomial> iterator() {
            return monomials.iterator();
        }

        Polynomial(double x = 0.0, double y = 0.0, double z = 0.0): x(x), y(y), z(z) {}

};