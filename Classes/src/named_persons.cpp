#include <persons/Juanito.h>
#include <persons/Pepita.h>

int main()
{
	Juanito this_juanito;
	Pepita this_pepita;
	Juanito another_juanito;
	Person bob;

	this_juanito.setAge(35);
	another_juanito.setAge(26);
	this_pepita.setAge(58);
	bob.setAge(58);

	std::cout << std::endl; // one space

	std::cout << "This Juanito secret phrase is: " << this_juanito.tellMySecretPhrase() << std::endl;
	std::cout << "This Pepita secret phrase is: " << this_pepita.tellMySecretPhrase() << std::endl;

	std::cout << std::endl; // one space
}
