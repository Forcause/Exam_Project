#include "Human.h"

Human::Human(string name, string surname, string patronymic)
    : name_(name), surname_(surname), patronymic_(patronymic) {}

bool Human::AddRole(Role role) { return role_.insert(role).second; }

string const& Human::name() const { return name_; }

string const& Human::surname() const { return surname_; }

string const& Human::patronymic() const { return patronymic_; }

bool operator==(Human left, Human right) {
  return left.name_ == right.name_ && left.surname_ == right.surname_ &&
         left.patronymic_ == right.patronymic_;
}
