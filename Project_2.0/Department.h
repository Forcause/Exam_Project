#pragma once
#include "Person.h"
#include "Student.h"
#include "Lecturer.h"
#include "UniversityMembers.h"

class Department {
    const string title_;
    string description_;
    UniversityMembers<Lecturer> lecturers_;
    UniversityMembers<Student> students_;
public:
    Department(string);
    string const& title() const;
    void addStudent(string const&, string const&, string const&);
    void addLecturer(string const&, string const&, string const&);
    inline auto findMember(string const&, string const&, string const&);
    Student findStudent(string const&, string const&, string const&);
    Lecturer findLecturer(string const&, string const&, string const&);
    void removeStudent(Student);
    void removeLecturer(Lecturer);
};