#include <persons/Juanito.h>

// Implementation of pure virtual function
std::string Juanito::tellMySecretPhrase()
{
	return tellJuanitoSecretePhrase();
}

// protected member that has access to private members too
std::string Juanito::tellJuanitoSecretePhrase()
{
	return my_secret_phrase__;
}
