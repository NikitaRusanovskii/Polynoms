
// Generated from PolynomialANTLR.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  PolynomialANTLRParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, NUM = 5, OPERATION = 6, OPEN_BRACKET = 7, 
    CLOSE_BRACKET = 8, WS = 9
  };

  enum {
    RuleMonomial_rule = 0, RulePolynomial_rule = 1
  };

  explicit PolynomialANTLRParser(antlr4::TokenStream *input);

  PolynomialANTLRParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~PolynomialANTLRParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class Monomial_ruleContext;
  class Polynomial_ruleContext; 

  class  Monomial_ruleContext : public antlr4::ParserRuleContext {
  public:
    Monomial_ruleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Monomial_ruleContext* monomial_rule();

  class  Polynomial_ruleContext : public antlr4::ParserRuleContext {
  public:
    Polynomial_ruleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Monomial_ruleContext *> monomial_rule();
    Monomial_ruleContext* monomial_rule(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Polynomial_ruleContext* polynomial_rule();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

