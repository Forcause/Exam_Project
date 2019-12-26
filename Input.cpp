#include "my_input.h"

void Input::MainInput(int lever, bool access, University& uni) { //lever takes 49 or 50 (ASCII 1 or 2), 49 means operating with Human-objects, 50 means operating with Org. //access defines the type of access should be granted.
	Output output; Addons addons;
	vector<string> v; string str;
	if (lever == 49) {
		if (access) cout << "\n#Allowed commands:\n#  Add student/lecturer <department> <Surname> <Name> <Patronymic>\n#  Remove student/lecturer <Surname> <Name> <Patronymic>\n#  Edit student/lecturer <Surname> <Name> <Patronymic>\n#  View student/lecturer <Surname> <Name> <Patronymic>\n#  Input 'back' to return.";
		else cout << "\n#Allowed commands:\n#  View student/lecturer <Surname> <Name> <Patronymic>\n# Input 'back' to return.";
		while (1) {
			output.Drawer(1); cout << "\n#>";
			getline(cin, str);
			for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
			output.Drawer(0);
			addons.Split(str, v, ' ');
			//if ((v.size() != 5 && v[0] != "BACK") || (v.size()!=6 && v[0]=="ADD")) cout << "\n#Error: wrong input!";
			if (v[0] == "BACK") break;
			else {
				if (v[1] == "STUDENT") {
					if (v[0] == "ADD" && access && v.size()==6) {
						uni.findDepartment(v[2])->addStudent(v[4], v[3], v[5]);
						break;
					}
					else if (v[0] == "REMOVE" && access) {
						if (1) 
						uni.removeStudent(*uni.findStudent(v[3], v[2], v[4]));
						else 
						cout << "\n#Error: no such person was found.";
						break;
					}
					else if (v[0] == "EDIT" && access) {
						if (1) 
						output.Edit(*uni.findStudent(v[3], v[2], v[4]), uni);
						else 
						cout << "\n#Error: no such person was found.";
						break;
					}
					else if (v[0] == "VIEW") {
						output.Viewer(1, 1, v, uni);
						break;
					}
					else cout << "\n#Error: Unknown command, please try again..";
				}
				else if (v[1] == "LECTURER") {
					if (v[0] == "ADD" && access && v.size()==6) {
						uni.findDepartment(v[2])->addLecturer(v[4], v[3], v[5]);
						break;
					}
					else if (v[0] == "REMOVE" && access) {
						if (1) 
						uni.removeLecturer(*uni.findLecturer(v[3], v[2], v[4]));
						else 
						cout << "\n#Error: no such person was found.";
						break;
					}
					else if (v[0] == "EDIT" && access) {
						if (1) 
						output.Edit(*uni.findLecturer(v[3], v[2], v[4]), uni);
						else 
						cout << "\n#Error: no such person was found.";
						break;
					}
					else if (v[0] == "VIEW") {
						output.Viewer(1, 2, v, uni);
						break;
					}
					else cout << "\n#Error: Unknown command, please try again..";
				}
				else cout << "\n#Error: Unknown command, please try again..";
			}
		}
	}
	else if (lever == 50) {
		cout << "\n#Allowed commands:\n#  View";
		while (1) {
			output.Drawer(1); cout << "\n#>";
			getline(cin, str);
			for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
			output.Drawer(0);
			addons.Split(str, v, ' ');
			if (v[0] == "VIEW") {
				output.Viewer(2, 0, v, uni);
				break;
			}
		}
	}
}

