#pragma once
#include "Person.h"
#include "Publication.h"
#include "Subject.h"

class Lecturer : public Person {
    map<Subject, string> subject_thesis_;
    vector<PublicationInf> publications_;

public:
    using Person::Person;
    void AddSubjectThesis(Subject, string);
    void AddPublication(Lecturer, PublicationInf);
    vector<PublicationInf> const& publication() const;
    string to_s(Lecturer lect);
};