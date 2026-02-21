#pragma once
#include <Stack.hpp>
#include <Monomial.hpp>
#include <Polynomial.hpp>

#define STORING_A_POLYNOMIAL Stack<Monomial>

class Representation {};
class TextRepresentationPolynomial;
class MathematicalRepresentationPolynomial;

class PolyBuilder {
    private:
        Representation repr;
    
    public:
        PolyBuilder(Representation repr);
        Polynomial build(STORING_A_POLYNOMIAL storage); 
};