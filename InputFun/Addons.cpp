#include "my_addons.h"
#include "my_output.h"

Output output;

size_t Addons::Split(const string& str, vector<string>& v, char ch) {
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

bool Addons::Access(string str) {
	output.Drawer(1);
	printf("\n#To continue in usermode press '1'.\n#To continue as administrator press '2'.");
	output.Drawer(1);
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
			if (pass == str) { output.Drawer(1); return 1; }
			else {
				output.Drawer(1);
				printf("\n#Incorrect password! Try again...");
			}
		}
	}
	return 0;
}