#include <persons/Juanito.h>
#include <persons/Pepita.h>



std::string whatIsYourNameByRef(Person& __p) // note the &
{
	__p.setAge(0); // modifies the external value

	// return __p.name__; // access a protected member, compilation error
	return __p.getName(); // good practice, access classs members with get/set functions
}

std::string whatIsYourNameByCopy(Person __p) // note the absence of the &
{
	__p.setAge(0); // modifies the local copy

	// return __p.name__; // access a protected member, compilation error
	return __p.getName(); // good practice, access classs members with get/set functions

	// also, see in the screen that there is a dead, that's the local copy being destroid
}

int main()
{
	Person bob;
	bob.setAge(34);

	std::cout << "My name is " << whatIsYourNameByCopy(bob) << std::endl;
	std::cout << "And I'm " << bob.getAge() << " years old" << std::endl;

	std::cout << "My name is " << whatIsYourNameByRef(bob) << std::endl;
	std::cout << "And I'm " << bob.getAge() << " years old" << std::endl;

	std::cout << "That's all with " << bob.getName();
	std::cout << ", as he'll die when the program terminates, after John is born..." << std::endl;

	Person john("John");

	return 0;

	// see in the screen both bob and john being dead
}
