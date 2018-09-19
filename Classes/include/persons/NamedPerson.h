#ifndef ___PERSONS___NAMED_PERSON_H___
#define ___PERSONS___NAMED_PERSON_H___

#include <iostream>
#include <string>

#include <persons/Person.h>

class NamedPerson : public Person
{
public:
	NamedPerson(std::string name) :
		Person(name)
	{}

	virtual std::string tellMySecretPhrase() = 0;
};

#endif
