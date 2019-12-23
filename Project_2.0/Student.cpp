#include "Student.h"

void Student::AddGrade(Subject subject, int grade) {
  subject_grades_[subject] = grade;
}

void Student::AddCourseWork(Subject subject, string coursework_name) {
  subject_coursework_[subject] = coursework_name;
}

void Student::AddDirector(Human scientific) {
  scientific_director_.push_back(scientific);
}

void Student::EditGrade(int grade, Subject subject) {
  subject_grades_[subject] = grade;
}

void Student::DeleteCoursework(Subject subject) {
  subject_coursework_.erase(subject);
}

/*void Student::EditDirector(Human director) {
  for (Human it : scientific_director_) {
    if (it == director) scientific_director_.erase(scientific_director_.begin() + it);
  }
}
*/