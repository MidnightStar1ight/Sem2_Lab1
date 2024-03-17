#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**/
const int students_possible_number = 10;
//int students_user_number;
int students_current_number = 0;
int sportics_current_number = 0;
const int max_string = 21;

struct Students {
	char name[max_string];
	char surname[max_string];
	char patronymic[max_string];
	bool sex;
	int group_number;
	int list_number;
	int grades[8];
	float average_grade = 0;
};

struct Sportics {
	char name[max_string];
	char surname[max_string];
	char patronymic[max_string];
	bool sex;
	int age;
	int cloth_size;
	bool is_category;
	int grade;
};

Students students[students_possible_number];

Sportics sportics[students_possible_number];

bool read_file(char* students_file) {
	ifstream File;
	File.open(students_file);
	if (!File.is_open()) return 0;
	char s[21];
	while (File.peek() != EOF) {
		//cout << s << endl;
		File >> students[students_current_number].name, max_string;
		File >> students[students_current_number].surname, max_string;
		File >> students[students_current_number].patronymic, max_string;
		File >> students[students_current_number].sex;
		File >> students[students_current_number].group_number;
		File >> students[students_current_number].list_number;
		File >> students[students_current_number].grades[0]
			>> students[students_current_number].grades[1]
			>> students[students_current_number].grades[2]
			>> students[students_current_number].grades[3]
			>> students[students_current_number].grades[4]
			>> students[students_current_number].grades[5]
			>> students[students_current_number].grades[6]
			>> students[students_current_number].grades[7];
		students_current_number++;
			
	}
	File.close();
	return 1;
}

bool write_file(char* students_file) {
	ofstream File;
	File.open(students_file);
	if (!File.is_open()) return 0;
	for (int i = 0; i < students_current_number; i++) {
		if (i) File << '\n';
		File << students[i].name << '\n';
		File << students[i].surname << '\n';
		File << students[i].patronymic << '\n';
		File << students[i].sex << '\n';
		File << students[i].group_number << '\n';
		File << students[i].list_number << '\n';
		File << students[i].grades[0] << ' '
			<< students[i].grades[1] << ' '
			<< students[i].grades[2] << ' '
			<< students[i].grades[3] << ' '
			<< students[i].grades[4] << ' '
			<< students[i].grades[5] << ' '
			<< students[i].grades[6] << ' '
			<< students[i].grades[7];
	}
}

int _1_new_student(char* students_file) {
	ofstream File;
	File.open(students_file, ios::app);
	if (!File.is_open()) return 0;

	if (students_current_number == students_possible_number) {
		cout << "Error: maxed students count" << endl;
		return 0;
	}

	File << '\n';
	cout << "Entering the iformation about a student..." << endl << endl;

	cin.ignore();
	cout << "Name (up to 20 characters): ";
	cin.getline(students[students_current_number].name, max_string);
	File << students[students_current_number].name << endl;

	cin.ignore();
	cout << "Surname (up to 20 characters): ";
	cin.getline(students[students_current_number].surname, max_string);
	File << students[students_current_number].surname << endl;

	cin.ignore();
	cout << "Patronymic (up to 20 characters): ";
	cin.getline(students[students_current_number].patronymic, max_string);
	File << students[students_current_number].patronymic << endl;

	cout << "Sex (1 - male, 0 - female): ";
	cin >> students[students_current_number].sex;
	File << students[students_current_number].sex << endl;

	cout << "Group number: ";
	cin >> students[students_current_number].group_number;
	File << students[students_current_number].group_number << endl;

	cout << "List number: ";
	cin >> students[students_current_number].list_number;
	File << students[students_current_number].list_number << endl;

	cout << "Grades (press 'Space' after each grade, 8 grades total): ";

	cin >> students[students_current_number].grades[0]
		>> students[students_current_number].grades[1]
		>> students[students_current_number].grades[2]
		>> students[students_current_number].grades[3]
		>> students[students_current_number].grades[4]
		>> students[students_current_number].grades[5]
		>> students[students_current_number].grades[6]
		>> students[students_current_number].grades[7];

	File << students[students_current_number].grades[0] << ' '
		 << students[students_current_number].grades[1] << ' '
		 << students[students_current_number].grades[2] << ' '
		 << students[students_current_number].grades[3] << ' '
		 << students[students_current_number].grades[4] << ' '
		 << students[students_current_number].grades[5] << ' '
		 << students[students_current_number].grades[6] << ' '
		 << students[students_current_number].grades[7];

	students_current_number++;

	File.close();
	return 1;
}

