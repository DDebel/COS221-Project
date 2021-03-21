#include <string>
#include <iostream>
#include <vector>
#include "Graduate.h"


std::vector<int> graduatePin;

Graduate::Graduate() : degreeAfterBachelors("") {};

Graduate::Graduate(std::string standing, std::string major, std::string university, int beganStudyYear, float gpa, std::string degreeAfterBachelors)
	: Student(standing, major, university, beganStudyYear, gpa) {

	this->degreeAfterBachelors = degreeAfterBachelors;
	this->beganStudyYear = beganStudyYear;
	this->pin = generatePin();
};

std::string Graduate::getGraduateDegree() {
	return degreeAfterBachelors;
}

 std::string Graduate::generatePin() {

	 std::string year = std::to_string(beganStudyYear);
	 std::string graduatePin = ""; // empty string to save characters
	 std::string uniqueLastFourCharacters = "";

	const char alphanum[] = "0123456789"; // values for PIN
	int string_length = sizeof(alphanum) - 1;

	//srand(time(0)); // generate srand random seed 
	for (int i = 0; i < 2; i++) {
		// save first two random characters to graduate PIN 
		graduatePin = graduatePin + std::to_string(rand() % string_length);
	}

	for (int i = 0; i < 4; i++) {
		// generate last four characters
		uniqueLastFourCharacters = uniqueLastFourCharacters + std::to_string(rand() % string_length);
	}

	graduatePin = year + graduatePin + uniqueLastFourCharacters; // Year + pin + last 4 unique characters
	return graduatePin;
}