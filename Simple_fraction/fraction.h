#pragma once

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
		m_denomirator = 1;
	}

	Fraction(int n, int d = 1) // констурток с параметрами - числитель и знаментель(по умочанию 1)
	{
		m_numerator = n;
		m_denomirator = d;
	}


	int GetNumerator() { return m_numerator; }								// возвращает числитель
	void SetNumerator(int item) { m_numerator = item; }						// устанавливает числитель
	int GetDenomirator() { return m_denomirator; }							// возвращает знаменатель
	void SetDenomirator(int item) { m_denomirator = item; }					// устанавливает знаменатель

	friend Fraction operator+(const Fraction& item1, const Fraction& item2);// перегрузка операции сложения
	friend Fraction operator-(const Fraction& item1, const Fraction& item2);// перегрузка операции вычитания
	friend Fraction operator*(const Fraction& item1, const Fraction& item2);// перегрузка операции умножения
	friend Fraction operator/(const Fraction& item1, const Fraction& item2);// перегрузка операции деления

	friend bool operator>(const Fraction& item1, const Fraction& item2);	// перегрузка операции >
	friend bool operator<(const Fraction& item1, const Fraction& item2);	// перегрузка операции <
	friend bool operator==(const Fraction& item1, const Fraction& item2);	// перегрузка операции ==
	friend bool operator!=(const Fraction& item1, const Fraction& item2);	// перегрузка операции !=

	void Print();	// вывод дроби в консоль

	void MakeSimple(double item, int precision);	// создание простой дроби из числа с плавающей точкой
	float GetFloat() { return static_cast<float>(m_numerator) / static_cast<float>(m_denomirator); }	// возвращает число с плавающей точкой на основе простой дроби


private:

	void Reduce();		// сокращает дробь до не сократимой

private:

	int m_numerator;	// числитель
	int m_denomirator;	// знаменатель
};