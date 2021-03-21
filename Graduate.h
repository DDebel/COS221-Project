#pragma once
#include "Student.h"
#include <string>


class Graduate : public Student {
private:
	std::string degreeAfterBachelors;

public:

	Graduate();

	Graduate(std::string standing, std::string major, std::string university, int beganStudyYear, float gpa, std::string degreeAfterBachelors);

	using Student::Student;

	std::string getGraduateDegree();

	std::string generatePin();
};