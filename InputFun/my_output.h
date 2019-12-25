#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "my_addons.h"
#include "UniversityWorkers.h"

using namespace std;

class Output {
public:
	void Viewer(int lever, vector<string>& v);
	void Drawer(int lever);
};
