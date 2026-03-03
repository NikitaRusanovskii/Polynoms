#include <Polynomial.hpp>
#include <Tools.hpp>

#if USE_SKIP_LIST
using List = SkipList<Monomial>;
using Iterator = SkipListIterator<Monomial>;
#else
using List = LinkedList<Monomial>;
using Iterator = LinkedListIterator<Monomial>;
#endif

Polynomial::Polynomial(Monomial m)
{
	add_monomial(m);
}

bool Polynomial::monomial_comparator(Monomial a, Monomial b)
{
	return a >= b;
}

void Polynomial::add_monomial(Monomial m)
{
	monomials.ordered_push(m, monomial_comparator);
}

void Polynomial::add(double coefficient, signed char x_degree, signed char y_degree,
					 signed char z_degree)
{
	add_monomial(Monomial(coefficient, x_degree, y_degree, z_degree));
}

double Polynomial::solve()
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

Polynomial operator+(Polynomial &p1, Monomial &m1)
{
	if (p1.size() == 0)
		return (Polynomial)m1;

	Polynomial result;
	Iterator iter = p1.iterator();

	while (!iter.end())
	{
		Monomial current = iter.current();
		if (current == m1)
		{
			result.add_monomial(m1 + current);
			iter.next();
		}
		else if (m1 > current)
		{
			result.add_monomial(m1);
		}
		else if (m1 < current)
		{
			result.add_monomial(current);
			iter.next();
		}
	}

	return result;
}

Polynomial operator-(Polynomial &p1, Monomial &m1)
{
	if (p1.size() == 0)
		return (Polynomial)m1;

	Polynomial result;
	Iterator iter = p1.iterator();

	while (!iter.end())
	{
		Monomial current = iter.current();
		if (current == m1)
		{
			result.add_monomial(m1 - current);
			iter.next();
		}
		else if (m1 > current)
		{
			result.add_monomial(m1);
		}
		else if (m1 < current)
		{
			result.add_monomial(current);
			iter.next();
		}
	}

	return result;
}

Polynomial operator*(Polynomial &p1, Monomial &m1)
{
	if (p1.size() == 0)
		return (Polynomial)m1;

	Polynomial result;
	Iterator iter = p1.iterator();

	while (!iter.end())
	{
		Monomial current = iter.current();
		result.add_monomial(current * m1);
		iter.next();
	}

	return result;
}

Polynomial operator+(Polynomial &p1, Polynomial &p2)
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
			result.add_monomial(m1 + m2);
			it1.next();
			it2.next();
		}
		else if (m1 > m2)
		{
			result.add_monomial(m1);
			it1.next();
		}
		else
		{
			result.add_monomial(m2);
			it2.next();
		}
	}
	while (!it1.end())
	{
		result.add_monomial(it1.current());
		it1.next();
	}
	while (!it2.end())
	{
		result.add_monomial(it2.current());
		it2.next();
	}

	return result;
}

Polynomial operator-(Polynomial &p1, Polynomial &p2)
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
			result.add_monomial(m1 - m2);
			it1.next();
			it2.next();
		}
		else if (m1 > m2)
		{
			result.add_monomial(m1);
			it1.next();
		}
		else
		{
			result.add_monomial(m2);
			it2.next();
		}
	}
	while (!it1.end())
	{
		result.add_monomial(it1.current());
		it1.next();
	}
	while (!it2.end())
	{
		result.add_monomial(it2.current());
		it2.next();
	}

	return result;
}

Polynomial operator*(Polynomial &p1, Polynomial &p2)
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
	}

	return result;
}
Polynomial Polynomial::operator+=(Polynomial &p1)
{
	return operator+(*this, p1);
}
Polynomial Polynomial::operator-=(Polynomial &p1)
{
	return operator-(*this, p1);
}
Polynomial Polynomial::operator*=(Polynomial &p1)
{
	return operator*(*this, p1);
}

std::ostream &operator<<(std::ostream &ostr, Polynomial &p)
{
	Iterator iter = p.iterator();
	if (!iter.end())
	{
		ostr << iter.current();
		iter.next();
		while (!iter.end())
		{
			ostr << " + " << iter.current();
			iter.next();
		}

		ostr << std::endl;
	}
	return ostr;
}

size_t Polynomial::size()
{
	return monomials.size();
}

Iterator Polynomial::iterator()
{
	return monomials.iterator();
}
