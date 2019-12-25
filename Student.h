#pragma once
#include "Person.h"
#include "CourseWork.h"
#include "Subjects.h"

class Student : public Person {
    map<string, int> subject_grades_;
    vector<CourseWork> courseworks_;
   // vector<Person> scientific_director_;
public:
    using Person::Person;
    void addCourseWork(CourseWork);
    vector<CourseWork> const& courseworks() const;
    void editGrade(string, int);
    string to_s(Student stud);
};