#include "Person.h"

Person::Person(string name, string surname, string patronymic)
    : name_(name), surname_(surname), patronymic_(patronymic) {}

//bool Person::AddRole(Role role) { return role_.insert(role).second; }

string const& Person::name() const { return name_; }

string const& Person::surname() const { return surname_; }

string const& Person::patronymic() const { return patronymic_; }

set<Role> const& Person::role() const { return role_; }

bool operator==(Person left, Person right) {
    return left.name_ == right.name_ && left.surname_ == right.surname_ &&
        left.patronymic_ == right.patronymic_;
}
