#include "my_output.h"
#include "my_addons.h"
#include "DataBase.h"

void MainInput(int lever, bool access);

Output output; Addons addons;

int main() {
	string a_str = "admin";
	output.Drawer(1);
	printf("\n#Welcome to the University database!");
	output.Drawer(1);
	bool access = addons.Access(a_str);
	while (1) {
		if (access) printf("\n#By pressing '1' you can operate with Human-objects.\n#By pressing '2' you can operate with Subjects.\n#By pressing 'c' you can change admin password.\n#You can exit bu pressing 'Esc'");
		else printf("\n#By pressing '1' you can operate with Human-objects.\n#By pressing '2' you can operate with Subjects.\n#You can exit bu pressing 'Esc'");
		output.Drawer(1);
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
				output.Drawer(1);
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
		output.Drawer(1);
	}	
}

void MainInput(int lever, bool access) { //lever takes 49 or 50 (ASCII 1 or 2), 49 means operating with Human-objects, 50 means operating with Subjects. //access defines the type of access should be granted.
	vector<string> v; string str;
	if (lever == 49) {
		if(access) printf("\n#Allowed commands:\n#  Add <Surname> <Name> <Patronymic>\n#  Remove <Surname> <Name> <Patronymic>\n#  Edit <Surname> <Name> <Patronymic>\n#  View <Surname> <Name> <Patronymic>");
		else printf("\n#Allowed commands:\n#  View <Surname> <Name> <Patronymic>");
		while (1) {
			output.Drawer(1); cout << "\n#>";
			getline(cin, str);
			for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
			output.Drawer(0);
			addons.Split(str, v, ' ');
			if (Find(v).id[0] == 's') {
				if (v[0] == "ADD" && access) {
					DataBase::AddStudent(Find(v));
					break;
				}
				else if (v[0] == "REMOVE" && access) {
					DataBase::RemoveStudent(Find(v));
					break;
				}
				else if (v[0] == "EDIT" && access) {
					DataBase::EditStudent(Find(v));
					break;
				}
				else if (v[0] == "VIEW") {
					//Viewer(1, v);
					break;
				}
				else printf("\n#Unknown command, please try again..");
			}
			else if (Find(v).id[0] == 't') {
				if (v[0] == "ADD" && access) {
					DataBase::AddLecturer(Find(v));
					break;
				}
				else if (v[0] == "REMOVE" && access) {
					DataBase::RemoveLecturer(Find(v));
					break;
				}
				else if (v[0] == "EDIT" && access) {
					DataBase::EditLecturer(Find(v));
					break;
				}
				else if (v[0] == "VIEW") {
					//Viewer(1, v);
					break;
				}
				else printf("\n#Unknown command, please try again..");
			}
			else printf("\n#Error: no such person was found.");
		}
	}
	else if (lever == 50) {
		if(access) printf("\n#Allowed commands:\n#  Add <Name>\n#  Remove <Name>\n#  View <Name>");
		else printf("\n#  View <Name>");
		while (1) {
			output.Drawer(1); cout << "\n#>";
			getline(cin, str);
			output.Drawer(0);
			addons.Split(str, v, ' ');
			if (Find(v).id[0] == 'o') {
				if (v[0] == "ADD" && access) {
					//Operate_With_Subject(v[0], v);
					break;
				}
				else if (v[0] == "REMOVE" && access) {
					//Operate_With_Subject(v[0], v);
					break;
				}
				else if (v[0] == "VIEW") {
					//Viewer(2, v);
					break;
				}
				else printf("\n#Unknown command, please try again..");
			}
			else printf("\n#Error: no such organisation was found.");
		}
	}
}
