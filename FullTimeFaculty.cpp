#include "FullTimeFaculty.h"
#include <string>
#include <vector>
#include <time.h>

std::vector<int> fullTimeFacultyPinNumbers;

FullTimeFaculty::FullTimeFaculty() : recognizedAwards("None") {};


FullTimeFaculty::FullTimeFaculty(std::string employer, float workExperienceInYears, float salary, std::string recognizedAwards)
	: Employee(employer, workExperienceInYears, salary) {

	this->recognizedAwards = recognizedAwards;
	this->employer = employer;
	this->pin = generatePin();
}

std::string FullTimeFaculty::getFullTimeFacultyAward() {
	return recognizedAwards;
}

std::string FullTimeFaculty::generatePin() {
	std::string fullTimeTag = "FT";
	std::string fullTimePin = ""; // empty string to save characters
	std::string employerName = employer;

	const char alphanum[] = "0123456789"; // values for PIN
	int string_length = sizeof(alphanum) - 1;
	//srand((unsigned)time(NULL)); // generate srand random seed 

	for (int i = 0; i < 9; i++) {
		fullTimePin = fullTimePin + alphanum[rand() % string_length];// save characters to string
	}
	fullTimePin = fullTimeTag + fullTimePin; // Full time Faculty PIN code

	return fullTimePin;
}