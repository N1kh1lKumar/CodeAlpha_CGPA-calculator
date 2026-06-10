#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    std::string name;
    std::string rollNumber;

public:
    Student();

    void inputStudentInfo();

    std::string getName() const;
    std::string getRollNumber() const;
};

#endif