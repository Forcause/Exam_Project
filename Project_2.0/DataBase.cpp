#include "DataBase.h"

int global_counter = 0;

void DataBase::AddStudent(Student student) {
  students_.insert(std::make_pair((2000 + global_counter), student));
  global_counter++;
}

void DataBase::AddLecturer(Lecturer lecturer) {
  lecturers_.insert(std::make_pair((1000 + global_counter), lecturer));
  global_counter++;
}

void DataBase::RemoveStudent(int id) { students_.erase(id); }

void DataBase::RemoveLecturer(int id) { lecturers_.erase(id); }

void DataBase::EditStudentGrade(int id, int grade, Subject subject) {
  students_[id].EditGrade(grade, subject);
}

void DataBase::DeleteStudentCoursework(int id, Subject subject) {
  students_[id].DeleteCoursework(subject);
}

vector<Student> const& DataBase::students() {
  vector<Student> studtmp;
  for (auto it : students_) {
    studtmp.push_back(it.second);
  }
  return studtmp;
}

vector<Lecturer> const& DataBase::lecturers() {
  vector<Lecturer> lecttmp;
  for (auto it : lecturers_) {
    lecttmp.push_back(it.second);
  }
  return lecttmp;
}