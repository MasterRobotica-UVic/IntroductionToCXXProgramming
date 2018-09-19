#ifndef ___PERSONS___PEPITA_H___
#define ___PERSONS___PEPITA_H___

#include <persons/NamedPerson.h>

class Pepita : public NamedPerson
{
public:
	Pepita() :
		NamedPerson("Pepita")
	{
		my_secret_phrase__ = "All Pepita's will rule the world";
	}

	std::string tellMySecretPhrase();

protected:
	std::string tellPepitaSecretePhrase();

private:
	std::string my_secret_phrase__;
};

#endif
