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

class Person {
    const string name_;
    const string surname_;
    const string patronymic_;
    set<Role> role_;

public:
    Person(string, string, string);

    //bool addRole(Role);  // returns TRUE if new role
    string const& name() const;
    string const& surname() const;
    string const& patronymic() const;
    set<Role> const& role() const;
    friend bool operator==(Person left, Person right);
};