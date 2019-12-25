#include "my_output.h"

void Output::Viewer(int lever, int plever, vector<string>& v, University& uni) { //lever takes 1 or 2, 1 means operating with Human-objects, 2 means operating with Org.
	Addons addons;
	Drawer(1);
	if (lever == 1) {
		if (plever == 1) {
			if (1) {
				//Student student = umembers.find(v);
				cout << "\n#Student: " << uni.findStudent(v[3], v[2], v[4])->surname() << " " << uni.findStudent(v[3], v[2], v[4])->name() << " " << uni.findStudent(v[3], v[2], v[4])->patronymic();
				/*if (student.roles().size()!=0) {
					cout << "\n# Roles:";
					for (int i = 0; i < student.roles().size(); i++) cout << "\n#   " << student.roles()[i];
				}*/
				/*if (student.grades().size()!=0) {
					cout << "\n# Grades:";
					for (auto n : student.grades()) cout << "\n#   " << n.first << ": " << n.second;
				}*/
				if (uni.findStudent(v[3], v[2], v[4])->courseworks().size()!=0) {
					cout << "\n# Courseworks:";
					for (auto n : uni.findStudent(v[3], v[2], v[4])->courseworks()) cout << "\n#   " << n.date() << ": " << n.title();
				}
				/*if (student.scientific_director().size()!=0) {
					cout << "\n# Scientific directors:";
					for (int i = 0; i < student.scientific_director().size(); i++) cout << "\n#   " << student.scientific_director()[i];
				}*/
				//delete student;
			}
		}
		else if (plever == 2) {
			if (1) {
				//Lecturer lecturer = umembers.find(v);
				cout << "\n# Lecturer: " << uni.findLecturer(v[3], v[2], v[4])->surname() << " " << uni.findLecturer(v[3], v[2], v[4])->name() << " " << uni.findLecturer(v[3], v[2], v[4])->patronymic();
				/*if (lecturer.roles()size()!=0) {
					cout << "\n# Roles:";
					for (int i = 0; i < lecturer.roles().size(); i++) cout << "\n#   " << lecturer.roles()[i];
				}*/
				if (uni.findLecturer(v[3], v[2], v[4])->publications().size()!=0) {
					cout << "\n# Roles:";
					for (auto n : uni.findLecturer(v[3], v[2], v[4])->publications()) cout << "\n#   " << n.title() << " " << n.date();
				}
				//delete lecturer;
			}
		}
		else cout << "No person with this name was found.";
	}
	else if (lever == 2) {
		if (1) {
			cout << "\n# Organisation: " << uni.title();
			if (uni.departments().size()!=0) {
				cout << "\n# Departments:";
				for (auto n : uni.departments()) {
					cout << "\n#   " << n.title() << ". Subjects:";
					for (auto q : n.schedule()) cout << "\n#     " << q;
				}
			}
		}
		else cout << "No organisation with this name was found.";

	}
	Drawer(1);
}

void Output::Edit(Student& student, University& uni) {
	Addons addons;
	Drawer(1);
	cout << "\n#Editing student - " << student.surname() << " " << student.name() << " " << student.patronymic();
	cout << "\n# You can perfrom such operations as: ";
	cout << "\n#   'Add coursework'\n#   'Add grade'\n#   'Edit grade'\n#   'Add director'\n#   'Edit director'";
	while (1) {
		Drawer(1); cout << "\n#> ";
		string str; vector<string> v;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
		addons.Split(str, v, ' ');
		if (v[0] == "ADD") {
			if (v[1] == "COURSEWORK") {
				Drawer(1);
				cout << "\n#Input format: <date(mm/dd/yy)> <coursework name>";
				Drawer(1); cout << "\n#> ";
				string s; vector<string> ve; vector<Person> n_ve;
				getline(cin, s);
				addons.Split(s, ve, ' ');
				n_ve.push_back(student);
				CourseWork cw(ve[1],ve[0],n_ve);
				student.addCourseWork(cw);
				break;
			}
			else if (v[1] == "GRADE") {
				Drawer(1);
				cout << "\n#Input format: <subject> <grade>";
				Drawer(1); cout << "\n#> ";
				string s; vector<string> ve;
				getline(cin, s);
				addons.Split(s, ve, ' ');
				//student.addGrade(ve[0], int(ve[1]) - 48);
				break;
			}
			else if (v[1] == "DIRECTOR") {
				Drawer(1);
				cout << "\n#Input format: <name>";
				Drawer(1); cout << "\n#> ";
				string s; vector<string> ve;
				getline(cin, s);
				addons.Split(s, ve, ' ');
				//student.addDirector(); //!!!!!!!!!!!!!!!!!!!!!
				break;
			}
			else cout << "\n#Error: Unknown command. Please try again...";
		}
		else if (v[0] == "EDIT") {
			if (v[1] == "GRADE") {
				Drawer(1);
				cout << "\n#Input format: <subject> <new grade>";
				Drawer(1); cout << "\n#> ";
				string subj; int grade;
				cin >> subj; cin >> grade;
				student.editGrade(subj, grade);
				break;
			}
			else if (v[1] == "DIRECTOR") {
				Drawer(1);
				cout << "\n#Input format: <new name>";
				Drawer(1); cout << "\n#> ";
				string s; vector<string> ve;
				getline(cin, s);
				addons.Split(s, ve, ' ');
				Person director(ve[0], ve[1], ve[2]);
				//student.editDirector(); //!!!!!!!!!!!!!!!!
				break;
			}
			else cout << "\n#Error: Unknown command. Please try again...";
		}
		else cout << "\n#Error: Unknown command. Please try again...";
	}
}
void Output::Edit(Lecturer& lecturer, University& uni) {
	Addons addons;
	Drawer(1);
	cout << "\n#Editing lecturer - " << lecturer.surname() << " " << lecturer.name() << " " << lecturer.patronymic();
	cout << "\n# You can perfrom such operations as: ";
	cout << "\n#   'Add publication'";
	while (1) {
		Drawer(1); cout << "\n#> ";
		string str; vector<string> v;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
		addons.Split(str, v, ' ');
		if (v[0] == "ADD" && v[1] == "PUBLICATION") {
			UniversityMembers<Lecturer> umembers;
			Drawer(1);
			cout << "\n#Title: >";
			string title;
			getline(cin, title);
			cout << "\n#Date (mm/dd/yy): ";
			string date;
			getline(cin, date);
			cout << "\n#Authors (author, author,..): ";
			string auth;
			getline(cin, auth);
			vector<string> a_ve_tmp, a_ve; vector<Person> p_ve;
			addons.Split(auth, a_ve_tmp, ',');
			for (auto n : a_ve_tmp) {
				addons.Split(n, a_ve, ' ');
				p_ve.push_back(*umembers.find(a_ve[2], a_ve[3], a_ve[4]));
			}
			string s;
			getline(cin, s);
			vector<string> ve;
			addons.Split(s, ve, ' ');
			Publication res(title,date,p_ve);
			lecturer.addPublication(res);
			break;
		}
		else cout << "\n#Error: Unknown command. Please try again...";
	}
}

void Output::Drawer(int lever) { //lever takes 0 or 1, 0 means write on the same string, 1 means jump to next one.
	Addons addons;
	int size = addons.GetWindowSize();
	if (size == -1) {
		cout << "#An error occured! Please fix window size, then try again by pressing 'g'.\n";
		int ch = -1;
		while (ch != 103) ch = _getch(); //ASCII g=103
		if (ch == 103) { system("CLS"); };
	}
	else {
		if (lever == 1) cout << endl;
		for (int i = 1; i <= size; i++) {
			cout << '#';
		}
	}
}
