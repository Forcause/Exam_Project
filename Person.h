#pragma once
#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>
#include <list>

using std::map;
using std::set;
using std::string;
using std::vector;
using std::list;

using Role = string;

class Department;

class Person {
    string name_;
    string surname_;
    string patronymic_;
    Department* department_;
    set<Role> role_;

public:
    Person(string, string, string, Department&);
    Person(string, string, string);

    //bool addRole(Role);  // returns TRUE if new role
    string const& name() const;
    string const& surname() const;
    string const& patronymic() const;
    Department& department();
    set<Role> const& role() const;
    friend bool operator==(Person left, Person right);
};