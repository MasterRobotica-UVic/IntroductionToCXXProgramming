#include <iostream>
#include <string> // powerful standard library to handle with text

int main()
{
	std::string your_name; // decl. and def.
	std::cout << "What is your name: "; // operator <<
	std::cin >> your_name; // assignment with operator >>

	std::cout << "Hi, " << your_name << ", ";
	std::cout << "do you always tell the truth, <yes> or <no>" << std::endl;

	std::string yes_word = "yes"; // decl., def., and assignment
	std::string no_word("no"); // decl. def. and initialization
	int asking_counter = 1; // the "Do you always.." counts as asking one already
	bool good_answer = false;

	while( !good_answer )
	{
		std::string your_answer;
		std::cin >> your_answer;
		if( your_answer == yes_word )
		{
			std::cout << "Good lier!" << std::endl;
			good_answer = true; // assignment
		}
		else if( your_answer.compare(no_word) == 0 )
		{
			std::cout << "Bad lier!" << std::endl;
			good_answer = true;
		}
		else
		{
			if( asking_counter > 2 )
			{
				std::cout << "I asked " << asking_counter << " times already, I guess you are not in the mood. See ya" << std::endl;
				return 34; // typically numbers are used for non-intended termination, as error codes, use $? on the terminal to see
			}
			std::cout << "Don't go around, tell me <yes> or <no>" << std::endl;
			asking_counter++; // sum 1 and assign
		}
	}

	std::cout << "Thanks for being honest. Have a good day " << your_name << "." << std::endl;
	return 0; // typically zero means everything went as expected
}
