#pragma once
#include "University.h"
#include <algorithm>

University::University(string title)
    : title_(title) {}

string const& University::title() const { return title_; }
vector<Department> const& University::departments() const { return departments_; }

Lecturer* University::findLecturer(
    Lecturer const& lecturer) {
    for (auto& department_it : departments_) {
        vector<Lecturer>::iterator lecturer_it = department_it.lecturers_.find(lecturer);
        if (lecturer_it != department_it.lecturers_.end()) {
            return &(*lecturer_it);
        }
    }
    return nullptr;
};

Department University::addDepartment(string title) {
    Department department = Department(title);

    departments_.push_back(department);
    return department;
}

Lecturer* University::findLecturer(
    string const& name, string const& surname, string const& patronymic) {
    return findLecturer(Lecturer(name, surname, patronymic));
};

Student* University::findStudent(
    Student const& student) {
    for (auto& department_it : departments_) {
        auto student_it = department_it.students_.find(student);
        if (student_it != department_it.students_.end()) {
            return &(*student_it);
        }
    }
    return nullptr;
};

Student* University::findStudent(
    string const& name, string const& surname, string const& patronymic) {
    return findStudent(Student(name, surname, patronymic));
};

void University::removeStudent(Student& student) {
    auto student_it = findStudent(student);
    if (student_it) {
        student_it->department().students_.remove(*student_it);
    }
};

void University::removeLecturer(Lecturer& lecturer) {
    auto lecturer_it = findLecturer(lecturer);
    if (lecturer_it) {
        lecturer_it->department().lecturers_.remove(*lecturer_it);
    }
};

typename vector<Department>::iterator University::findDepartment(string title) {
    return std::find(departments_.begin(), departments_.end(), Department(title));
}

typename vector<Department>::iterator University::findDepartment(Department const& department) {
    return std::find(departments_.begin(), departments_.end(), department);
}