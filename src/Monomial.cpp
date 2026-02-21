#include <Monomial.hpp>

/*
unsigned char Monomial::transformation_of_the_degree(signed char degree) {
    if (HIGHEST_BOUND_OF_THE_DEGREE < degree|| LOWER_BOUND_OF_THE_DEGREE > degree) throw -1;
    return degree - LOWER_BOUND_OF_THE_DEGREE;
}

void Monomial::set_degree(char degree, int place) {
    degrees.storage = (degrees.storage << place * 8) | degree;
}
signed char Monomial::get_degree(int place) {
    return (degrees.storage & (1 << 9 - 1));
}
*/

signed char Monomial::operator[](size_t index) const {
    if (index < 0 || index > 3) throw -1;
    return degrees.degree[index] + -1 * abs(LOWER_BOUND_OF_THE_DEGREE);
}

signed char transform_degree(signed char value) {
    //if (value < LOWER_BOUND_OF_THE_DEGREE || value > HIGHEST_BOUND_OF_THE_DEGREE) throw -1;
    return value + abs(LOWER_BOUND_OF_THE_DEGREE);
}

Monomial::Monomial(double coefficient, signed char x_degree, signed char y_degree, signed char z_degree): coefficient(coefficient) {
    degrees.degree[0] = transform_degree(x_degree);
    degrees.degree[1] = transform_degree(y_degree);
    degrees.degree[2] = transform_degree(z_degree);
}

void Monomial::change_degree(signed char _degree, int place) {
    if (place < 0 || place > 3) throw std::out_of_range("invalid place. Function: Monomial::change_degrees\n");
    degrees.degree[place] = _degree;
}

void Monomial::change_coefficient(double _coefficient)
{
    coefficient = _coefficient;
}

int compare(Monomial a, Monomial b) {

    //std::cout << a.degrees.storage << "\n" << b.degrees.storage;
    return (a.degrees.storage - b.degrees.storage);
}

Monomial operator+(const Monomial& m1, const Monomial& m2) {
    Monomial m;
    if (compare(m1, m2) == 0) {
        m.change_coefficient(m1.coefficient + m2.coefficient);
        m.change_degree(transform_degree(m1[0]), 0);
        m.change_degree(transform_degree(m1[1]), 1);
        m.change_degree(transform_degree(m1[2]), 2);
    }
    else {
        throw -1; // soon edit this;
    }
    return m;
}
Monomial operator-(const Monomial& m1, const Monomial& m2) {
    Monomial m;
    if (compare(m1, m2) == 0) {
        m.change_coefficient(m1.coefficient - m2.coefficient);
        m.change_degree(transform_degree(m1[0]), 0);
        m.change_degree(transform_degree(m1[1]), 1);
        m.change_degree(transform_degree(m1[2]), 2);
    }
    else {
        throw -1; // soon edit this;
    }
    return m;

}
Monomial operator*(const Monomial& m1, const Monomial& m2) {
    Monomial m;
    if (compare(m1, m2) == 0) {
        m.change_coefficient(m1.coefficient * m2.coefficient);
        m.change_degree(transform_degree(m1[0] + m2[0]), 0); // потом реализовать отбрасывание
        m.change_degree(transform_degree(m1[1] + m2[1]), 1);
        m.change_degree(transform_degree(m1[2] + m2[2]), 2);
    }
    else {
        throw -1; // soon edit this;
    }
    return m;
}
Monomial operator/(const Monomial& m1, const Monomial& m2) {
    Monomial m;
    if (compare(m1, m2) == 0) {
        m.change_coefficient(m1.coefficient / m2.coefficient);
        m.change_degree(transform_degree(m1[0] - m2[0]), 0); // потом реализовать отбрасывание
        m.change_degree(transform_degree(m1[1] - m2[1]), 1);
        m.change_degree(transform_degree(m1[2] - m2[2]), 2);
    }
    else {
        throw -1; // soon edit this;
    }
    return m;
}
Monomial operator*(const Monomial& m, double coefficient) {
    return Monomial(m.coefficient * coefficient, m.degrees.degree[0], m.degrees.degree[1], m.degrees.degree[2]);
}

Monomial operator/(const Monomial& m, double coefficient) {
    return Monomial(m.coefficient / coefficient, m.degrees.degree[0], m.degrees.degree[1], m.degrees.degree[2]);
}

Monomial& Monomial::operator+=(const Monomial& other) {
    *this = (*this) + other;
    return *this;
}

Monomial& Monomial::operator-=(const Monomial& other) {
    *this = (*this) - other;
    return *this;
}

Monomial& Monomial::operator*=(const Monomial& other) {
    *this = (*this) * other;
    return *this;
}

Monomial& Monomial::operator/=(const Monomial& other) {
    *this = (*this) / other;
    return *this;
}

Monomial& Monomial::operator*=(double coefficient){
    *this = (*this) * coefficient;
    return *this;
}
Monomial& Monomial::operator/=(double coefficient){
    *this = (*this) * coefficient;
    return *this;
}

std::ostream& operator<<(std::ostream& ostr, const Monomial& m) {
    ostr << m.coefficient << "x^" << (int)m[0] << "y^" << (int)m[1] << "z^" << (int)m[2];
    return ostr;
}