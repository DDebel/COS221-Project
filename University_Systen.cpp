#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>

#include "Person.h"
#include "PartTimeFaculty.h"
#include "FullTimeFaculty.h"
#include "Undergraduate.h"
#include "Graduate.h"

std::vector<Graduate*> graduates;
std::vector<Undergraduate*> undergraduates;
std::vector<PartTimeFaculty*> partTimeFaculty;
std::vector<FullTimeFaculty*> fullTimeFaculty;

std::string standing, major, university, degree, awardName;
float gpa, salary, workExperience;
int beganYearOfStudy;

void getGraduate(std::ifstream textFileName) {
    if (textFileName.is_open()) {
        while (textFileName >> standing >> major >> university >> beganYearOfStudy >> gpa >> degree) {
            Graduate* graduate = new Graduate(standing, major, university, beganYearOfStudy, gpa, degree);
            graduate->generatePin();
            graduates.push_back(graduate);
        }
        textFileName.close();
    }
}

void getUndergraduate(std::ifstream textFileName) {
    if (textFileName.is_open()) {
        while (textFileName >> standing >> major >> university >> beganYearOfStudy >> gpa >> degree) {
            Undergraduate* undergraduate = new Undergraduate(standing, major, university, beganYearOfStudy, gpa, degree);
            undergraduate->generatePin();
            undergraduates.push_back(undergraduate);
        }
        textFileName.close();
    }
}

void getPartTimeFaculty(std::ifstream textFileName) {
    if (textFileName.is_open()) {
        while (textFileName >> university >> workExperience >> salary >> awardName) {
            PartTimeFaculty* partTimeEmployee= new PartTimeFaculty(university, workExperience, salary, awardName);
            partTimeEmployee->generatePin();
            partTimeFaculty.push_back(partTimeEmployee);
        }
        textFileName.close();
    }
}

void getFullTimeFaculty(std::ifstream textFileName) {
    if (textFileName.is_open()) {
        while (textFileName >> university >> workExperience >> salary >> awardName) {
            FullTimeFaculty* fullTimeEmployee = new FullTimeFaculty(university, workExperience, salary, awardName);
            fullTimeEmployee->generatePin();
            fullTimeFaculty.push_back(fullTimeEmployee);
        }
        textFileName.close();
    }
}

// recursive binary search using STL vectors
int binarySearch(const std::vector<Graduate*>& vec, int start, int end, std::string key)
{
    // Start index greater than end index
    // return -1 if the value could not be found.
    if (start > end) {
        return -1;
    }

    // Middle element of the vector
    const int middle = start + ((end - start) / 2);

    // return the index from the vector if the value is found
    if (vec[middle]->getPersonPIN() == key) {
        return middle;
    }
    // narrow search upper half result + call recursevly the function
    else if (vec[middle]->getPersonPIN() > key) {
        return binarySearch(vec, start, middle - 1, key);
    }
    // narrow search to lower half  + call recursevly the function
    return binarySearch(vec, middle + 1, end, key);
}

int main() {
    //2012171152 -> working ID for graduates

    getGraduate(std::ifstream ("Graduates.txt"));
    getUndergraduate(std::ifstream("Undergraduates.txt"));
    getPartTimeFaculty(std::ifstream("PartTimeEmployees.txt"));
    getFullTimeFaculty(std::ifstream("FullTimeEmployees.txt"));

    // sorting graduates vector because of binary search requirement
    std::sort(graduates.begin(), graduates.end());

    // call binary search function
    int indexFromGraduateSearch = binarySearch(graduates, 0, graduates.size() - 1, "2012171152"); 

        /*   Check return value index   */
    if (indexFromGraduateSearch != -1) {
        std::cout << "Graduate PIN index is: " << indexFromGraduateSearch << "\n";
    } else {
        std::cout << "PIN does not exist: " << indexFromGraduateSearch << "\n";
    }
        /*   Loop Through All vectors    */
    for (size_t i = 0; i < graduates.size(); i++) {
        std::cout << "Graduate Degree: " << graduates[i]->getGraduateDegree() << "\n";
        std::cout << "Graduate PIN: " << graduates[i]->getPersonPIN() << "\n";
        std::cout << std::endl;
    }

    for (size_t i = 0; i < undergraduates.size(); i++) {
        std::cout << "Undergraduate Degree: " << undergraduates[i]->getUnderGraduateBachelorDegree() << "\n";
        std::cout << "Undergraduate PIN: " << undergraduates[i]->getPersonPIN() << "\n";
        std::cout << std::endl;
    }

    for (size_t i = 0; i < partTimeFaculty.size(); i++) {
        std::cout << "partTimeFaculty Qualification: " << partTimeFaculty[i]->getPartTimeFacultyQualification() << "\n";
        std::cout << "partTimeFaculty PIN: " << partTimeFaculty[i]->getPersonPIN() << "\n";
        std::cout << std::endl;
    }

    for (size_t i = 0; i < fullTimeFaculty.size(); i++) {
        std::cout << "fullTimeFaculty Award: " << fullTimeFaculty[i]->getFullTimeFacultyAward() << "\n";
        std::cout << "fullTimeFaculty PIN: " << fullTimeFaculty[i]->getPersonPIN() << "\n";
        std::cout << std::endl;
    }

    return 0;
}