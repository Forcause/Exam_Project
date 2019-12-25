#include "my_output.h"

Addons addons; UniversityMembers umembers;

void Output::Viewer(int lever, vector<string>& v) { //lever takes 1 or 2, 1 means operating with Human-objects, 2 means operating with Org.
	Drawer(1);
	if (lever == 1) {
		if (umembers.Find(v)!=NULL) {
			Student student = umembers.Find(v);
			cout << "\n#Student: " << student.surname_ + " " + student.name_ + " " + student.patronymic_;
			if (student.roles_ != NULL) {
				cout << "\n# Roles:";
				for (int i = 0; i < student.roles_.size(); i++) cout << "\n#   " + student.roles_[i];
			}
			if (student.subject_grades_ != NULL) {
				cout << "\n# Grades:";
				for (auto n : student.subject_grades_) cout << "\n#   " + n.first + ": " + n.second;
			}
			if (student.subject_coursework_ != NULL) {
				cout << "\n# Courseworks:";
				for (auto n : student.subject_coursework_) cout << "\n#   " + n.first + ": " + n.second;
			}
			if (student.scientific_director != NULL) {
				cout << "\n# Scientific directors:";
				for (int i = 0; i < student.scientific_director_.size(); i++) cout << "\n#   " + student.scientific_director_[i];
			}
			delete student;
		}
		else if (umembers.Find(v)!=NULL) {
			Lecturer lecturer = umembers.Find(v);
			cout << "\n# Lecturer: " << lecturer.Surname + " " + lecturer.Name + " " + lecturer.Patronymic;
			if (lecturer.roles_ != NULL) {
				cout << "\n# Roles:";
				for (int i = 0; i < lecturer.roles_.size(); i++) cout << "\n#   " + lecturer.roles_[i];
			}
			if (lecturer.publications_ != NULL) {
				cout << "\n# Roles:";
				for (int i = 0; i < lecturer.publications_.size(); i++) cout << "\n#   " + lecturer.publications_[i];
			}
			delete lecturer;
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

void Output::Edit(Student* student) {
	Drawer(1);
	cout << "\n#Editing student - " << student.surname_ + " " + student.name_ + " " + student.patronymic_;
	cout << "\n# You can perfrom such operations as: ";
	cout << "\n#   'Add coursework'\n#   'Delete coursework'\n#   'Add grade'\n#   'Edit grade'\n#   'Add director'\n#   'Edit director'";
	while (1) {
		Drawer(1); cout << "\n#> ";
		getline(cin, string str);
		for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
		addons.Split(str, vector<string> v, ' ');
		if (v[0] == "ADD") {
			if (v[1] == "COURSEWORK") {
				Drawer(1);
				cout << "\n#Input format: <subject> <coursework name>";
				Drawer(1); cout << "\n#> ";
				getline(cin, string s);
				addons.Split(s, vector<string> ve, ' ');
				student->AddCourseWork(ve[0], ve[1]);
				break;
			}
			else if (v[1] == "GRADE") {
				Drawer(1);
				cout << "\n#Input format: <subject> <grade>";
				Drawer(1); cout << "\n#> ";
				getline(cin, string s);
				addons.Split(s, vector<string> ve, ' ');
				student->AddGrade(ve[0], int(ve[1]) - 48);
				break;
			}
			else if (v[1] == "DIRECTOR") {
				Drawer(1);
				cout << "\n#Input format: <name>";
				Drawer(1); cout << "\n#> ";
				getline(cin, string s);
				addons.Split(s, vector<string> ve, ' ');
				student->AddDirector(); //!!!!!!!!!!!!!!!!!!!!!
				break;
			}
			else cout << "\n#Error: Unknown command. Please try again...";
		}
		else if (v[0] == "EDIT") {
			if (v[1] == "GRADE") {
				Drawer(1);
				cout << "\n#Input format: <subject> <new grade>";
				Drawer(1); cout << "\n#> ";
				getline(cin, string s);
				addons.Split(s, vector<string> ve, ' ');
				student->AddCourseWork(ve[1], ve[0]);
				break;
			}
			else if (v[1] == "DIRECTOR") {
				Drawer(1);
				cout << "\n#Input format: <new name>";
				Drawer(1); cout << "\n#> ";
				getline(cin, string s);
				addons.Split(s, vector<string> ve, ' ');
				student->AddCourseWork(); //!!!!!!!!!!!!!!!!
				break;
			}
			else cout << "\n#Error: Unknown command. Please try again...";
		}
		else if (v[0] == "DELETE") {
			if (v[1] == "COURSEWORK") {
				Drawer(1);
				cout << "\n#Input format: <subject>";
				Drawer(1); cout << "\n#> ";
				getline(cin, string s);
				addons.Split(s, vector<string> ve, ' ');
				student->AddCourseWork(ve[0]);
				break;
			}
			else cout << "\n#Error: Unknown command. Please try again...";
		}
		else cout << "\n#Error: Unknown command. Please try again...";
	}
}
void Output::Edit(Lecturer* lecturer) {
	Drawer(1);
	cout << "\n#Editing lecturer - " << lecturer.surname_ + " " + lecturer.name_ + " " + lecturer.patronymic_;
	cout << "\n# You can perfrom such operations as: ";
	cout << "\n#   'Add publication'";
	while (1) {
		Drawer(1); cout << "\n#> ";
		getline(cin, string str);
		for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
		addons.Split(str, vector<string> v, ' ');
		if (v[0] == "ADD" && v[1] == "PUBLICATION") {
			Drawer(1);
			cout << "\n#Title: >";
			getline(cin, string title);
			cout << "\n#Date (mm/dd/yy): ";
			getline(cin, string date);
			cout << "\n#Authors (author, author,..): ";
			getline(cin, string auth);
			addons.Split(auth, vector<string> a_ve, ',');
			getline(cin, string s);
			addons.Split(s, vector<string> ve, ' ');
			lecturer->AddPublication(Research(title, date, a_ve)); //!!!!!!!!!!!!!!!!!!!!!
			break;
		}
		else cout << "\n#Error: Unknown command. Please try again...";
	}
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
