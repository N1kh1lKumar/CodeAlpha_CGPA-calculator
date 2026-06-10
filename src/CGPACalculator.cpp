#include "../include/CGPACalculator.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

void CGPACalculator::inputCourses()
{
    int n;

    cout << "\n Enter Number of Courses: ";

    while (!(cin >> n) || n <= 0)
    {
        cout << "Enter a valid number of courses: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    courses.clear(); // prevents duplicate entries 
    for(int i = 0; i < n; i++)
    {
        cout << "\n----------  Course " << i + 1 << " ----------\n";

        Course course;
        course.inputCourse();

        courses.push_back(course);
    }

    cout << "\n CGPA Calculated Successfully! \n";

    cout <<endl;

    displayReport();
}


// Calculate Total Credits
int CGPACalculator::getTotalCredits()
{
    int totalCredits = 0;

    for (Course course : courses)
    {
        totalCredits += course.getCredits();
    }

    return totalCredits;
}



// Calculate CGPA
double CGPACalculator::calculateCGPA()
{
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (Course course : courses)
    {
        totalGradePoints += course.getGradePoint() * course.getCredits();

        totalCredits += course.getCredits();
    }

    if (totalCredits == 0)  return 0.0;

    return (totalGradePoints / totalCredits);
}



// Display Report
void CGPACalculator::displayReport()
{
    if (courses.empty())
    {
        cout << "\n No courses added yet! \n";
        return;
    }

    double totalGradePoints = 0;

        for (Course course : courses)
        {
            totalGradePoints += course.getGradePoint() * course.getCredits();
        }

    
    cout << "                     COURSE REPORT\n";
    cout << "============================================================\n";

    cout << left
         << setw(25) << "Course Name"
         << setw(10) << "Grade"
         << setw(10) << "Credits"
         << setw(15) << "Grade Point"
         << endl;

    cout << "------------------------------------------------------------\n";

    for (Course course : courses)
    {
        cout << left
             << setw(25) << course.getCourseName()
             << setw(10) << course.getGrade()
             << setw(10) << course.getCredits()
             << setw(15) << course.getGradePoint()
             << endl;
    }

    cout << "------------------------------------------------------------\n";

    cout << "Total Credits : " << getTotalCredits() << endl;

    cout << fixed << setprecision(2);

    double sgpa = calculateCGPA();

    cout << "CGPA          : " << fixed << setprecision(2) << sgpa << endl;

    cout << "Percentage    : " << fixed << setprecision(2) << sgpa * 9.5 << "%" << endl;

    cout << "============================================================\n";
}



// Save Report to File
void CGPACalculator::saveReport(const Student& student)
{
    if(student.getRollNumber().empty())
    {
        cout << "\n Please enter student details first! \n";
        return;
    }

    if(courses.empty())
    {
        cout << "\n Please calculate SGPA first!\n";
        return;
    }

    string filename = "reports/" + student.getRollNumber() + ".txt";

    ofstream file(filename);

    if(!file)
    {
        cout << "\n Error creating report file! \n";
        return;
    }

  

    file << "Name        : " << student.getName() << endl;

    file << "Roll Number : " << student.getRollNumber() << endl;

    file << "\n";

    file << left << setw(25) << "Course Name"  << setw(10) << "Grade" << setw(10) << "Credits"  << endl;

    file << "---------------------------------------------\n";

    for(Course course : courses)
    {
        file << left  << setw(25) << course.getCourseName()  << setw(10) << course.getGrade()  << setw(10) << course.getCredits() << endl;
    }

    file << "\n Total Credits : " << getTotalCredits() << endl;

    file << fixed << setprecision(2);

    double sgpa = calculateCGPA();

    file << "CGPA : " << fixed << setprecision(2) << sgpa << endl;

    file << "Percentage : " << fixed << setprecision(2) << sgpa * 9.5 << "%" << endl;

    file.close();

    bool exists = false;

    ifstream checkFile("data/students.txt");

    string line;

   while(getline(checkFile, line))
    {
        size_t pos = line.find(',');

        if(pos != string::npos)
        {
            string roll = line.substr(0, pos);

            if(roll == student.getRollNumber())
            {
                exists = true;
                break;
            }
        }
    }

    checkFile.close();

    if(!exists)
    {
        ofstream indexFile( "data/students.txt", ios::app);

        indexFile << student.getRollNumber() << "," << student.getName() << endl;

        indexFile.close();
    }

    cout << "\nReport saved successfully!\n";
}



// Search Student Report
void CGPACalculator::searchReport()
{
    string rollNo;

    cout << "\nEnter Roll Number: ";
    cin >> rollNo;

    string filename = "reports/" + rollNo + ".txt";

    ifstream file(filename);

    if (!file)
    {
        cout << "\nStudent Report Not Found!\n";
        return;
    }

    string line;

    cout << "STUDENT REPORT\n";
    cout << "=================================\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}


// View All Students
void CGPACalculator::viewAllStudents()
{
    ifstream file("data/students.txt");

    if(!file)
    {
        cout << "\nNo Students Found!\n";
        return;
    }

    cout << "           REGISTERED STUDENTS\n";
    cout << "==================================================\n";

    cout << left << setw(20) << "Roll Number" << setw(25) << "Name" << endl;

    cout << "--------------------------------------------------\n";

    string line;

    while(getline(file, line))
    {
        size_t pos = line.find(',');

        if(pos != string::npos)
        {
            string roll = line.substr(0, pos);

            string name = line.substr(pos + 1);

            cout << left << setw(20) << roll << setw(25) << name << endl;
        }
    }

    file.close();
}