#pragma once
#include "Research.h"

class CourseWork : public Research {
    int course_;
    double grade_;
    int subject;
public:
    using Research::Research;
    int course();
    double grade();
    void setCourse(int);
    void setGrade(double);
};