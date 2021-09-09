#include <iostream>
#include "fraction.h"

int main()
{
	Fraction f(1, 2);
	Fraction f2(2, 4);

	f.Print();
	std::cout << std::endl;
	f2.Print();

	f = f + f2;

	std::cout << std::endl;
	f.Print();

	return 0;
}