#include "Research.h"
#include <string>

Research::Research(string title, string date, vector<Person> authors)
    : title_(title), date_(date), authors_(authors) {}

string const& Research::title() const { return title_; }

string const& Research::date() const { return date_; }

vector<Person> const& Research::authors() const { return authors_; }

void Research::setDescription(string description) { description_ = description; }

string Research::description() { return description_; }

void Research::setKeyWords(vector<string> key_words) { key_words_ = key_words; }

vector<string> Research::key_words() { return key_words_; }
