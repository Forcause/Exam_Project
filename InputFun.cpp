#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h> //only ms windows library
#include <conio.h> //only ms windows library

using namespace std;

//Initializing functions.
void Drawer(int lever), MainInput(int lever, bool access), Operate_With_Human(const string& fun, vector<string>& obj), Operate_With_Subject(const string& fun, vector<string>& obj), Viewer(int lever, vector<string>& obj); int* GetWindowSize(); size_t Split(const string& str, vector<string>& v, char ch); bool Access(string str);
//Initializing dummys.
struct Subject {}; struct Human {};  map<int, Subject> Submap; map<int, Human> Humap;

int main() {
	string a_str = "admin";
	Drawer(1);
	printf("\n#Welcome to the University database!");
	Drawer(1);
	bool access = Access(a_str);
	while (1) {
		if (access) printf("\n#By pressing '1' you can operate with Human-objects.\n#By pressing '2' you can operate with Subjects.\n#By pressing 'c' you can change admin password.\n#You can exit bu pressing 'Esc'");
		else printf("\n#By pressing '1' you can operate with Human-objects.\n#By pressing '2' you can operate with Subjects.\n#You can exit bu pressing 'Esc'");
		Drawer(1);
		int ch = -1;
		if (access) {
			while ((ch != 49) && (ch != 50) && (ch != 99) && (ch!=27)) ch = _getch();
			if (ch == 99) {
				printf("\n#Please enter new admin password: ");
				a_str.clear();
				char lt;
				lt = _getch();
				while (lt != 13) {
					a_str.push_back(lt);
					cout << '*';
					lt = _getch();
				}
				Drawer(1);
				continue;
			}
			else if (ch == 49 || ch == 50) MainInput(ch, access);
			else if (ch == 27) break;
		}
		else {
			while ((ch != 49) && (ch != 50) && (ch!=27)) ch = _getch(); //using conio::_getch allow us not to see input on the screen.
			if ((ch == 49) || (ch == 50)) MainInput(ch, access);
			else if (ch == 27) break;
		}
		Drawer(1);
	}	
}

void MainInput(int lever, bool access) { //lever takes 49 or 50 (ASCII 1 or 2), 49 means operating with Human-objects, 50 means operating with Subjects. //access defines the type of access should be granted.
	vector<string> v; string str;
	if (lever == 49) {
		if(access) printf("\n#Allowed commands:\n#  Add <Surname> <Name> <Patronymic>\n#  Remove <Surname> <Name> <Patronymic>\n#  Edit <Surname> <Name> <Patronymic>\n#  View <Surname> <Name> <Patronymic>");
		else printf("\n#Allowed commands:\n#  View <Surname> <Name> <Patronymic>");
		while (1) {
			Drawer(1); cout << "\n#>";
			getline(cin, str);
			for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
			Drawer(0);
			Split(str, v, ' ');
			if (v[0] == "ADD" && access) {
				Operate_With_Human(v[0], v);
				break;
			}
			else if (v[0] == "REMOVE" && access) {
				Operate_With_Human(v[0], v);
				break;
			}
			else if (v[0] == "EDIT" && access) {
				Operate_With_Human(v[0], v);
				break;
			}
			else if (v[0] == "VIEW") {
				Viewer(1, v);
				break;
			}
			else printf("\n#Unknown command, please try again..");
		}
	}
	else if (lever == 50) {
		if(access) printf("\n#Allowed commands:\n#  Add <Name>\n#  Remove <Name>\n#  View <Name>");
		else printf("\n#  View <Name>");
		while (1) {
			Drawer(1); cout << "\n#>";
			getline(cin, str);
			Drawer(0);
			Split(str, v, ' ');
			if (v[0] == "ADD" && access) {
				Operate_With_Subject(v[0], v);
				break;
			}
			else if (v[0] == "REMOVE" && access) {
				Operate_With_Subject(v[0], v);
				break;
			}
			else if (v[0] == "VIEW") {
				Viewer(2, v);
				break;
			}
			else printf("\n#Unknown command, please try again..");
		}
	}
}

void Viewer(int lever, vector<string>& obj) { //lever takes 1 or 2, 1 means operating with Human-objects, 2 means operating with Subjects.
	Drawer(1);
	if (lever == 1) {

	}
	else if (lever == 2) {

	}
	Drawer(1);
}

size_t Split(const string& str, vector<string>& v, char ch) {
	size_t pos = str.find(ch);
	size_t initialPos = 0;
	v.clear();
	while (pos != string::npos) {
		v.push_back(str.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;
		while (str.find(ch,initialPos)==initialPos) {
			initialPos += 1;
		}
		pos = str.find(ch, initialPos);
	}
	v.push_back(str.substr(initialPos, min(pos, str.size()) - initialPos + 1));
	return v.size();
}

void Drawer(int lever) { //lever takes 0 or 1, 0 means write on the same string, 1 means jump to next one.
	int* size = GetWindowSize();
	if (size[0] == -1 || size[1] == -1) {
		printf("#An error occured! Please fix window size, then try again by pressing 'g'.\n");
		int ch = -1;
		while (ch != 103) ch=_getch();
		if (ch == 103) { system("CLS");  Drawer(1); };
	}
	else {
		if (lever == 1) cout << endl;
		for (int i = 1; i <= size[0]; i++) {
			cout << '#';
		}
	}
}

int* GetWindowSize() {
	HANDLE hWndConsole; int width = -1, height = -1;
	if (hWndConsole = GetStdHandle(-12)) {
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo)) {
			width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
			height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
		}
		else
			printf("#Error: %d\n", GetLastError());
	}
	else
		printf("#Error: %d\n", GetLastError());
	int* size = new int[2];
	size[0] = width; size[1] = height;
	return size;
}

bool Access(string str) {
	Drawer(1);
	printf("\n#To continue in usermode press '1'.\n#To continue as administrator press '2'.");
	Drawer(1);
	int ch = -1;
	while ((ch != 49) && (ch != 50)) ch = _getch();
	if (ch == 50) {
		while (1) {
			string pass = "";
			char lt;
			printf("\n#Enter password for administrator mode: ");
			lt = _getch();
			while (lt != 13) {
				pass.push_back(lt);
				cout << '*';
				lt = _getch();
			}
			if (pass == str) { Drawer(1); return 1; }
			else {
				Drawer(1);
				printf("\n#Incorrect password! Try again...");
			}
		}
	}
	return 0;
}

void Operate_With_Human(const string& fun, vector<string>& obj) {}
void Operate_With_Subject(const string& fun, vector<string>& obj) {}
