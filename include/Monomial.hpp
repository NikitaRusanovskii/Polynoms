#pragma once
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <stdint.h>

#define LOWER_BOUND_OF_THE_DEGREE -5
#define HIGHEST_BOUND_OF_THE_DEGREE 10

union Degrees
{
	uint32_t storage = 0;
	signed char degree[4];
};

signed char transform_degree(signed char value);

class Monomial
{
  private:
	double coefficient;
	Degrees degrees;

  public:
	Monomial(double coefficient = 0, signed char x_degree = 0, signed char y_degree = 0,
			 signed char z_degree = 0);

	double solve(double x_value, double y_value, double z_value);

	void change_degree(signed char _degree, int place);
	void change_coefficient(double _coefficient);

	friend int compare(Monomial a, Monomial b);

	friend Monomial operator+(const Monomial &m1, const Monomial &m2);
	friend Monomial operator-(const Monomial &m1, const Monomial &m2);
	friend Monomial operator*(const Monomial &m1, const Monomial &m2);
	friend Monomial operator/(const Monomial &m1, const Monomial &m2);
	friend Monomial operator*(const Monomial &m, double coefficient);
	friend Monomial operator/(const Monomial &m, double coefficient);

	bool operator<(const Monomial &m1) const;
	bool operator>(const Monomial &m1) const;
	bool operator==(const Monomial &m1) const;
	bool operator!=(const Monomial &m1) const;
	bool operator<=(const Monomial &m1) const;
	bool operator>=(const Monomial &m1) const;

	Monomial &operator+=(const Monomial &other);
	Monomial &operator-=(const Monomial &other);
	Monomial &operator*=(const Monomial &other);
	Monomial &operator/=(const Monomial &other);
	Monomial &operator*=(double coefficient);
	Monomial &operator/=(double coefficient);

	signed char operator[](size_t index) const;

	friend std::ostream &operator<<(std::ostream &ostr, const Monomial &m);
};