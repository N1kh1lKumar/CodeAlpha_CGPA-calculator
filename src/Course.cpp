#include "../include/Course.h"
#include <iostream>


using namespace std;

//  Constructor
Course::Course()
{
    courseName = "";
    grade = "";
    credits = 0;
}

// Input Course Details
void Course::inputCourse()
{
    cin.ignore(1000, '\n');

    cout << "\nEnter Course Name: ";
    getline(cin, courseName);

    cout << "Enter Grade (A+, A, B+, B, C, D, F): ";
    cin >> grade;

    while (grade != "A+" && grade != "A" && grade != "B+" && grade != "B" &&  grade != "C" && grade != "D" && grade != "F")
    {
        cout << "Invalid Grade! Enter again: ";
        cin >> grade;
    }

    cout << "Enter Credits : ";
    cin >> credits;

    while (credits <= 0)
    {
        cout << "Credits must be greater than 0. Enter again: ";
        cin >> credits;
    }
}

// Getter Functions
string Course::getCourseName()
{
    return courseName;
}


// Getter for Grade
string Course::getGrade()
{
    return grade;
}


// Getter for Credits
int Course::getCredits()
{
    return credits;
}

// Convert Grade to Grade Point
double Course::getGradePoint()
{
    if (grade == "A+")
        return 10.0;
    else if (grade == "A")
        return 9.0;
    else if (grade == "B+")
        return 8.0;
    else if (grade == "B")
        return 7.0;
    else if (grade == "C")
        return 6.0;
    else if (grade == "D")
        return 5.0;
    else
        return 0.0; // F
}