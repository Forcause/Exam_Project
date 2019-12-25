#pragma once
#include "Person.h"

class Research {
    const string title_;
    const string date_;
    vector<Person> authors_;
    vector<string> key_words_;
    string description_;
public:
    Research(string, string, vector<Person>);
    string const& title() const;
    string const& date() const;
    vector<Person> const& authors() const;
    vector<string> key_words();
    string description();
    void setDescription(string);
    void setKeyWords(vector<string> key_words);
};