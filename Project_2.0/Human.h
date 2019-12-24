#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>

using std::map;
using std::set;
using std::string;
using std::vector;

//�������� ����
using Role = string;

class Human {
  string name_;
  string surname_;
  string patronymic_;
  set<Role> role_;

 public:
  Human(string name, string surname, string patronymic);
  /*
        ���������� true ���� ���������� ����� ����
  */
  bool AddRole(Role role);
  string const &name() const;
  string const &surname() const;
  string const &patronymic() const;
  friend bool operator==(Human left, Human right);
};