#include "persons/Person.h"

Person::Person()
{
	std::cout << "I'm born with no name, so I'm gonna call myself Bob" << std::endl;
	name__ = "Bob";
}

Person::Person(std::string name) :
	name__(name)
{
	std::cout << "I'm born as " << name__ << std::endl;
}

Person::~Person()
{
	std::cout << name__ <<  " is dead" << std::endl;
}
