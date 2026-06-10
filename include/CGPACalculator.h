#ifndef CGPACALCULATOR_H
#define CGPACALCULATOR_H

#include <vector>
#include "Course.h"
#include "Student.h"

class CGPACalculator
{
private:
    std::vector<Course> courses;

public:
    void inputCourses();
    
    int getTotalCredits();

    double calculateCGPA();

    void displayReport();

    void searchReport();

    void viewAllStudents();

    void saveReport(const Student& student);
};

#endif