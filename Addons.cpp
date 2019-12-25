#include "my_addons.h"

size_t Addons::Split(const string& str, vector<string>& v, char ch) {
	Output output;
	size_t pos = str.find(ch);
	size_t initialPos = 0;
	v.clear();
	while (pos != string::npos) {
		v.push_back(str.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;
		while (str.find(ch, initialPos) == initialPos) {
			initialPos += 1;
		}
		pos = str.find(ch, initialPos);
	}
	v.push_back(str.substr(initialPos, min(pos, str.size()) - initialPos + 1));
	return v.size();
}

bool Addons::Access() {
	Output output;
	output.Drawer(1);
	cout << "\n#To continue in usermode press '1'.\n#To continue as administrator press '2'.";
	output.Drawer(1);
	int ch = -1;
	while ((ch != 49) && (ch != 50)) ch = _getch();
	if (ch == 50) {
		while (1) {
			string pass = "";
			char lt;
			cout << "\n#Enter password for administrator mode: ";
			lt = _getch();
			while (lt != 13) {
				pass.push_back(lt);
				cout << '*';
				lt = _getch();
			}
			if (pass == "admin") { output.Drawer(1); return 1; }
			else {
				output.Drawer(1);
				cout << "\n#Incorrect password! Try again...";
			}
		}
	}
	return 0;
}

int Addons::GetWindowSize() {
	HANDLE hWndConsole; int width = -1;
	if (hWndConsole = GetStdHandle(-12)) {
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo)) width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
		else
			cout << "\n#Error: " + GetLastError() << endl;
	}
	else
		cout << "\n#Error: " + GetLastError() << endl;
	int size = width;
	return size;
}