
// Generated from PolynomialANTLR.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PolynomialANTLRVisitor.h"


/**
 * This class provides an empty implementation of PolynomialANTLRVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PolynomialANTLRBaseVisitor : public PolynomialANTLRVisitor {
public:

  virtual std::any visitMonomial_rule(PolynomialANTLRParser::Monomial_ruleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPolynomial_rule(PolynomialANTLRParser::Polynomial_ruleContext *ctx) override {
    return visitChildren(ctx);
  }


};

