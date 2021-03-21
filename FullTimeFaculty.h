#pragma once
#include "Employee.h"
#include <string>

class FullTimeFaculty : public Employee {
private:

	std::string recognizedAwards;

public:
	FullTimeFaculty();

	FullTimeFaculty(std::string employer, float workExperienceInYears, float salary, std::string recognizedAwards);

	std::string getFullTimeFacultyAward();

	std::string generatePin();
};