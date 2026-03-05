#pragma once
#include <Config.hpp>
#include <Monomial.hpp>
#include <iostream>

#if USE_SKIP_LIST
#include <SkipList.hpp>
using List = SkipList<Monomial>;
using Iterator = SkipListIterator<Monomial>;
#else
#include <LinkedList.hpp>
using List = LinkedList<Monomial>;
using Iterator = LinkedListIterator<Monomial>;
#endif

class Polynomial
{
  private:
	List monomials;

	static bool monomial_comparator(std::variant<Infinity, Monomial> a,
									std::variant<Infinity, Monomial> b);
	void add_monomial(Monomial m);

  public:
	void add(double coefficient = 0, signed char x_degree = 0, signed char y_degree = 0,
			 signed char z_degree = 0);
	double solve(double x = 0.0, double y = 0.0, double z = 0.0);

	friend Polynomial operator+(const Polynomial &p1, const Monomial &m1);
	friend Polynomial operator-(const Polynomial &p1, const Monomial &m1);
	friend Polynomial operator*(const Polynomial &p1, const Monomial &m1);

	friend Polynomial operator+(const Polynomial &p1, const Polynomial &p2);
	friend Polynomial operator-(const Polynomial &p1, const Polynomial &p2);
	friend Polynomial operator*(const Polynomial &p1, const Polynomial &p2);
	Polynomial operator+=(Monomial &m1);
	Polynomial operator-=(Monomial &m1);
	Polynomial operator*=(Monomial &m1);
	Polynomial operator+=(Polynomial &p1);
	Polynomial operator-=(Polynomial &p1);
	Polynomial operator*=(Polynomial &p1);

	friend std::ostream &operator<<(std::ostream &ostr, const Polynomial &p);

	size_t size() const;
	Iterator iterator() const;

	Polynomial()
	{
	}
	Polynomial(Monomial m);
};