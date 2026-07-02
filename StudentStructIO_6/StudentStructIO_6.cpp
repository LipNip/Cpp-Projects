#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio> // FILE, fopen, fprintf
using namespace std;

struct Student {
	char name[50];
	char surname[50];
	int age;
};

void set_Student(Student& s) {
	cout << "Enter name: ";
	cin >> s.name;

	cout << "Enter surname: ";
	cin >> s.surname;

	cout << "Enter age: ";
	cin >> s.age;
}

void print_Student(const Student& s) {		// передаю за константним посиланням для оптимізації
	cout << "Name: " << s.name << "\n";
	cout << "Surname: " << s.surname << "\n";
	cout << "Age: " << s.age << "\n";
}

int main()
{
	Student s1,s2;

	set_Student(s1);

	char path[] = "student.txt";
	FILE* file = fopen(path, "w");

	if (!file) {
		cout << "Error opening file for writing!!!\n";
		return -1;
	}
		
	fprintf(file, "%s %s %i", s1.name, s1.surname, s1.age);
	
	fclose(file);

	cout << "\nData saved to student.txt\n";
	
	FILE* file_r = fopen(path, "r");

	if (!file_r) {
		cout << "Error opening file for reading!!!\n";
		return -1;
	}

	fscanf(file_r, "%s %s %i", s2.name, s2.surname, &s2.age);

	fclose(file_r);

	cout << "\n";
	print_Student(s2);

	cout << "\n\n";
	return 0;
}