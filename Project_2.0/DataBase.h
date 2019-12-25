#pragma once
#include <algorithm>
#include <string>
#include <unordered_set>
#include "Lecturer.h"
#include "Student.h"

using std::unordered_set;

class DataBase {
  vector<Student> students_;
  vector<Lecturer> lecturers_;

 public:
  void AddStudent(Student student);
  void AddLecturer(Lecturer lecturer);
  void RemoveStudent(Student stud);
  void RemoveLecturer(Lecturer lect);
  void EditStudentGrade(int id, int grade, Subject subject);
  void DeleteStudentCoursework(int id, Subject subject);
  Student& SearchStudent(vector<string> people);
  vector<Student> const &students();
  vector<Lecturer> const &lecturers();
};