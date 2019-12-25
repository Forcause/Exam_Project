#include <Windows.h>
#include <iostream>
#include "DataBase.h"
#include "Human.h"
#include "Lecturer.h"
#include "PublicationInf.h"
#include "Student.h"
#include "Subject.h"
#include "UniversityWorkers.h"

using std::cin;
using std::make_pair;

int main() {
  UniversityWorkers<Lecturer> lecturers;
  UniversityWorkers<Student> students;
  string t1, t2, t3;
  DataBase database;

  cin >> t1 >> t2 >> t3;
  Lecturer lect = Lecturer(t1, t2, t3);
  lecturers.Add(lect);
  database.AddLecturer(lect);
  lecturers.Find(lect);
  string title = "Good Shit";
  string date = "10:01:2019";
  vector<string> authors;
  authors.push_back("Pidor.A.A");
  vector<string> keywords;
  keywords.push_back("Zalupa");
  PublicationInf publication = PublicationInf(title, date, authors, keywords);
  return 0;
}