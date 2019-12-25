#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "my_addons.h"
#include "UniversityMembers.h"

using namespace std;

class Output {
public:
	void Viewer(int lever, vector<string>& v);
	void Drawer(int lever);
	void Edit(Lecturer* lecturer);
	void Edit(Student* student);
};
