#pragma once
#include "Human.h"

class PublicationInf {
  const string title_;
  const string date_;
  const vector<string> authors_;
  const vector<string> key_words_;

 public:
  PublicationInf(string title, string date, vector<string> authors,
                 vector<string> key_words);
};