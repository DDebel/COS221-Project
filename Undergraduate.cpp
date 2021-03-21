#include <string>
#include <iostream>
#include <vector>
#include "Undergraduate.h"

std::vector<int> undergraduatePin;

Undergraduate::Undergraduate() : bachelorsDegree("") {};

Undergraduate::Undergraduate(std::string standing, std::string major, std::string university, int beganStudyYear, float gpa, std::string bachelorsDegree)
		: Student(standing, major, university, beganStudyYear, gpa) {

	this->bachelorsDegree = bachelorsDegree;
	this->university = university;
	this->pin = generatePin();
}

std::string Undergraduate::getUnderGraduateBachelorDegree() {
	return bachelorsDegree;
}
std::string Undergraduate::generatePin() {

	std::string universityName = university;
	std::string undergraduatePin = ""; // empty string to save characters

	const char alphanum[] = "0123456789"; // values for PIN
	int string_length = sizeof(alphanum) - 1;
	//srand((unsigned)time(NULL)); // generate srand random seed 

	for (int i = 0; i < 6; i++) {
		// generate undergraduatePin last 4 numbers 
		undergraduatePin = undergraduatePin + alphanum[rand() % string_length];
	}

	undergraduatePin = universityName + undergraduatePin; // Graduate University + 4 random at the end
	return undergraduatePin;
}

