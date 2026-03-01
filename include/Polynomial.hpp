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

        friend Polynomial operator+(Polynomial& p1, Monomial& m1);
        friend Polynomial operator-(Polynomial& p1, Monomial& m1);
        friend Polynomial operator*(Polynomial& p1, Monomial& m1);

        friend Polynomial operator+(Polynomial& p1, Polynomial& p2);
        friend Polynomial operator-(Polynomial& p1, Polynomial& p2);
        friend Polynomial operator*(Polynomial& p1, Polynomial& p2);
        Polynomial operator+=(Monomial& m1);
        Polynomial operator-=(Monomial& m1);
        Polynomial operator*=(Monomial& m1);
        Polynomial operator+=(Polynomial& p1);
        Polynomial operator-=(Polynomial& p1);
        Polynomial operator*=(Polynomial& p1);

        friend std::ostream& operator<<(std::ostream& ostr, Polynomial& p);

        size_t size();
        Iterator<Monomial> iterator();

        Polynomial(double x = 0.0, double y = 0.0, double z = 0.0): x(x), y(y), z(z) {}
        Polynomial(Monomial m);

};