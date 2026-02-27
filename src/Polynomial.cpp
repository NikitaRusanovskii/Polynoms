#include <Polynomial.hpp>
#include <Tools.hpp>


bool Polynomial::monomial_comparator(Monomial a, Monomial b) {
    return a <= b;
}

void Polynomial::add_monomial(Monomial m) {
    monomials.ordered_push(m, monomial_comparator);
}

void Polynomial::add(double coefficient, signed char x_degree, signed char y_degree, signed char z_degree) {
    add_monomial(Monomial(coefficient, x_degree, y_degree, z_degree));
}

double Polynomial::solve() {
    double result = 0.0;
    Iterator<Monomial> iter = monomials.iterator();
    while(!iter.end()) {
        result += (iter.next()).solve(x, y, z);
    }
    return result;
}

Polynomial operator+(Polynomial& p1, Polynomial& p2) {
    if(p1.size() == 0) {
        return p1;
    }
    else if (p2.size() == 0) {
        return p2;
    }

    Polynomial result;

    Polynomial& short_ = (p1.size() < p2.size()) ? p1 : p2;
    Polynomial& long_  = (p1.size() < p2.size()) ? p2 : p1;

    Monomial current_element_from_long = {};
    Monomial current_element_from_short = {};
    
    Iterator<Monomial> short_iter = short_.iterator();
    Iterator<Monomial> long_iter = long_.iterator();
    
    if (!long_iter.end()) current_element_from_long = long_iter.next();
    if (!short_iter.end()) current_element_from_short = short_iter.next();
    
    while(!short_iter.end()) {
        if (current_element_from_long == current_element_from_short) {
            result.monomials.push_back(current_element_from_long + current_element_from_short);
            current_element_from_long = long_iter.next();
            current_element_from_short = short_iter.next();
        }
        else if (current_element_from_long > current_element_from_short) {
            result.monomials.push_back(current_element_from_long);
            current_element_from_long = long_iter.next();
        }
        else if (current_element_from_long < current_element_from_short) {
            result.monomials.push_back(current_element_from_short);
            current_element_from_short = short_iter.next();
        }
        //std::cout << "Comparing: " << compare(current_element_from_long, current_element_from_short) << "\n";
    }
    while(!long_iter.end()) {
        result.monomials.push_back(current_element_from_long);
        current_element_from_long = long_iter.next();
    }
    return result;
}
//Polynomial operator-(const Polynomial& p2, const Polynomial& p2) {
//
//}
//Polynomial operator*(const Polynomial& p1, const Polynomial& p2) {
//
//}
//Polynomial& Polynomial::operator+=(const Polynomial& p1) {
//
//}
//Polynomial& Polynomial::operator-=(const Polynomial& p1) {
//
//}
//Polynomial& Polynomial::operator*=(const Polynomial& p1) {}

std::ostream& operator<<(std::ostream& ostr, Polynomial& p) {
    Iterator<Monomial> iter = p.monomials.iterator();
    if(!iter.end()) {
        ostr << iter.next();
        while(!iter.end()) {
            ostr << " + " << iter.next();
        }

        ostr << std::endl;
    }
    return ostr;
}