#pragma once
#include <unordered_set>
#include <algorithm>
#include "Lecturer.h"
#include "Student.h"

using std::unordered_set;

class DataBase {
  vector<Student> students_;
  vector<Lecturer> lecturers_;

 public:
  void AddStudent(Student student);
  void AddLecturer(Lecturer lecturer);
  void RemoveStudent(Student student);
  void RemoveLecturer(Lecturer lecturer);
  vector<Student> const &students();
  vector<Lecturer> const &lecturers();
 };