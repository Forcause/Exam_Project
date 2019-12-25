#include "my_output.h"
#include "my_input.h"

int main() {

	University uni = University("Polytech");

	Department iknt = uni.addDepartment("IKNT");
	Department ipmm = uni.addDepartment("IPMM");
	Department isi = uni.addDepartment("ISI");

	iknt.addLecturer("MIHAIL", "ZUBENKO", "PETROVICH");
	iknt.addStudent("ABRAM", "ABRAMOVICH", "ABAKUMOV");
	iknt.addLecturer("AFANAS", "AFANASOVICH", "ABDULOV");
	iknt.addLecturer("MAKSIM", "MAKSIMOVICH", "LOBANOV");
	iknt.addStudent("AFASNASY", "AFANASYOVICH", "ABRAMOVICH");
	iknt.addStudent("AFON", "AFONOVICH", "AFANASYEV");
	iknt.addStudent("FOMA", "FOMAOVICH", "FOMIN");
	iknt.addStudent("GERASIM", "GERASIMOVICH", "ILYIN");
	iknt.addStudent("GLEB", "GLEBOVICH", "ISTOMIN");
	iknt.addStudent("GOGA", "GOGAOVICH", "IVANKOV");
	iknt.addStudent("IAKOV", "IAKOVOVICH", "IVASHOV");
	iknt.addStudent("IGOR", "IGOROVICH", "KALASHNIK");
	iknt.addStudent("ILIA", "ILIAOVICH", "KAPITSA");

	ipmm.addLecturer("AFONASEI", "AFONASEIOVICH", "AKSYONOV");
	ipmm.addStudent("AKIM", "AKIMOVICH", "ALEXANDROV");
	ipmm.addLecturer("ALBERT", "ALBERTOVICH", "ALEXEYEV");
	ipmm.addLecturer("NESTOR", "NESTOROVICH", "NIKITIN");
	ipmm.addStudent("ALEKS", "ALEKSOVICH", "ANDREYEV");
	ipmm.addStudent("ALEXANDER", "ALEXANDROVICH", "ANISIMOV");
	ipmm.addStudent("IMMANUIL", "IMMANUILOVICH", "KAZANTSEV");
	ipmm.addStudent("INNOKENTY", "INNOKENTIYOVICH", "KHABAROV");
	ipmm.addStudent("IOANN", "IOANNOVICH", "KIRILOV");
	ipmm.addStudent("IPPOLIT", "IPPOLITOVICH", "KOLTSOV");
	ipmm.addStudent("IVAN", "IVANOVICH", "KOSTIN");
	ipmm.addStudent("KAZIMIR", "KAZIMIROVICH", "KOVALEVSKY");
	ipmm.addStudent("KHARITON", "KHARITONOVICH", "KOZLOVSKY");

	isi.addLecturer("ALEXEI", "ALEXEIOVICH", "ARTYOMOV");
	isi.addStudent("ANATOLY", "ANATOLYOVICH", "AVDEYEV");
	isi.addLecturer("ANDREI", "ANDREIOVICH", "AVERYANOV");
	isi.addLecturer("OLEG", "NIKOLAYOVICH", "NOSKOV");
	isi.addStudent("ANTON", "ANTONOVICH", "BALABANOV");
	isi.addStudent("FILIPP", "FILIPPOVICH", "ESSEN");
	isi.addStudent("KIRILL", "KIRILLOVICH", "KRUGLOV");
	isi.addStudent("KLIMENT", "KLIMENTOVICH", "KRYLOV");
	isi.addStudent("KOLDAN", "KOLDANOVICH", "KRYMOV");
	isi.addStudent("KONSTANTIN", "KONSTANTINOVICH", "KUTUZOV");
	isi.addStudent("LEONID", "LEONIDOVICH", "LAPIN");
	isi.addStudent("MAKAR", "MAKAROVICH", "LAVROV");
	isi.addStudent("MARK", "MARKOVICH", "LOGINOVSKY");

	Person pers1 = Person("ANDREI", "ANDREIOVICH", "AVERYANOV");
	Person pers2 = Person("IMMANUIL", "IMMANUILOVICH", "KAZANTSEV");
	Person pers3 = Person("GERASIM", "GERASIMOVICH", "ILYIN");
	vector<Person> auth;
	auth.push_back(pers1);
	auth.push_back(pers2);
	auth.push_back(pers3);
	CourseWork course = CourseWork("Research of ancient civilizations", "25.10.2015", auth);
	isi.findStudent("MAKAR", "MAKAROVICH", "LAVROV")->addCourseWork(course);

	Output output; Addons addons; Input input;
	output.Drawer(1);
	cout << "\n#Welcome to the University database!";
	output.Drawer(1);
	bool access = addons.Access();
	while (1) {
		cout << "\n#By pressing '1' you can operate with people.\n#By pressing '2' you can operate with organisation.\n#You can exit bu pressing 'Esc'"; //ASCII 1=49, 2=50, esc=27
		output.Drawer(1);
		int ch = -1;
		if (access) {
			while ((ch != 49) && (ch != 50) && (ch != 27)) ch = _getch();
			if (ch == 49 || ch == 50) input.MainInput(ch, access, uni);
			else if (ch == 27) break;
		}
		else {
			while ((ch != 49) && (ch != 50) && (ch != 27)) ch = _getch(); //using conio::_getch allow us not to see input on the screen.
			if ((ch == 49) || (ch == 50)) input.MainInput(ch, access, uni);
			else if (ch == 27) break;
		}
		output.Drawer(1);
	}

}