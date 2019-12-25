#pragma once
#include "Department.h"
#include "Person.h"
#include "Student.h"
#include "Lecturer.h"
#include "UniversityMembers.h"

class University {
    const string title_;
    vector<Department> departments_;
public:
    University(string);
    string const& title() const;
    Department addDepartment(string);
    auto findDepartment(string);
    auto findDepartment(Department const&);
    auto findDepartment(Department);
    void removeDeapartment();
    Student findStudent(string const&, string const&, string const&);
    Lecturer findLecturer(string const&, string const&, string const&);
    Student findStudent(Student const&);
    Lecturer findLecturer(Lecturer const&);
    void removeStudent(Student);
    void removeLecturer(Lecturer);
};