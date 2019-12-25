#pragma once
#include "Person.h"

class Research {
    const string title_;
    const string date_;
    const vector<string> authors_;
    vector<string> key_words_;
    string description_;
public:
    Research(string, string, vector<string>);
    string const& title() const;
    string const& date() const;
    vector<string> const& authors() const;
    vector<string> key_words();
    string description();
    void setDescription(string);
    void setKeyWords(vector<string> key_words);
};