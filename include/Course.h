#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
private:
    std::string courseName;
    std::string grade;
    int credits;

public:
    Course();

    void inputCourse();

    std::string getCourseName();
    std::string getGrade();
    int getCredits();

    double getGradePoint();
};

#endif