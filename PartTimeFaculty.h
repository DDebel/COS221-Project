#pragma once
#include "Employee.h"
#include <string>

class PartTimeFaculty : public Employee {
private:
	
	std::string extraQualification;

public:

	PartTimeFaculty();

	PartTimeFaculty(std::string employer, float workExperienceInYears, float salary, std::string extraQualification);

	std::string getPartTimeFacultyQualification();

	std::string generatePin();
};