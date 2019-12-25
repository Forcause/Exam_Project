#pragma once
#include "Person.h"
#include "Subject.h"

class Student : public Person {
    map<Subject, int> subject_grades_;
    map<Subject, string> subject_coursework_;
    vector<Person> scientific_director_;
public:
    using Person::Person;
    void AddGrade(Subject subject, int grade);
    void AddCourseWork(Subject subject, string coursework_name);
    void AddDirector(Person s);
    void EditGrade(int grade, Subject subject);
    void DeleteCoursework(Subject subject);
    void EditDirector(Person director);
    string to_s(Student stud);
};