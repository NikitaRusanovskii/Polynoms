
// Generated from PolynomialANTLR.g4 by ANTLR 4.13.2


#include "PolynomialANTLRVisitor.h"

#include "PolynomialANTLRParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PolynomialANTLRParserStaticData final {
  PolynomialANTLRParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PolynomialANTLRParserStaticData(const PolynomialANTLRParserStaticData&) = delete;
  PolynomialANTLRParserStaticData(PolynomialANTLRParserStaticData&&) = delete;
  PolynomialANTLRParserStaticData& operator=(const PolynomialANTLRParserStaticData&) = delete;
  PolynomialANTLRParserStaticData& operator=(PolynomialANTLRParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag polynomialantlrParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PolynomialANTLRParserStaticData> polynomialantlrParserStaticData = nullptr;

void polynomialantlrParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (polynomialantlrParserStaticData != nullptr) {
    return;
  }
#else
  assert(polynomialantlrParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PolynomialANTLRParserStaticData>(
    std::vector<std::string>{
      "monomial_rule", "polynomial_rule"
    },
    std::vector<std::string>{
      "", "'x^'", "'y^'", "'z^'", "'+'", "", "", "'('", "')'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "NUM", "OPERATION", "OPEN_BRACKET", "CLOSE_BRACKET", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,9,28,2,0,7,0,2,1,7,1,1,0,3,0,6,8,0,1,0,1,0,3,0,10,8,0,1,0,1,0,3,0,
  	14,8,0,1,0,1,0,3,0,18,8,0,1,1,1,1,1,1,5,1,23,8,1,10,1,12,1,26,9,1,1,1,
  	0,0,2,0,2,0,0,30,0,5,1,0,0,0,2,19,1,0,0,0,4,6,5,5,0,0,5,4,1,0,0,0,5,6,
  	1,0,0,0,6,9,1,0,0,0,7,8,5,1,0,0,8,10,5,5,0,0,9,7,1,0,0,0,9,10,1,0,0,0,
  	10,13,1,0,0,0,11,12,5,2,0,0,12,14,5,5,0,0,13,11,1,0,0,0,13,14,1,0,0,0,
  	14,17,1,0,0,0,15,16,5,3,0,0,16,18,5,5,0,0,17,15,1,0,0,0,17,18,1,0,0,0,
  	18,1,1,0,0,0,19,24,3,0,0,0,20,21,5,4,0,0,21,23,3,0,0,0,22,20,1,0,0,0,
  	23,26,1,0,0,0,24,22,1,0,0,0,24,25,1,0,0,0,25,3,1,0,0,0,26,24,1,0,0,0,
  	5,5,9,13,17,24
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  polynomialantlrParserStaticData = std::move(staticData);
}

}

PolynomialANTLRParser::PolynomialANTLRParser(TokenStream *input) : PolynomialANTLRParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PolynomialANTLRParser::PolynomialANTLRParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PolynomialANTLRParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *polynomialantlrParserStaticData->atn, polynomialantlrParserStaticData->decisionToDFA, polynomialantlrParserStaticData->sharedContextCache, options);
}

PolynomialANTLRParser::~PolynomialANTLRParser() {
  delete _interpreter;
}

const atn::ATN& PolynomialANTLRParser::getATN() const {
  return *polynomialantlrParserStaticData->atn;
}

std::string PolynomialANTLRParser::getGrammarFileName() const {
  return "PolynomialANTLR.g4";
}

const std::vector<std::string>& PolynomialANTLRParser::getRuleNames() const {
  return polynomialantlrParserStaticData->ruleNames;
}

const dfa::Vocabulary& PolynomialANTLRParser::getVocabulary() const {
  return polynomialantlrParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PolynomialANTLRParser::getSerializedATN() const {
  return polynomialantlrParserStaticData->serializedATN;
}


//----------------- Monomial_ruleContext ------------------------------------------------------------------

PolynomialANTLRParser::Monomial_ruleContext::Monomial_ruleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PolynomialANTLRParser::Monomial_ruleContext::NUM() {
  return getTokens(PolynomialANTLRParser::NUM);
}

tree::TerminalNode* PolynomialANTLRParser::Monomial_ruleContext::NUM(size_t i) {
  return getToken(PolynomialANTLRParser::NUM, i);
}


size_t PolynomialANTLRParser::Monomial_ruleContext::getRuleIndex() const {
  return PolynomialANTLRParser::RuleMonomial_rule;
}


std::any PolynomialANTLRParser::Monomial_ruleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialANTLRVisitor*>(visitor))
    return parserVisitor->visitMonomial_rule(this);
  else
    return visitor->visitChildren(this);
}

PolynomialANTLRParser::Monomial_ruleContext* PolynomialANTLRParser::monomial_rule() {
  Monomial_ruleContext *_localctx = _tracker.createInstance<Monomial_ruleContext>(_ctx, getState());
  enterRule(_localctx, 0, PolynomialANTLRParser::RuleMonomial_rule);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(5);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PolynomialANTLRParser::NUM) {
      setState(4);
      match(PolynomialANTLRParser::NUM);
    }
    setState(9);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PolynomialANTLRParser::T__0) {
      setState(7);
      match(PolynomialANTLRParser::T__0);
      setState(8);
      match(PolynomialANTLRParser::NUM);
    }
    setState(13);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PolynomialANTLRParser::T__1) {
      setState(11);
      match(PolynomialANTLRParser::T__1);
      setState(12);
      match(PolynomialANTLRParser::NUM);
    }
    setState(17);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PolynomialANTLRParser::T__2) {
      setState(15);
      match(PolynomialANTLRParser::T__2);
      setState(16);
      match(PolynomialANTLRParser::NUM);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Polynomial_ruleContext ------------------------------------------------------------------

PolynomialANTLRParser::Polynomial_ruleContext::Polynomial_ruleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PolynomialANTLRParser::Monomial_ruleContext *> PolynomialANTLRParser::Polynomial_ruleContext::monomial_rule() {
  return getRuleContexts<PolynomialANTLRParser::Monomial_ruleContext>();
}

PolynomialANTLRParser::Monomial_ruleContext* PolynomialANTLRParser::Polynomial_ruleContext::monomial_rule(size_t i) {
  return getRuleContext<PolynomialANTLRParser::Monomial_ruleContext>(i);
}


size_t PolynomialANTLRParser::Polynomial_ruleContext::getRuleIndex() const {
  return PolynomialANTLRParser::RulePolynomial_rule;
}


std::any PolynomialANTLRParser::Polynomial_ruleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialANTLRVisitor*>(visitor))
    return parserVisitor->visitPolynomial_rule(this);
  else
    return visitor->visitChildren(this);
}

PolynomialANTLRParser::Polynomial_ruleContext* PolynomialANTLRParser::polynomial_rule() {
  Polynomial_ruleContext *_localctx = _tracker.createInstance<Polynomial_ruleContext>(_ctx, getState());
  enterRule(_localctx, 2, PolynomialANTLRParser::RulePolynomial_rule);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(19);
    monomial_rule();
    setState(24);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PolynomialANTLRParser::T__3) {
      setState(20);
      match(PolynomialANTLRParser::T__3);
      setState(21);
      monomial_rule();
      setState(26);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void PolynomialANTLRParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  polynomialantlrParserInitialize();
#else
  ::antlr4::internal::call_once(polynomialantlrParserOnceFlag, polynomialantlrParserInitialize);
#endif
}
