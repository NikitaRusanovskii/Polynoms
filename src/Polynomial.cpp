#include <Polynomial.hpp>
#include <Tools.hpp>
#include <PolynomialANTLRLexer.h>
#include <PolynomialANTLRParser.h>
#include <GrammarVisitor.hpp>
#include <antlr4-runtime.h>

#if USE_SKIP_LIST
using List = SkipList<Monomial>;
using Iterator = SkipListIterator<Monomial>;
#else
using List = LinkedList<Monomial>;
using Iterator = LinkedListIterator<Monomial>;
#endif

using namespace antlr4;

Polynomial::Polynomial(Monomial m)
{
	push_back(m);
}

Polynomial::Polynomial(std::string polynomial_in_text)
{
	std::string input = polynomial_in_text;
	ANTLRInputStream inputStream(input);
	PolynomialANTLRLexer lexer(&inputStream);
	CommonTokenStream tokens(&lexer);
	PolynomialANTLRParser parser(&tokens);

	tree::ParseTree *tree = parser.polynomial_rule();

	if (parser.getNumberOfSyntaxErrors() > 0)
	{
		std::cerr << "Syntax error!" << std::endl;
	}

	GrammarVisitor gr;
	gr.visit(tree);
    *this = gr.get();
}

bool Polynomial::monomial_comparator(std::variant<Infinity, Monomial> a,
									 std::variant<Infinity, Monomial> b)
{
	return a > b;
}

void Polynomial::add_monomial(Monomial m)
{
	monomials.ordered_push(m, monomial_comparator);
}

void Polynomial::push_back(Monomial m)
{
	monomials.push_back(m);
}

void Polynomial::add(double coefficient, signed char x_degree, signed char y_degree,
					 signed char z_degree)
{
	add_monomial(Monomial(coefficient, x_degree, y_degree, z_degree));
}

void Polynomial::add(const Monomial& m)
{
	add_monomial(m);
}


double Polynomial::solve(double x, double y, double z) const
{
	double result = 0.0;
	Iterator iter = monomials.iterator();
	while (!iter.end())
	{
		result += (iter.current()).solve(x, y, z);
		iter.next();
	}
	return result;
}

Polynomial operator+(const Polynomial &p1, const Monomial &m1)
{
	if (p1.size() == 0)
		return (Polynomial)m1;

	Polynomial result;
	Iterator iter = p1.iterator();

	bool m1_used = false;
	while (!iter.end())
	{
		Monomial current = iter.current();
		if (current == m1)
		{
			result.push_back(m1 + current);
			m1_used = true;
			iter.next();
		}
		else if (m1 < current && !m1_used) //
		{
			result.push_back(m1);
			m1_used = true;
		}
		else if (m1 > current) //
		{
			result.push_back(current);
			iter.next();
		}
	}
	if (!m1_used)
	{
		result.push_back(m1);
	}

	return result;
}

Polynomial operator-(const Polynomial &p1, const Monomial &m1)
{
	if (p1.size() == 0)
		return (Polynomial)m1;

	Polynomial result;
	Iterator iter = p1.iterator();

	bool m1_used = false;
	while (!iter.end())
	{
		Monomial current = iter.current();
		if (current == m1)
		{
			result.push_back(m1 - current);
			iter.next();
			m1_used = true;
		}
		else if (m1 < current && !m1_used) //
		{
			result.push_back(m1);
			m1_used = true;
		}
		else if (m1 > current) //
		{
			result.push_back(current);
			iter.next();
		}
	}
	if (!m1_used)
	{
		result.push_back(m1);
	}
	return result;
}

Polynomial operator*(const Polynomial &p1, const Monomial &m1)
{
	if (p1.size() == 0)
		return (Polynomial)m1;

	Polynomial result;
	Iterator iter = p1.iterator();

	while (!iter.end())
	{
		Monomial current = iter.current();
		result.push_back(current * m1);
		iter.next();
	}

	return result;
}

Polynomial operator+(const Polynomial &p1, const Polynomial &p2)
{
	auto it1 = p1.iterator();
	auto it2 = p2.iterator();

	Polynomial result;

	while (!it1.end() && !it2.end())
	{
		Monomial m1 = it1.current();
		Monomial m2 = it2.current();
		if (m1 == m2)
		{
			result.push_back(m1 + m2);
			it1.next();
			it2.next();
		}
		else if (m1 < m2) //
		{
			result.push_back(m1);
			it1.next();
		}
		else
		{
			result.push_back(m2);
			it2.next();
		}
	}
	while (!it1.end())
	{
		result.push_back(it1.current());
		it1.next();
	}
	while (!it2.end())
	{
		result.push_back(it2.current());
		it2.next();
	}

	return result;
}

Polynomial operator-(const Polynomial &p1, const Polynomial &p2)
{
	auto it1 = p1.iterator();
	auto it2 = p2.iterator();

	Polynomial result;

	while (!it1.end() && !it2.end())
	{
		Monomial m1 = it1.current();
		Monomial m2 = it2.current();
		if (m1 == m2)
		{
			result.push_back(m1 - m2);
			it1.next();
			it2.next();
		}
		else if (m1 < m2) //
		{
			result.push_back(m1);
			it1.next();
		}
		else
		{
			result.push_back(m2);
			it2.next();
		}
	}
	while (!it1.end())
	{
		result.push_back(it1.current());
		it1.next();
	}
	while (!it2.end())
	{
		result.push_back(it2.current());
		it2.next();
	}

	return result;
}

Polynomial operator*(const Polynomial &p1, const Polynomial &p2)
{
	if (p1.size() == 0 || p2.size() == 0)
		return Polynomial(Monomial(0));

	Polynomial result;
	Iterator iter_p1 = p1.iterator();
	Iterator iter_p2 = p2.iterator();

	while (!iter_p1.end())
	{
		Monomial current = iter_p1.current();
		iter_p1.next();
		Polynomial mul = p2 * current;
		result = result + mul;
		// std::cout << "temp_result: " << result;
	}
	return result;
}
Polynomial Polynomial::operator+=(const Polynomial &p1)
{
	*this = *this + p1;
	return *this;
}
Polynomial Polynomial::operator-=(const Polynomial &p1)
{
	*this = *this - p1;
	return *this;
}
Polynomial Polynomial::operator*=(const Polynomial &p1)
{
	*this = *this * p1;
	return *this;
}

Polynomial Polynomial::operator+=(const Monomial &m1)
{
	*this = *this + m1;
	return *this;
}
Polynomial Polynomial::operator-=(const Monomial &m1)
{
	*this = *this - m1;
	return *this;
}
Polynomial Polynomial::operator*=(const Monomial &m1)
{
	*this = *this * m1;
	return *this;
}

std::ostream &operator<<(std::ostream &ostr, const Polynomial &p)
{
	ostr << p.monomials;
	return ostr;
}

size_t Polynomial::size() const
{
	return monomials.size();
}

Iterator Polynomial::iterator() const
{
	return monomials.iterator();
}
