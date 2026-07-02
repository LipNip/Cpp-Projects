#pragma warning(disable: 4996)

#include <iostream>
using namespace std;

void set_arr(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101 - 50;
	}
}

void print_console_arr(int* arr, const int size) {

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}


void print_file_arr(int* arr, int size, FILE* file) {
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%i ", arr[i]);
	}
}

int main()
{

	//---------------------- Ввід\вивід даних на консоль (чиста С)
	//printf("Hello World");

	//int a = 2, b = 1;
	//printf("a: %i | b: %i", a, b);

	// --------- Символи після % (плейсхолдери):
	// i, d - цілі числа
	// g - дійсні числа
	// c - символ
	// s - стрічка
	// p - вказівник


	//char name[] = "John";
	//printf("My name is: %s", name);



	//int a, b;
	//printf("Enter number: ");
	//scanf_s("%i", &a);
	//printf("Enter number: ");
	//scanf_s("%i", &b);

	//printf("A: %i\nB: %i", a, b);



	//int a, b;
	//printf("Enter numbers: ");
	//scanf_s("%i%i", &a, &b);
	//printf("%i + %i = %i", a, b, a + b);




	//------------------------ ЗАПИС\ЗЧИТУВАННЯ ДАНИХ У\З ФАЙЛУ
	// fprintf() - для запису
	// fscanf() - для зчитування

	//char path[] = "data.txt";
	//FILE* file = fopen(path, "w");

	//if (!file) {
	//	cout << "Error path!!!!\n";
	//	return -1;
	//}

	//fprintf(file, "Hello\nWorld");

	//fclose(file);



	/////////////////////////

	//char path[] = "data.txt";
	//FILE* file = fopen(path, "w");

	//if (!file) {
	//	cout << "Error path!!!!";
	//	return -1;
	//}

	//for (int i = 0; i < 100; i++)
	//{
	//	fprintf(file, "i: %i\n", i);
	//}

	//fclose(file);






	//------------ Записати у файл таблицю множення всіх стовпців від 1 до 10 у вигляді виразу (1 * 1 = 1)

	//char path[] = "table.txt";
	//FILE* file = fopen(path, "w");


	//if (!file) {
	//	cout << "Error path!!!!";
	//	return -1;
	//}

	//for (int i = 1; i <= 10; i++)
	//{
	//	for (int j = 1; j <= 10; j++)
	//	{
	//		fprintf(file, "%i * %i = %i\n", i, j, i * j);
	//	}
	//	fprintf(file, "\n");
	//}

	//fclose(file);



	//-------------------- 
	//char path[] = "data.txt";
	//FILE* file = fopen(path, "w");

	//if (!file) {
	//	cout << "Error path!!!!";
	//	return -1;
	//}

	//char name[30], surname[30];
	//int age;

	//cout << "Enter name: ";
	//gets_s(name);

	//cout << "Enter surname: ";
	//gets_s(surname);

	//cout << "Enter age: ";
	//cin >> age;

	//fprintf(file, "%s %s %i", name, surname, age);
	//fclose(file);




	//char path[] = "data.txt";
	//FILE* file = fopen(path, "a");

	//if (!file) {
	//	cout << "Error path!!!!";
	//	return -1;
	//}
	//

	//char group[30];
	//cout << "Enter group: ";
	//gets_s(group);

	//fprintf(file, " %s", group);
	//fclose(file);


	//----------- зчитування
	//char name[30], surname[30], group[30];
	//int age;
	//char path[] = "data.txt";
	//FILE* file = fopen(path, "r");

	//if (!file) {
	//	cout << "Error path!!!!";
	//	return -1;
	//}
	//
	//fscanf(file, "%s%s%i%s", name, surname, &age, group);
	//fclose(file);

	//cout << "Name: " << name << '\n';
	//cout << "Surname: " << surname << '\n';
	//cout << "Age: " << age << '\n';
	//cout << "Group: " << group << '\n';


	//-------------------
	//const int size = 10;
	//int arr[size]{};

	//set_arr(arr, size);
	//print_console_arr(arr, size);

	//char path[] = "data.txt";
	//FILE* file = fopen(path, "w");

	//if (!file) {
	//	cout << "Error path\n";
	//	return -1;
	//}

	//print_file_arr(arr, size, file);
	//fclose(file);




	// -------------------- Посимвольне зчитування\запис у\з файлу
	// fgetc() - зчитування 1 символу
	// fputc() - запис 1 символу
	// feof() - зчитування поки не кінець файлу

	//char path[] = "data.txt";
	//FILE* file = fopen(path, "r");

	//char result[100000];
	//if (!file) {
	//	cout << "Error path!!!";
	//	return -1;
	//}
	//

	//int i = 0;
	//while (!feof(file)) {
	//	result[i] = fgetc(file);
	//	i++;
	//}
	//result[i - 1] = '\0';

	//fclose(file);
	//cout << result << "\n";





	//char path[] = "data.txt";
	//FILE* file = fopen(path, "w");

	//if (!file) {
	//	cout << "Error path!!!";
	//	return -1;
	//}
	//

	//fputc('h', file);
	//fputc('e', file);
	//fputc('l', file);
	//fputc('l', file);
	//fputc('o', file);

	//fclose(file);


	//-------------- Зчитати весь код із файлу Source.cpp та вивести його на консоль








	cout << "\n\n";
	return 0;
}
