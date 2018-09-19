#ifndef ___PERSONS___JUANITO_H___
#define ___PERSONS___JUANITO_H___

#include <persons/NamedPerson.h>

class Juanito : public NamedPerson
{
public:
	Juanito() :
		NamedPerson("Juanito")
	{
		my_secret_phrase__ = "All Juanito's will rule the world";
	}

	std::string tellMySecretPhrase();

protected:
	std::string tellJuanitoSecretePhrase();

private:
	std::string my_secret_phrase__;
};

#endif
