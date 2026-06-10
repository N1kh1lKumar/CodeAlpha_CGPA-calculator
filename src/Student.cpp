#include "../include/Student.h"
#include <iostream>

using namespace std;

// Constructor
Student::Student()
{
    name = "";
    rollNumber = "";
}

// Input Student Details
void Student::inputStudentInfo()
{
    cout << "\n------------- Student Information -------------\n";

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Roll Number: ";
    getline(cin, rollNumber);

}

// Getter for NameS
string Student::getName() const
{
    return name;
}

// Getter for Roll Number
string Student::getRollNumber() const
{
    return rollNumber;
}