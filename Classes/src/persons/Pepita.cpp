#include <persons/Pepita.h>

// Implementation of pure virtual function
std::string Pepita::tellMySecretPhrase()
{
	return tellPepitaSecretePhrase();
}

// protected member that has access to private members too
std::string Pepita::tellPepitaSecretePhrase()
{
	return my_secret_phrase__;
}
