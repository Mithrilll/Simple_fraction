#pragma once

class Fraction
{
public: 

	Fraction()
	{
		m_numerator = 0;
		m_denomirator = 1;
	}

	Fraction(int n, int d)
	{
		m_numerator = n;
		m_denomirator = d;
	}


	int GetNumerator() { return m_numerator; }
	void SetNumerator(int item) { m_numerator = item; }
	int GetDenomirator() { return m_denomirator; }
	void SetDenomirator(int item) { m_denomirator = item; }

	friend Fraction operator+(const Fraction& item1, const Fraction& item2);
	friend Fraction operator-(const Fraction& item1, const Fraction& item2);
	friend Fraction operator*(const Fraction& item1, const Fraction& item2);
	friend Fraction operator/(const Fraction& item1, const Fraction& item2);

	friend bool operator>(const Fraction& item1, const Fraction& item2);
	friend bool operator<(const Fraction& item1, const Fraction& item2);
	friend bool operator==(const Fraction& item1, const Fraction& item2);
	friend bool operator!=(const Fraction& item1, const Fraction& item2);

	void Print();

	void MakeSimple(double item, int precision);
	float GetFloat() { return static_cast<float>(m_numerator) / static_cast<float>(m_denomirator); }


private:

	void Reduce();

private:

	int m_numerator;
	int m_denomirator;
};