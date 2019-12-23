#include <iostream>
#include <Windows.h>
#include "DataBase.h"
#include "Human.h"
#include "Lecturer.h"
#include "PublicationInf.h"
#include "Student.h"
#include "Subject.h"

using namespace std;
using std::cin;
using std::make_pair;


int main() {
  string t1, t2, t3;
  DataBase database;

  cin >> t1 >> t2 >> t3;
  Lecturer lect = Lecturer(t1, t2, t3);
  database.AddLecturer(lect);
  string title = "Good Shit";
  string date = "10:01:2019";
  vector<string> authors;
  authors.push_back("Pidor.A.A");
  vector<string> keywords;
  keywords.push_back("Zalupa");
  PublicationInf publication = PublicationInf(title, date, authors, keywords);
  return 0;
}