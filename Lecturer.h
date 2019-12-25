#pragma once
#include "Person.h"
#include "Publication.h"
#include "Subjects.h"
#include <string>
#include <vector>

class Lecturer : public Person {
   // map<Subject, string> subject_thesis_;
    vector<Publication> publications_;
public:
    using Person::Person;
   // void AddSubjectThesis(Subject, string);
    void addPublication(Publication);
    vector<Publication> const& publications() const;
    string to_s(Lecturer lect);
};