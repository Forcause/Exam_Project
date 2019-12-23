#pragma once
#include <vector>
#include <string>
#include <conio.h>
#include <iostream>

using namespace std;

class Addons {
public: 
	static size_t Split(const string& str, vector<string>& v, char ch);
	static bool Access(string str);
};