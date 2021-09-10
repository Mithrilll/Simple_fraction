#include "fraction.h"
#include <iostream>
#include <algorithm>
#include <string>

Fraction Fraction::operator+(const Fraction& second_operand)
{
	Fraction f(this->m_numerator * second_operand.m_denominator + second_operand.m_numerator * this->m_denominator, this->m_denominator * second_operand.m_denominator);
	f.Reduce();

	return f;
}

Fraction Fraction::operator-(const Fraction& second_operand)
{
	Fraction f(this->m_numerator * second_operand.m_denominator - second_operand.m_numerator * this->m_denominator, this->m_denominator * second_operand.m_denominator);
	f.Reduce();

	return f;
}

Fraction Fraction::operator*(const Fraction& second_operand)
{
	Fraction f(this->m_numerator * second_operand.m_numerator, this->m_denominator * second_operand.m_denominator);
	f.Reduce();

	return f;
}

Fraction Fraction::operator/(const Fraction& second_operand)
{
	Fraction f(this->m_numerator * second_operand.m_denominator, this->m_denominator * second_operand.m_numerator);
	f.Reduce();

	return f;
}

bool Fraction::operator>(const Fraction& second_operand)
{
	return (static_cast<float>(this->m_numerator) / static_cast<float>(this->m_denominator)) > (static_cast<float>(second_operand.m_numerator) / static_cast<float>(second_operand.m_denominator));
}

bool Fraction::operator<(const Fraction& second_operand)
{
	return (static_cast<float>(this->m_numerator) / static_cast<float>(this->m_denominator)) < (static_cast<float>(second_operand.m_numerator) / static_cast<float>(second_operand.m_denominator));
}

bool Fraction::operator==(const Fraction& second_operand)
{
	return (static_cast<float>(this->m_numerator) / static_cast<float>(this->m_denominator)) == (static_cast<float>(second_operand.m_numerator) / static_cast<float>(second_operand.m_denominator));
}

bool Fraction::operator!=(const Fraction& second_operand)
{
	return (static_cast<float>(this->m_numerator) / static_cast<float>(this->m_denominator)) != (static_cast<float>(second_operand.m_numerator) / static_cast<float>(second_operand.m_denominator));
}

void Fraction::MakeSimple(double item, int precision)
{
	this->m_numerator = static_cast<int>(item * pow(10, precision));
	this->m_denominator = static_cast<int>(pow(10, precision));
	this->Reduce();
}

void Fraction::Reduce()
{
	int n = this->m_numerator;
	int d = this->m_denominator;
	while (d) {
		n %= d;
		std::swap(n, d);
	}

	this->m_numerator /= n;
	this->m_denominator /= n;

	if (this->m_denominator < 0)
	{
		this->m_numerator *= -1;
		this->m_denominator *= -1;
	}

}

std::ostream& operator<<(std::ostream& out, const Fraction& frac)
{
	out << frac.m_numerator << "/" << frac.m_denominator;

	return out;
}

std::istream& operator>>(std::istream& in, Fraction& frac)
{
	std::string input;

	in >> input;

	int i = 0;

	frac.m_denominator = 0;

	if (input[i] == '-')
	{
		i++;
		frac.m_numerator = -1 * (input[i]-48);
		i++;
	}
	else
	{
		frac.m_numerator = input[i] - 48;
		i++;
	}

	while (input[i] != '/')
	{
		frac.m_numerator = frac.m_numerator * 10 + (input[i] - 48);
		i++;
	}

	i++;

	while (input[i])
	{
		frac.m_denominator = frac.m_denominator * 10 + (input[i] - 48);
		i++;
	}

	return in;
}
