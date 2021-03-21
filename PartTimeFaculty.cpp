#include "PartTimeFaculty.h"
#include <string>
#include <vector>
#include <time.h>

std::vector<int> partTimeFacultyPinNumbers;

PartTimeFaculty::PartTimeFaculty() : extraQualification("None") {};


PartTimeFaculty::PartTimeFaculty(std::string employer, float workExperienceInYears, float salary, std::string extraQualification)
	: Employee(employer, workExperienceInYears, salary) {

	this->extraQualification = extraQualification;
	this->pin = generatePin();
}

std::string PartTimeFaculty::getPartTimeFacultyQualification() {
	return extraQualification;
}

std::string PartTimeFaculty::generatePin() {

	std::string partTimeTag = "PT";
	std::string partTimePin = ""; // empty string to save characters
	
	const char alphanum[] = "0123456789"; // values for PIN
	int string_length = sizeof(alphanum) - 1;
	//srand((unsigned)time(NULL)); // generate srand random seed 

	for (int i = 0; i < 9; i++) {
		partTimePin = partTimePin + alphanum[rand() % string_length];// save characters to string
	}

	partTimePin = partTimeTag + partTimePin; // Part time Faculty PIN 

	return partTimePin;
}
