#pragma once
#include "Department.h"

Department::Department(string title)
    : title_(title) {}

string const& Department::title() const { return title_; }
vector<string> const& Department::schedule() const { return schedule_; }

void Department::addStudent(string const& name, string const& surname, string const& patronymic) {
    Student new_student = Student(name, surname, patronymic, *this);
    students_.add(new_student);
};
void Department::addLecturer(string const& name, string const& surname, string const& patronymic) {
    Lecturer new_lecturer = Lecturer(name, surname, patronymic, *this);
    lecturers_.add(new_lecturer);
};
typename std::vector<Student>::iterator Department::findStudent(
    string const& name, string const& surname, string const& patronymic) {
    return students_.find(name, surname, patronymic);
};
typename std::vector<Lecturer>::iterator Department::findLecturer(
    string const& name, string const& surname, string const& patronymic) {
    return lecturers_.find(name, surname, patronymic);
};
void Department::removeStudent(Student student) {
    students_.remove(student);
};
void Department::removeLecturer(Lecturer lecturer) {
    lecturers_.remove(lecturer);
};
