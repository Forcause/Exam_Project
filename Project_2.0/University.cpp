#pragma once
#include "University.h"

University::University(string title)
    : title_(title) {}

string const& University::title() const { return title_; }


void Department::addStudent(string const& name, string const& surname, string const& patronymic) {
    Lecturer new_lecturer = Lecturer(name, surname, patronymic);
    lecturers_.add(new_lecturer);
};
Student Department::findStudent(
    string const& name, string const& surname, string const& patronymic) {
    return students_.find(name, surname, patronymic);
};
Lecturer Department::findLecturer(
    string const& name, string const& surname, string const& patronymic) {
    return lecturers_.find(name, surname, patronymic);
};
void Department::removeStudent(Student student) {
    students_.remove(student);
};
void Department::removeLecturer(Lecturer lecturer) {
    lecturers_.remove(lecturer);
};