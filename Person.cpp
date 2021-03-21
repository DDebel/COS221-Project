#include "Person.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>  

// Default constructor
Person::Person() : firstName(""), lastName(""), age(0), country("") {}


Person::Person(std::string firstName, std::string lastname, int age, std::string country) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->country = country;
	this->pin = getPersonPIN();
}

std::string Person::getPersonPIN() {
	return pin;
}
