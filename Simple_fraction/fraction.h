#pragma once
#include <iostream>

//
//- конструктор (по умолчанию + как минимум один конструктор с параметрами);
//-установление / получение числителя / знаменателя дроби;
//-арифметические операции между дробями(+, -, *, / ).Могут быть реализованы в виде перегрузок или обычных методов;
//-операции сравнения(> , < , == , != ).Могут быть реализованы в виде перегрузок или обычных методов;
//-приведение дроби к несократимой(допускается как в виде публичного, так и закрытого метода, при условии, что закрытый метод вызывается при операциях, результатом которых может быть сократимая дробь);
//-ввод / вывод дроби в консоль;
//-как минимум два уникальных собственных метода на ваше усмотрение(пример: конвертация из double в обыкновенную дробь(с указанием точности(количества значащих знаков после запятой))).
//


class Fraction
{
public: 

	Fraction() // конструктор по умолчанию
	{
		m_numerator = 0;
		m_denominator = 1;
	}

	Fraction(int n, int d = 1) // констурток с параметрами - числитель и знаментель(по умочанию 1)
	{
		m_numerator = n;
		m_denominator = d;
	}


	int GetNumerator() const { return m_numerator; }								// возвращает числитель
	void SetNumerator(int numerator) { m_numerator = numerator; }					// устанавливает числитель
	int GetDenomirator() const { return m_denominator; }							// возвращает знаменатель
	void SetDenomirator(int denominator) { m_denominator = denominator; }			// устанавливает знаменатель

	Fraction operator+(const Fraction& second_operand);	// перегрузка операции сложения
	Fraction operator-(const Fraction& second_operand);	// перегрузка операции вычитания
	Fraction operator*(const Fraction& second_operand);	// перегрузка операции умножения
	Fraction operator/(const Fraction& second_operand);	// перегрузка операции деления

	bool operator>(const Fraction& second_operand);		// перегрузка операции >
	bool operator<(const Fraction& second_operand);		// перегрузка операции <
	bool operator==(const Fraction& second_operand);	// перегрузка операции ==
	bool operator!=(const Fraction& second_operand);	// перегрузка операции !=

	friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);	// перегрузка оператора вывода
	friend std::istream& operator>>(std::istream& in, Fraction& frac);	// перегрузка оператора ввода

	void MakeSimple(double item, int precision);	// создание простой дроби из числа с плавающей точкой
	float GetFloat() const { return static_cast<float>(m_numerator) / static_cast<float>(m_denominator); }	// возвращает число с плавающей точкой на основе простой дроби


private:

	void Reduce();		// сокращает дробь до не сократимой

private:

	int m_numerator;	// числитель
	int m_denominator;	// знаменатель
};