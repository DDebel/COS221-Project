#pragma once
#include "Student.h"
#include <string>

class Undergraduate : public Student {

	std::string bachelorsDegree;

public:

	Undergraduate();

	Undergraduate(std::string standing, std::string major, std::string university, int beganStudyYear, float gpa, std::string bachelorsDegree);

	std::string getUnderGraduateBachelorDegree();

	std::string generatePin();
};