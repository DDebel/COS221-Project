#include "Employee.h"
#include <string>
#include <iostream>

Employee::Employee() : employer(""), workExperienceInYears(0), salary(0) {};

Employee::Employee(std::string employer, float workExperienceInYears, float salary) {
	this->employer = employer;
	this->workExperienceInYears = workExperienceInYears;
	this->salary = salary;
}
