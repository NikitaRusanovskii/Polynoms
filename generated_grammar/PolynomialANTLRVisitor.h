
// Generated from PolynomialANTLR.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PolynomialANTLRParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PolynomialANTLRParser.
 */
class  PolynomialANTLRVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PolynomialANTLRParser.
   */
    virtual std::any visitMonomial_rule(PolynomialANTLRParser::Monomial_ruleContext *context) = 0;

    virtual std::any visitPolynomial_rule(PolynomialANTLRParser::Polynomial_ruleContext *context) = 0;


};

