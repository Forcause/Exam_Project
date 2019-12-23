#include "Student.h"

void Student::AddGrade(Subject subject, int grade) {
  subject_grades_[subject] = grade;
}

void Student::AddCourseWork(Subject subject, string coursework_name) {
  subject_coursework_[subject] = coursework_name;
}

void Student::AddDirector(Human scientific) { scientific_director_.push_back(scientific); }
