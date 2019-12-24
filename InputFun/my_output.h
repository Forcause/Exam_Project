#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

class Output {
public:
	static void Viewer(int lever, vector<string>& v);
	static void Drawer(int lever);
	static int GetWindowSize();
};
