#pragma once
#include "Human.h"
#include "Subject.h"

class Student : public Human {
  map<Subject, int> subject_grades_;
  map<Subject, string> subject_coursework_;
  vector<Human> scientific_director_;

 public:
  using Human::Human;
  void AddGrade(Subject subject, int grade);
  void AddCourseWork(Subject subject, string coursework_name);
  void AddDirector(Human s);
  void EditGrade(int grade, Subject subject);
  void DeleteCoursework(Subject subject);
  void EditDirector(Human director);
};