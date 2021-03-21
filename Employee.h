#pragma once
#include "Person.h"
#include <string>

class Employee : public Person {
protected:
	std::string employer;
	float workExperienceInYears; // <- for example 2 years of work experience
	float salary;

public:
	Employee();

	Employee(std::string employer, float workExperienceInYears, float salary);

};