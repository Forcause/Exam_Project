#pragma once
#include "Person.h"
#include "Student.h"
#include "Lecturer.h"
#include "UniversityMembers.h"


class Department {
    const string title_;
    string description_;
	vector<string> schedule_;
public:
    UniversityMembers<Lecturer> lecturers_;
    UniversityMembers<Student> students_;
    Department(string);
    string const& title() const;
	vector<string> const& schedule() const;
    void addStudent(string const&, string const&, string const&);
    void addLecturer(string const&, string const&, string const&);
    inline auto findMember(string const&, string const&, string const&);
    typename std::vector<Student>::iterator findStudent(string const&, string const&, string const&);
    typename std::vector<Lecturer>::iterator findLecturer(string const&, string const&, string const&);
    void removeStudent(Student);
    void removeLecturer(Lecturer);
    friend bool operator ==(Department const& first, Department const& second) {return first.title() == second.title();}
};