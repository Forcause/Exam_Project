#include "my_output.h"
#include "my_addons.h"
#include "UniversityWorkers.h"

void MainInput(int lever, bool access);

Output output; Addons addons;

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
			if (access) cout << "\n#Allowed commands:\n#  Add <Surname> <Name> <Patronymic>\n#  Remove <Surname> <Name> <Patronymic>\n#  Edit <Surname> <Name> <Patronymic>\n#  View <Surname> <Name> <Patronymic>\n#  Input 'back' to return.";
			else cout << "\n#Allowed commands:\n#  View <Surname> <Name> <Patronymic>\n#  Input 'back' to return.";
			while (1) {
				output.Drawer(1); cout << "\n#>";
				getline(cin, str);
				for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
				output.Drawer(0);
				addons.Split(str, v, ' ');
				if (v.size() != 4 && v[0] != "BACK") cout << "\n#Error: wrong input!";
				else if (v[0] == "BACK") break;
				else {
					if () {
						if (v[0] == "ADD" && access) {
							UniversityWorkers::AddStudent(v[1], v[2], v[3]);
							break;
						}
						else if (v[0] == "REMOVE" && access) {
							Student a = UniversityWorkers::Student.Find(v[1], v[2], v[3]);
							if (a != NULL) UniversityWorkers::RemoveStudent(a);
							else cout << "\n#Error: no such person was found.";
							break;
						}
						else if (v[0] == "EDIT" && access) {
							Student a = UniversityWorkers::Student.Find(v[1], v[2], v[3]);
							if (a != NULL) UniversityWorkers::EditStudent(a);
							else cout << "\n#Error: no such person was found.";
							break;
						}
						else if (v[0] == "VIEW") {
							output.Viewer(1, v);
							break;
						}
						else cout << "\n#Unknown command, please try again..";
					}
					else if () {
						if (v[0] == "ADD" && access) {
							UniversityWorkers::AddLecturer(v[1], v[2], v[3]);
							break;
						}
						else if (v[0] == "REMOVE" && access) {
							Lecturer a = UniversityWorkers::Lecturer.Find(v[1], v[2], v[3]);
							if (a != NULL) UniversityWorkers::RemoveLecturer(a);
							else cout << "\n#Error: no such person was found.";
							break;
						}
						else if (v[0] == "EDIT" && access) {
							Lecturer a = UniversityWorkers::Lecturer.Find(v[1], v[2], v[3]);
							if (a != NULL) UniversityWorkers::RemoveStudent(a);
							else cout << "\n#Error: no such person was found.";
							break;
						}
						else if (v[0] == "VIEW") {
							output.Viewer(1, v);
							break;
						}
						else cout << "\n#Unknown command, please try again..";
					}
				}
			}
		}
		else if (lever == 50) {
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
					else cout << "\n#Unknown command, please try again..";
				}
				else cout << "\n#Error: no such organisation was found.";
			}
		}
	}
};

