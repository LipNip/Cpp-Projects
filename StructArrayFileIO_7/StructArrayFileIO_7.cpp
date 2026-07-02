#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>   // FILE, fopen, fclose, fprintf, fgetc
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

int main()
{
	int size;
	cout << "Enter size: ";
	cin >> size;

	Student* students = new Student[size];
	
	for (int i = 0; i < size; i++)
	{
		cout << "\nStudent " << i + 1 << "\n";
		set_Student(students[i]);
	}

	char path[] = "Students.txt";
	FILE* file = fopen(path, "w");

	if (!file) {
		cout << "Error opening file for writing!!!\n";
		return -1;
	}
	
	for (int i = 0; i < size; i++){
		fprintf(file, "%s %s %i\n", students[i].name, students[i].surname, students[i].age);
	}

	fclose(file);

	cout << "\nData saved to Students.txt\n";

	FILE* file_r = fopen(path, "r");

	if (!file_r) {
		cout << "Error opening file for reading!!!\n";
		return -1;
	}

	char result[100000];

	int i = 0;
	while (!feof(file_r)) {
	    result[i] = fgetc(file_r);
	    i++;
	}

	result[i - 1] = '\0';
	fclose(file_r);

	cout << "\n" << result << "\n";

	delete[] students;
	cout << "\n\n";
	return 0;
}