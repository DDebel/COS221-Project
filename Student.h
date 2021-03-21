#pragma once
#include "Person.h"
#include <string>

class Student : public Person {
protected:

	std::string standing;
	std::string major;
	std::string university;
	int beganStudyYear;
	float gpa;

public:
	Student();

	Student(std::string standing, std::string major, std::string university, int beganStudyYear, float gpa);

};