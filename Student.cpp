#include "Student.h"
#include "Subjects.h"

void Student::editGrade(string subject, int grade) {
    subject_grades_[subject] = grade;
}

void Student::addCourseWork(CourseWork publication) {
    courseworks_.push_back(publication);
}

vector<CourseWork> const& Student::courseworks() const {
    return courseworks_;
}

string Student::to_s(Student stud) {
    string info = stud.surname() + " " + stud.name() + " " + stud.patronymic() + "\n";
    for (auto it : subject_grades_) {
        info += it.first + ": " + std::to_string(it.second) + '\n';
    }

    //for (auto it : subject_coursework_) {
    //    if (it.second != "") {
    //        info += it.first + "- " + it.second;
    //    }
    //}

    return info;
}