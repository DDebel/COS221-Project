#pragma once
#include <string>
#include <vector>

class Person {
protected:	
	std::string firstName;
	std::string lastName;
	int age;
	std::string country;
	std::string pin;

public:
	Person();

	Person(std::string firstName, std::string lastName, int age, std::string country);

	virtual std::string generatePin() = 0;

	std::string getPersonPIN();
};