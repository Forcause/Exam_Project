#include "my_output.h"

Addons addons; UniversityWorkers uworkers;

void Output::Viewer(int lever, vector<string>& v) { //lever takes 1 or 2, 1 means operating with Human-objects, 2 means operating with Org.
	Drawer(1);
	if (lever == 1) {
		if (uworkers.Find(v)!=NULL) {
			Student student;
			cout << "\n#Student: " << student.surname_ + " " + student.name_ + " " + student.patronymic_;
			if (student.current_roles != NULL) {
				cout << "\n# Roles:";
				for (int i = 0; i < student.current_roles.size(); i++) cout << "\n#   " + student.current_roles[i];
			}
			if (student.subject_grades != NULL) {
				cout << "\n# Grades:";
				for (auto n : student.subject_grades) cout << "\n#   " + n.first + ": " + n.second;
			}
			if (student.subject_coursework != NULL) {
				cout << "\n# Courseworks:";
				for (auto n : student.subject_coursework) cout << "\n#   " + n.first + ": " + n.second;
			}
			if (student.scientific_director != NULL) {
				cout << "\n# Scientific directors:";
				for (int i = 0; i < student.scientific_director.size(); i++) cout << "\n#   " + student.scientific_director[i];
			}
		}
		else if (uworkers.Find(v)!=NULL) {
			Lecturer lecturer
			cout << "\n# Lecturer: " << lecturer.surname_ + " " + lecturer.name_ + " " + lecturer.patronymic_;
			if (lecturer.current_roles != NULL) {
				cout << "\n# Roles:";
				for (int i = 0; i < lecturer.current_roles.size(); i++) cout << "\n#   " + lecturer.current_roles[i];
			}
			if (lecturer.publications != NULL) {
				cout << "\n# Publications:";
				for (int i = 0; i < lecturer.publications.size(); i++) cout << "\n#   " + lecturer.publications[i];
			}
		}
		else cout << "No person with this name was found.";
	}
	/*else if (lever == 2) {
		if (Find(v).id[0] == 'o') {
			cout << "\n# Organisation: " << Submap[id].Name;
			if (Submap[id].departments != NULL) {
				cout << "\n# Departments:";
				for (int i = 0; i < Submap[id].departments.size(); i++) {
					cout << "\n#   " + Submap[id].departments[i] + ". Subjects:";
					for (int j = 0; j < Submap[id].departments[i].subjects.size(); j++) cout << "\n#     " + Submap[id].departments[i].subjects[j];
				}
			}
		}
		else cout << "No organisation with this name was found.";

	}*/
	Drawer(1);
}

void Output::Drawer(int lever) { //lever takes 0 or 1, 0 means write on the same string, 1 means jump to next one.
	int size = addons.GetWindowSize();
	if (size == -1) {
		cout << "#An error occured! Please fix window size, then try again by pressing 'g'.\n";
		int ch = -1;
		while (ch != 103) ch = _getch(); //ASCII g=103
		if (ch == 103) { system("CLS");  Drawer(1); };
	}
	else {
		if (lever == 1) cout << endl;
		for (int i = 1; i <= size; i++) {
			cout << '#';
		}
	}
}
