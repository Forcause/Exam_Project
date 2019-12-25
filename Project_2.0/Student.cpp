#include "Student.h"

void Student::AddGrade(Subject subject, int grade) {
    subject_grades_[subject] = grade;
}

void Student::AddCourseWork(Subject subject, string coursework_name) {
    subject_coursework_[subject] = coursework_name;
}

void Student::AddDirector(Person scientific) {
    scientific_director_.push_back(scientific);
}

void Student::EditGrade(int grade, Subject subject) {
    subject_grades_[subject] = grade;
}

void Student::DeleteCoursework(Subject subject) {
    subject_coursework_.erase(subject);
}

string Student::to_s(Student stud) {
    string info = stud.surname() + " " + stud.name() + " " + stud.patronymic() + "\n";
    for (auto it : subject_grades_) {
        info += it.first + ": " + std::to_string(it.second) + '\n';
    }

    for (auto it : subject_coursework_) {
        if (it.second != "") {
            info += it.first + "- " + it.second;
        }
    }

    return info;
}