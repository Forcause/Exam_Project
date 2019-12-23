#include "my_output.h"
#include "Student.h"
#include "Lecturer.h"

void Output::Viewer(int lever, vector<string>& v) { //lever takes 1 or 2, 1 means operating with Human-objects, 2 means operating with Subjects.
	Drawer(1);
	if (lever == 1) {
		/*if (Find(v).id[0] == 's') {
			cout << "\n#Student: " << students_[id].Surname + " " + students_[id].Name + " " + students_[id].Patronymic;
			if (students_[id].current_roles != NULL) {
				cout << "\n# Roles:";
				for (int i = 0; i < students_[id].current_roles.size(); i++) cout << "\n#   " + students_[id].current_roles[i];
			}
			if (students_[id].subject_grades != NULL) {
				cout << "\n# Grades:";
				for (auto n : students_[id].subject_grades) cout << "\n#   " + n;
			}
			if (students_[id].subject_coursework != NULL) {
				cout << "\n# Courseworks:";
				for (auto n : students_[id].subject_coursework) cout << "\n#   " + n;
			}
			if (students_[id].scientific_director != NULL) {
				cout << "\n# Scientific directors:";
				for (int i = 0; i < students_[id].scientific_director.size(); i++) cout << "\n#   " + students_[id].scientific_director[i];
			}
		}
		else if (Find(v).id[0] == 't') {
			cout << "\n# Lecturer: " << lecturer_[id].Surname + " " + lecturer_[id].Name + " " + lecturer_[id].Patronymic;
			if (lecturer_[id].current_roles != NULL) {
				cout << "\n# Roles:";
				for (int i = 0; i < lecturer_[id].current_roles.size(); i++) cout << "\n#   " + lecturer_[id].current_roles[i];
			}
			if (lecturer_[id].subject_thesis != NULL) {
				cout << "\n# Courseworks:";
				for (auto n : lecturer_[id].subject_thesis) cout << "\n#   " + n;
			}
			if (lecturer_[id].publications != NULL) {
				cout << "\n# Roles:";
				for (int i = 0; i < lecturer_[id].publications.size(); i++) cout << "\n#   " + lecturer_[id].publications[i];
			}
		}
		else printf("No person with this name was found.");
	}
	else if (lever == 2) {
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
		else printf("No organisation with this name was found.");*/
	}
	Drawer(1);
}

int* Output::GetWindowSize() {
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

void Output::Drawer(int lever) { //lever takes 0 or 1, 0 means write on the same string, 1 means jump to next one.
	int* size = GetWindowSize();
	if (size[0] == -1 || size[1] == -1) {
		printf("#An error occured! Please fix window size, then try again by pressing 'g'.\n");
		int ch = -1;
		while (ch != 103) ch = _getch();
		if (ch == 103) { system("CLS");  Drawer(1); };
	}
	else {
		if (lever == 1) cout << endl;
		for (int i = 1; i <= size[0]; i++) {
			cout << '#';
		}
	}
}