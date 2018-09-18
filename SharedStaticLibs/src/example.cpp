#include <iostream>
#include "functions.h"
#include "constants.h"

int main()
{
	std::cout << "Value of CURRENT_YEAR is in file constants.h : " << CURRENT_YEAR << std::endl;
	std::cout << "Value of CURRENT_YEAR is read via a method in functions.cpp : " << getCurrentYear() << std::endl;
	return 0;
}
