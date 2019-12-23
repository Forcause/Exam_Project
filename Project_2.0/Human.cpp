#include "Human.h"
static size_t hash() {
  static size_t counter = 0;
  return counter++;
}
Human::Human(string name, string surname, string patronymic)
    : name_(name), surname_(surname), patronymic_(patronymic), uid_(hash()) {}

bool Human::AddRole(Role role) {
  return role_.insert(role).second; }

size_t Human::uid() const { return uid_; }

bool operator==(Human h1, Human h2) { return h1.uid_ == h2.uid_; }