#include <iostream>
#include "fraction.h"

int main()
{
	Fraction f(1, 3);
	Fraction f2(9, 3);

	std::cout << "Frist fraction: " << f << std::endl;
	std::cout << "Second fraction: " << f2 << std::endl;

	std::cout << "Enter new first fraction: ";
	std::cin >> f;
	std::cout << "Enter new second fraction: ";
	std::cin >> f2;


	std::cout << f << " + " << f2 << " : " << f + f2 << std::endl;
	std::cout << f << " - " << f2 << " : " << f - f2 << std::endl;
	std::cout << f << " * " << f2 << " : " << f * f2 << std::endl;
	std::cout << f << " / " << f2 << " : " << f / f2 << std::endl;

	if (f < f2)
		std::cout << f << " < " << f2 << std::endl;
	else if (f > f2)
		std::cout << f << " > " << f2 << std::endl;
	else
		std::cout << f << " = " << f2 << std::endl;

	std::cout << "First franction as float: " << f.GetFloat() << std::endl;
	std::cout << "Second franction as float: " << f2.GetFloat() << std::endl;

	float in;
	int p;
	std::cout << "Enter float: ";
	std::cin >> in;
	std::cout << "Enter precision: ";
	std::cin >> p;
	f.MakeSimple(in, p);
	std::cout << "Float as simple fraction: " << f << std::endl;

	return 0;
}