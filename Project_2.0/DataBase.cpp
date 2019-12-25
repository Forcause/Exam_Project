#include "DataBase.h"

void DataBase::AddStudent(Student student) { students_.push_back(student); }

void DataBase::AddLecturer(Lecturer lecturer) {
  lecturers_.push_back(lecturer);
}

void DataBase::RemoveStudent(Student stud) {
  students_.erase(std::find(students_.begin(), students_.end(), stud));
}

void DataBase::RemoveLecturer(Lecturer lect) {
  lecturers_.erase(std::find(lecturers_.begin(), lecturers_.end(), lect));
}

void DataBase::EditStudentGrade(int id, int grade, Subject subject) {
  students_.at(id).EditGrade(grade, subject);
}

void DataBase::DeleteStudentCoursework(int id, Subject subject) {
  students_.at(id).DeleteCoursework(subject);
}



vector<Student> const& DataBase::students() {
  vector<Student> studtmp;
  for (auto it : students_) {
    studtmp.push_back(it);
  }
  return studtmp;
}

vector<Lecturer> const& DataBase::lecturers() {
  vector<Lecturer> lecttmp;
  for (auto it : lecturers_) {
    lecttmp.push_back(it);
  }
  return lecttmp;
}