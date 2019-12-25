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
	vector<Department> const& departments() const;
    Department addDepartment(string);
    typename vector<Department>::iterator findDepartment(string);
    typename vector<Department>::iterator findDepartment(Department const&);
    void removeDeapartment();
    Student* findStudent(string const&, string const&, string const&);
    Lecturer* findLecturer(string const&, string const&, string const&);
    Student* findStudent(Student const&);
    Lecturer* findLecturer(Lecturer const&);
    void removeStudent(Student&);
    void removeLecturer(Lecturer&);
};