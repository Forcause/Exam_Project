#pragma once
#include "University.h"
#include <optional>

University::University(string title)
    : title_(title) {}

string const& University::title() const { return title_; }

auto University::findLecturer(
    Lecturer const& lecturer) {
    for (auto& department_it : departments_) {
        auto lecturer_it = department_it.lecturers_.find(lecturer);
        if (lecturer_it != department_it.lecturers_.end()) {
            return std::optional<std::vector<Lecturer>::iterator>{lecturer_it};
        }
    }
    return std::nullopt;
};

auto University::findLecturer(
    string const& name, string const& surname, string const& patronymic) {
    return findLecturer(Person(name, surname, patronymic));
};

auto University::findStudent(
    Student const& student) {
    for (auto& department_it : departments_) {
        auto student_it = department_it.students_.find(student);
        if (student_it != department_it.students_.end()) {
            return std::optional<std::vector<Student>::iterator>{student_it};
        }
    }
    return std::nullopt;
};

auto University::findStudent(
    string const& name, string const& surname, string const& patronymic) {
    return findStudent(Person(name, surname, patronymic));
};

void University::removeStudent(Student student) {
    auto student_it = findStudent();
    if (student_it) {
        student_it->get()->department.students_.erase(student_it);
    }
};

void University::removeLecturer(Lecturer lecturer) {
    auto lecturer_it = findLecturer();
    if (lecturer_it) {
        lecturer_it->get()->department.lecturers_.erase(lecturer_it);
    }
};

auto University::findDepartment(string title) {
    return std::find(departments_.begin(), departments_.end(), Department(title));
}

auto University::findDepartment(Department const& department) {
    return std::find(departments_.begin(), departments_.end(), department);
}

auto University::findDepartment(Department department) {
    return std::find(departments_.begin(), departments_.end(), department);
}