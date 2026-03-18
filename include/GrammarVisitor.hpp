#pragma once
#include <Monomial.hpp>
#include <Polynomial.hpp>
#include <PolynomialANTLRBaseVisitor.h>
#include <PolynomialANTLRLexer.h>
#include <PolynomialANTLRParser.h>
#include <antlr4-runtime.h>
#include <iostream>
#include <vector>

/*

class  PolynomialANTLRBaseVisitor : public PolynomialANTLRVisitor {
public:

  virtual std::any visitMonomial_rule(PolynomialANTLRParser::Monomial_ruleContext *ctx) override {
	return visitChildren(ctx);
  }

  virtual std::any visitPolynomial_rule(PolynomialANTLRParser::Polynomial_ruleContext *ctx) override
{ return visitChildren(ctx);
  }

  virtual std::any visitPolynomial_expr(PolynomialANTLRParser::Polynomial_exprContext *ctx) override
{ return visitChildren(ctx);
  }


};

*/

class GrammarVisitor : public PolynomialANTLRBaseVisitor
{
  private:
    Polynomial tmp;
  public:

    GrammarVisitor() = default;

	virtual std::any visitMonomial_rule(PolynomialANTLRParser::Monomial_ruleContext *ctx) override
	{
        double coef[4];
        for (int i = 0; i < 4; i++) {
            std::string tmp_coef;
            if (ctx->NUM(i)) tmp_coef = ctx->NUM(i)->getText();
            else tmp_coef = "0";
            if (tmp_coef == "-") tmp_coef = "-1";
            if (tmp_coef == "") tmp_coef = "0";
            coef[i] = std::stod(tmp_coef);
        }

        tmp.add(Monomial(coef[0], coef[1], coef[2], coef[3]));
        return visitChildren(ctx);
	}

	virtual std::any
	visitPolynomial_rule(PolynomialANTLRParser::Polynomial_ruleContext *ctx) override
	{
		return visitChildren(ctx);
	}

    Polynomial get() {
        return tmp;
    }
};