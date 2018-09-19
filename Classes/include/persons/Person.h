#ifndef ___PERSONS___PERSON_H___
#define ___PERSONS___PERSON_H___

#include <iostream>
#include <string>

class Person
{

public:
	Person();
	Person(std::string name);
	~Person();

	std::string getName()
	{
		return name__;
	}

	void setName(std::string __n)
	{
		name__ = __n;
	}

	int getAge()
	{
		return age__;
	}

	void setAge(int __n)
	{
		age__ = __n;
	}

	std::string tellMySecretPhrase();

protected:
	std::string name__;
	int age__;
};

#endif
