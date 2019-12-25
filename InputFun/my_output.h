#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

class Output {
public:
	void Viewer(int lever, vector<string>& v);
	void Drawer(int lever);
};
