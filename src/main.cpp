#include <iostream>
#include <limits>

#include "../include/Student.h"
#include "../include/CGPACalculator.h"

using namespace std;

int main()
{
    Student student;
    CGPACalculator calculator;

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "CGPA CALCULATOR + STUDENT RECORD SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Enter Student Details\n";
        cout << "2. Calculate SGPA\n";
        cout << "3. View Current Report\n";
        cout << "4. Save Report\n";
        cout << "5. Search Student Report\n";
        cout << "6. View All Students\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";


        while (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number: ";

            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch(choice)
        {
            case 1:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                student.inputStudentInfo();
                break;

            case 2:
               calculator.inputCourses();
                break;

            case 3:
                calculator.displayReport();
                break;

            case 4:
                calculator.saveReport(student);
                break;

            case 5:
                calculator.searchReport();
                break;

            case 6:
                calculator.viewAllStudents();
                break;

            case 7:
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
            }

    } while(choice != 7);

    return 0;
}