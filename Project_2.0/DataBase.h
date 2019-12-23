#pragma once
#include <algorithm>
#include <string>
#include <unordered_set>
#include "Lecturer.h"
#include "Student.h"

using std::unordered_set;

class DataBase {
  map<int, Student> students_;
  map<int, Lecturer> lecturers_;

 public:
  void AddStudent(Student student);
  void AddLecturer(Lecturer lecturer);
  void RemoveStudent(int id);
  void RemoveLecturer(int id);
  void EditStudentGrade(int id, int grade, Subject subject);
  void DeleteStudentCoursework(int id, Subject subject);
  vector<Student> const &students();
  vector<Lecturer> const &lecturers();
};