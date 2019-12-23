#pragma once
#include "Human.h"
#include "PublicationInf.h"
#include "Subject.h"

class Lecturer : public Human {
  map<Subject, string> subject_thesis_;
  vector<PublicationInf> publications_;

 public:
	 using Human::Human;
  void AddSubjectThesis(Subject, string);
  void AddPublication(PublicationInf);
};
