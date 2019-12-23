#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>

    using std::map;
using std::set;
using std::string;
using std::vector;

//Дописать роли
using Role = string;

class Human {
  string name_;
  string surname_;
  string patronymic_;
  size_t uid_;
  set<Role> role_;

  friend bool operator==(Human h1, Human h2);

 public:
  Human(string name, string surname, string patronymic);
  /*
        Возвращает true если добавилась новая роль
  */
  bool AddRole(Role role);
  size_t uid() const;
};

namespace std {
template <>
struct hash<Human> {
  size_t operator()(Human const &human) const { return human.uid(); }
};
}  // namespace std
