#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "my_addons.h"
#include "UniversityMembers.h"
#include "University.h"

using namespace std;

class Output {
public:
	void Viewer(int lever, int plever, vector<string>& v, University& uni);
	static void Drawer(int lever);
	void Edit(Lecturer& lecturer, University& uni);
	void Edit(Student& student, University& uni);
};
