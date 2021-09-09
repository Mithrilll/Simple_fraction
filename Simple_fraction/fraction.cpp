#include "fraction.h"
#include <iostream>
#include <algorithm>

Fraction operator+(const Fraction& item1, const Fraction& item2)
{
	Fraction f(item1.m_numerator * item2.m_denomirator + item2.m_numerator * item1.m_denomirator, item1.m_denomirator * item2.m_denomirator);
	f.Reduce();

	return f;
}

Fraction operator-(const Fraction& item1, const Fraction& item2)
{
	Fraction f(item1.m_numerator * item2.m_denomirator - item2.m_numerator * item1.m_denomirator, item1.m_denomirator * item2.m_denomirator);
	f.Reduce();

	return f;
}

Fraction operator*(const Fraction& item1, const Fraction& item2)
{
	Fraction f(item1.m_numerator * item2.m_numerator, item1.m_denomirator * item2.m_denomirator);
	f.Reduce();

	return f;
}

Fraction operator/(const Fraction& item1, const Fraction& item2)
{
	Fraction f(item1.m_numerator * item2.m_denomirator, item1.m_denomirator * item2.m_numerator);
	f.Reduce();

	return f;
}

bool operator>(const Fraction& item1, const Fraction& item2)
{
	return (static_cast<float>(item1.m_numerator) / static_cast<float>(item1.m_denomirator)) > (static_cast<float>(item2.m_numerator) / static_cast<float>(item2.m_denomirator));
}

bool operator<(const Fraction& item1, const Fraction& item2)
{
	return (static_cast<float>(item1.m_numerator) / static_cast<float>(item1.m_denomirator)) < (static_cast<float>(item2.m_numerator) / static_cast<float>(item2.m_denomirator));
}

bool operator==(const Fraction& item1, const Fraction& item2)
{
	return (static_cast<float>(item1.m_numerator) / static_cast<float>(item1.m_denomirator)) == (static_cast<float>(item2.m_numerator) / static_cast<float>(item2.m_denomirator));
}

bool operator!=(const Fraction& item1, const Fraction& item2)
{
	return (static_cast<float>(item1.m_numerator) / static_cast<float>(item1.m_denomirator)) != (static_cast<float>(item2.m_numerator) / static_cast<float>(item2.m_denomirator));
}

void Fraction::Print()
{
	std::cout << this->m_numerator << "/" << this->m_denomirator;
}

void Fraction::MakeSimple(double item, int precision)
{
	this->m_numerator = static_cast<int>(item * pow(10, precision));
	this->m_denomirator = static_cast<int>(pow(10, precision));
	this->Reduce();
}

void Fraction::Reduce()
{
	int n = this->m_numerator;
	int d = this->m_denomirator;
	while (d) {
		n %= d;
		std::swap(n, d);
	}

	this->m_numerator /= n;
	this->m_denomirator /= n;

	if (this->m_denomirator < 0)
	{
		this->m_numerator *= -1;
		this->m_denomirator *= -1;
	}

}
