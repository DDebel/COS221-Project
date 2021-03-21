#include "Student.h"
#include <string>
#include <iostream>

Student::Student() : standing(""), major(""), university(""), beganStudyYear(0), gpa(0) {}

Student::Student(std::string standing, std::string major, std::string university, int beganStudyYear, float gpa) {
	this->standing = standing;
	this->major = major;
	this->university = university;
	this->beganStudyYear = beganStudyYear;
	this->gpa = gpa;
}

//std::string Student::getStudentInformation() {
//	return std::cout << "Standing: " << standing << "\n" 
//		<< "Major: " << major << "\n" 
//		<< "University: " << university << "\n" 
//		<< "Year Started: " << beganStudyYear << "\n" 
//		<< "GPA: " << gpa << "\n";
//}