int _2_change_student(char* students_file) {
	int st_num, st_change, st_grade_change(0);
	cout << "What number of student will be changed? ";
	cin >> st_num;
	if (st_num > students_current_number) {
		cout << "Error: this student does not exist";
		return 0;
	}
	st_num--;
	cout << '\n' << "What will be changed? \n"
		"1 - name, \n"
		"2 - surname, \n"
		"3 - patronymic, \n"
		"4 - sex (oh no!!), \n"
		"5 - group number, \n"
		"6 - list number, \n"
		"7 - grades, \n"
		"0 - nothing." << endl;
	cin >> st_change;
	if (st_change == 7) {
		cout << "Enter a number of grade: ";
		cin >> st_grade_change;
	}
	cout << "\n" "Enter a new value: ";
	switch (st_change) {

	case 1:
		cin >> students[st_num].name;
		break;
	case 2:
		cin >> students[st_num].surname;
		break;
	case 3:
		cin >> students[st_num].patronymic;
		break;
	case 4:
		cin >> students[st_num].sex;
		break;
	case 5:
		cin >> students[st_num].group_number;
		break;
	case 6:
		cin >> students[st_num].list_number;
		break;
	case 7:
		cin >> students[st_num].grades[st_grade_change-1];
		break;
	case 0:
		return 0;
	default:
		cout << "Error: wrong number" << endl;
		return 0;
	}
	write_file(students_file);
}

void student_inf(int i) {
	cout << "Student " << i + 1 << ":" << endl;

	cout << "\tName: " << students[i].name << endl;

	cout << "\tSurname: " << students[i].surname << endl;

	cout << "\tPatronymic: " << students[i].patronymic << endl;

	cout << "\tSex: ";
	if (students[i].sex) cout << "male" << endl;
	else cout << "female" << endl;

	cout << "\tGroup number: " << students[i].group_number << endl;

	cout << "\tList number: " << students[i].list_number << endl;

	cout << "\tGrades: ";
	for (int g = 0; g < 8; g++) cout << students[i].grades[g] << ' ';
	cout << endl << endl;
}

void sportic_inf(int i) {
	cout << "Sportic " << i + 1 << ":" << endl;

	cout << "\tName: " << sportics[i].name << endl;

	cout << "\tSurname: " << sportics[i].surname << endl;

	cout << "\tPatronymic: " << sportics[i].patronymic << endl;

	cout << "\tSex: ";
	if (sportics[i].sex) cout << "male" << endl;
	else cout << "female" << endl;

	cout << "\tAge: " << sportics[i].age << endl;

	cout << "\tCloth size: " << sportics[i].cloth_size << endl;

	cout << "\tCategory: ";
	if (sportics[i].sex) cout << "yes" << endl;
	else cout << "no" << endl;

	cout << "\tGrade: " << sportics[i].grade << endl;
	
}

int _3_all_data() {
	for (int i = 0; i < students_current_number; i++) {

		student_inf(i);

	}
	return 0;
}

int _4_current_group() {

	int group;
	cout << "Enter a group: ";
	cin >> group;
	for (int i = 0; i < students_current_number; i++) {
		if (students[i].group_number == group) {
			student_inf(i);
		}
	}

	return 0;
}

void insert_sort(float* p, int n) {
	float* Pos = p;
	for (int i = 1; i <= n; i++) {
		p = Pos;
		while (*p < *(p - 1)) {
			if (*p < *(p - 1)) {
				swap(*p, *(p - 1));
				p--;
			}
		}
		Pos++;
	}
}

int _5_best_students() {

	int len = 8;
	for (int i = 0; i < students_current_number; i++) {
		for (int students_current_grade = 0; students_current_grade < len; students_current_grade++) {
			students[i].average_grade += students[i].grades[students_current_grade];
		}
		students[i].average_grade /= len;
	}

	float arr[students_possible_number];
	for (int i = 0; i < students_current_number; i++) {
		arr[i] = students[i].average_grade;
	}

	insert_sort(arr, students_current_number);
	//cout << (arr[0]) == students[0].average_grade;
	for (int i = students_current_number-1; i >= 0; i--) {
		cout << "Average grade: " << (arr[i]) << "\nStudents : \n";
		for (int j = 0; j < students_current_number; j++) {
			if (students[j].average_grade == arr[i]) {
				cout << students[j].name << ' ' << students[j].surname << endl;
			}
		}
	}
	return 0;
}

int _6_male_and_female() {

	int s_male = 0, s_female = 0;

	for (int i = 0; i < students_current_number; i++) {
		if (students[i].sex) { s_male++; } else { s_female++; }
	}

	cout << "Male students: " << s_male << endl;
	cout << "Female students: " << s_female << endl;

	return 0;
}

