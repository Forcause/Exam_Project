#include "my_output.h"

void MainInput(int lever, bool access);

Output output; Addons addons; UniversityWorkers uworkers;

int main() {
	output.Drawer(1);
	cout << "\n#Welcome to the University database!";
	output.Drawer(1);
	bool access = addons.Access();
	while (1) {
		cout << "\n#By pressing '1' you can operate with people.\n#By pressing '2' you can operate with organisation.\n#You can exit bu pressing 'Esc'"; //ASCII 1=49, 2=50, esc=27
		output.Drawer(1);
		int ch = -1;
		if (access) {
			while ((ch != 49) && (ch != 50) && (ch!=27)) ch = _getch();
			if (ch == 49 || ch == 50) Input::MainInput(ch, access);
			else if (ch == 27) break;
		}
		else {
			while ((ch != 49) && (ch != 50) && (ch!=27)) ch = _getch(); //using conio::_getch allow us not to see input on the screen.
			if ((ch == 49) || (ch == 50)) Input::MainInput(ch, access);
			else if (ch == 27) break;
		}
		output.Drawer(1);
	}	
}

class Input {
public:
	static void MainInput(int lever, bool access) { //lever takes 49 or 50 (ASCII 1 or 2), 49 means operating with Human-objects, 50 means operating with Org. //access defines the type of access should be granted.
		vector<string> v; string str;
		if (lever == 49) {
			if (access) cout << "\n#Allowed commands:\n#  Add student/lecturer <Surname> <Name> <Patronymic>\n#  Remove student/lecturer <Surname> <Name> <Patronymic>\n#  Edit student/lecturer <Surname> <Name> <Patronymic>\n#  View student/lecturer <Surname> <Name> <Patronymic>\n#  Input 'back' to return.";
			else cout << "\n#Allowed commands:\n#  View student/lecturer <Surname> <Name> <Patronymic>\n# Input 'back' to return.";
			while (1) {
				output.Drawer(1); cout << "\n#>";
				getline(cin, str);
				for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
				output.Drawer(0);
				addons.Split(str, v, ' ');
				if (v.size() != 5 && v[0] != "BACK") cout << "\n#Error: wrong input!";
				else if (v[0] == "BACK") break;
				else {
					if (v[1] == "STUDENT") {
						if (v[0] == "ADD" && access) {
							uworkers.Add(v[2], v[3], v[4]);
							break;
						}
						else if (v[0] == "REMOVE" && access) {
							uworkers.Student a = uworkers.Student.Find(v[2], v[3], v[4]);
							if (a != NULL) uworkers.Remove(a);
							else cout << "\n#Error: no such person was found.";
							break;
						}
						else if (v[0] == "EDIT" && access) {
							uworkers.Student a = uworkers.Student.Find(v[2], v[3], v[4]);
							if (a != NULL) uworkers.Edit(a);
							else cout << "\n#Error: no such person was found.";
							break;
						}
						else if (v[0] == "VIEW") {
							output.Viewer(1, v);
							break;
						}
						else cout << "\n#Error: Unknown command, please try again..";
					}
					else if (v[1] == "LECTURER") {
						if (v[0] == "ADD" && access) {
							uworkers.Add(v[2], v[3], v[4]);
							break;
						}
						else if (v[0] == "REMOVE" && access) {
							uworkers.Lecturer a = uworkers.Lecturer.Find(v[2], v[3], v[4]);
							if (a != NULL) uworkers.RemoveLecturer(a);
							else cout << "\n#Error: no such person was found.";
							break;
						}
						else if (v[0] == "EDIT" && access) {
							uworkers.Lecturer a = urowkers.Lecturer.Find(v[2], v[3], v[4]);
							if (a != NULL) uworkers.Remove(a);
							else cout << "\n#Error: no such person was found.";
							break;
						}
						else if (v[0] == "VIEW") {
							output.Viewer(1, v);
							break;
						}
						else cout << "\n#Error: Unknown command, please try again..";
					}
					else cout << "\n#Error: Unknown command, please try again..";
				}
			}
		}
		/*else if (lever == 50) {
			cout << "\n#Allowed commands:\n#  View <Name>";
			while (1) {
				output.Drawer(1); cout << "\n#>";
				getline(cin, str);
				output.Drawer(0);
				addons.Split(str, v, ' ');
				if (Organisation.Find(v) != NULL) {
					if (v[0] == "VIEW") {
						output.Viewer(2, v);
						break;
					}
					else cout << "\n#Error: Unknown command, please try again..";
				}
				else cout << "\n#Error: no such organisation was found.";
			}
		}*/
	}
};

