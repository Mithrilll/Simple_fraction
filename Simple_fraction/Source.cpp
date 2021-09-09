#include <iostream>
#include "fraction.h"

int main()
{
	Fraction f(1, 3);
	Fraction f2(9, 3);

	std::cout << "Frist fraction: ";
	f.Print();
	std::cout << std::endl;
	std::cout << "Second fraction: ";
	f2.Print();
	std::cout << std::endl;

	f.Print();
	std::cout << " + ";
	f2.Print();
	std::cout << " = ";
	(f + f2).Print();
	std::cout << std::endl;

	f.Print();
	std::cout << " - ";
	f2.Print();
	std::cout << " = ";
	(f - f2).Print();
	std::cout << std::endl;

	f.Print();
	std::cout << " * ";
	f2.Print();
	std::cout << " = ";
	(f * f2).Print();
	std::cout << std::endl;

	f.Print();
	std::cout << " / ";
	f2.Print();
	std::cout << " = ";
	(f / f2).Print();
	std::cout << std::endl;


	if (f < f2)
	{
		f.Print();
		std::cout << " < ";
		f2.Print();
		std::cout << std::endl;
	}
	else if (f > f2)
	{
		f.Print();
		std::cout << " > ";
		f2.Print();
		std::cout << std::endl;
	}
	else
	{
		f.Print();
		std::cout << " = ";
		f2.Print();
		std::cout << std::endl;
	}

	std::cout << "First fraction: " << f.GetFloat() << std::endl;
	std::cout << "Second fraction: " << f2.GetFloat() << std::endl;

	return 0;
}