int _7_grades_statistics() {

	//int with_2_3(0), with_4_5(0), with_5(0), only_5(0);
	int only_5(0);
	bool s23[students_possible_number], s45[students_possible_number], s5[students_possible_number];
	bool is_3 = false;

	for (int i = 0; i < students_possible_number; i++) {
		s23[i] = s45[i] = s5[i] = false;
	}
	
	for (int i = 0; i < students_current_number; i++) {
		only_5 = 0;
		for (int grade = 0; grade < 8; grade++) {
			if ((students[i].grades[grade] == 2) || (students[i].grades[grade] == 3)) {
				s23[i] = true;
				is_3 = true;
				break;
			}
			if (students[i].grades[grade] == 5) { only_5++; }
		}
		if (is_3) break;
		if (only_5 == 8) { s5[i] = true; } else { s45[i] = true; }
	}

	cout << "Only with 5:" << endl;
	for (int i = 0; i < students_current_number; i++) {
		if (s5[i]) student_inf(i);
	}
	cout << "With 4 and 5:" << endl;
	for (int i = 0; i < students_current_number; i++) {
		if (s45[i]) student_inf(i);
	}
	cout << "Without grant:" << endl;
	for (int i = 0; i < students_current_number; i++) {
		//cout << '!';
		if (s23[i]) student_inf(i);
	}

	return 0;
}

int _8_list_number() {

	int s_list_number;
	cout << "Enter a group number: ";
	cin >> s_list_number;
	for (int i = 0; i < students_current_number; i++) {
		if (students[i].list_number == s_list_number) {
			cout << "Student " << i + 1 << ":" << endl;
			cout << "\tName: " << students[i].name << endl;
			cout << "\tSurname: " << students[i].surname << endl;
			cout << "\tPatronymic: " << students[i].patronymic << endl;
			cout << "\tSex: ";
			if (students[i].sex) cout << "male" << endl;
			else cout << "female" << endl;
			cout << "\tGroup number: " << students[i].group_number << endl;
			cout << "\tList number: " << students[i].list_number << endl;
			cout << "\tGrades: ";
			for (int g = 0; g < 8; g++) cout << students[i].grades[g] << ' ';
			cout << endl << endl;
		}
	}
	return 0;
}

int idz(char *path) {

	ifstream File;
	File.open(path);
	if (!File.is_open()) return 0;
	char s[21];
	while (File.peek() != EOF) {
		//cout << s << endl;
		File >> sportics[sportics_current_number].name, max_string;
		File >> sportics[sportics_current_number].surname, max_string;
		File >> sportics[sportics_current_number].patronymic, max_string;
		File >> sportics[sportics_current_number].sex;
		File >> sportics[sportics_current_number].age;
		File >> sportics[sportics_current_number].cloth_size;
		File >> sportics[sportics_current_number].is_category;
		File >> sportics[sportics_current_number].grade;
		sportics_current_number++;

	}
	File.close();

	int user_grade, male_size;
	cout << "Enter a grade: ";
	cin >> user_grade;
	cout << "\nEnter a male size: ";
	cin >> male_size;

	cout << "Category:" << endl;
	for (int i = 0; i < sportics_current_number; i++) {
		if (sportics[i].is_category) sportic_inf(i);
	}
	cout << "Female team:" << endl;
	for (int i = 0; i < sportics_current_number; i++) {
		if (!sportics[i].sex) sportic_inf(i);
	}
	cout << "Sportics of the " << user_grade << " grade:" << endl;
	for (int i = 0; i < sportics_current_number; i++) {
		if (sportics[i].grade == user_grade) sportic_inf(i);
	}
	cout << "Male sportics with cloth size more than " << male_size << ":" << endl;
	for (int i = 0; i < sportics_current_number; i++) {
		if (sportics[i].cloth_size > male_size) sportic_inf(i);
	}

	return 0;
}

/**/
int main() {
	char path[] = "C:\\Users\\cepra\\Desktop\\Students.txt";
	char idz_path[] = "C:\\Users\\cepra\\Desktop\\idz.txt";
	read_file(path);
	//write_file(path);

	//cout << "How many students will be created? (Up to " << students_possible_number << ", " << students_current_number << " now): ";
	//int s_u_n;
	//cin >> s_u_n;
	//students_user_number += s_u_n;

	int task;
	do {
		cout << "Commands:" << '\n'
			<< "1 - create a new student," << '\n'
			<< "2 - correct student's data," << '\n'
			<< "3 - print all data," << '\n'
			<< "4 - print all data of students of current group," << '\n'
			<< "5 - print last week's best students," << '\n'
			<< "6 - print a number of male and female students," << '\n'
			<< "7 - print cool and not cool students," << '\n'
			<< "8 - print all data of students with current list number," << '\n'
			<< "9 - idz," << '\n'
			<< "0 - exit." << "\n"
			//<< "r - create random students (groups 3372-3376)." << "\n\n"
			<< "Your choice: ";

		cin >> task;
		switch (task) {

		case 1:
			_1_new_student(path);
			break;
		case 2:
			_2_change_student(path);
			break;
		case 3:
			_3_all_data();
			break;
		case 4:
			_4_current_group();
			break;
		case 5:
			_5_best_students();
			//cout << "Haven't done yet (50%)" << endl;
			break;
		case 6:
			_6_male_and_female();
			break;
		case 7:
			_7_grades_statistics();
			break;
		case 8:
			_8_list_number();
			break;
		case 9:
			idz(idz_path);
			break;
		case 0:
			break;
		default:
			cout << "Error: wrong task" << endl;
			break;
		}
	} while (task);

	return 0;
}