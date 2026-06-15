
#include <iostream>
#include <conio.h>
using namespace std;


void print_names(char names[][30], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << names[i] << "\n";
	}
	cout << "\n";
}

void sort_names(char names[][30], int size) {
	for (int j = 0; j < size - 1; j++) {
		if (strcmp(names[j], names[j + 1]) == 1) {
			char tmp[30];
			strcpy_s(tmp, names[j]);
			strcpy_s(names[j], names[j + 1]);
			strcpy_s(names[j + 1], tmp);
		}
	}
}

int main()
{
	//------------------ ФУНКЦІЇ ДЛЯ РОБОТИ ІЗ СТРІЧКАМИ:
	//----------- 1. getchar() - повертає порядковий номер символа з ASCII таблиці
	//int s = getchar();
	//cout <<"ASCII: " << s << "\n";


	//char s = getchar();
	//cout << "SYMBOL: " << s << "\n";


	//---------- 2. _getch() - записує символ, який ми введемо з клавіатури без натискання enter(#include <conio.h>)
	//char s = _getch();
	//cout << s << "\n";

	//cout << "1 - hi\n";
	//cout << "2 - bye\n";
	//cout << "Enter choice: ";
	//char choice = _getch();


	//if (choice == '1') cout << "Hello\n";
	//else if (choice == '2') cout << "Goodbye\n";



	//----------- 3. putchar() - виводить один символ на консоль
	//char s = 'a';
	//putchar(s);


	//------------------ 4. gets_s() - заповнення стрічки з клавіатури
	//char name[30], surname[30], group[30];

	//cout << "Enter name: ";
	//gets_s(name);
	//cout << "Enter surname: ";
	//gets_s(surname);
	//cout << "Enter group: ";
	//gets_s(group);


	//cout << "Name: " << name << "\n";
	//cout << "Surname: " << surname << "\n";
	//cout << "Group: " << group << "\n";





	//---------- 5. puts() - виводить стрічку на консоль
	//char str[] = "Hello World";
	//puts(str);



	//----------- 6. strcat_s() - об'єднання двох стрічок
	//char str1[30] = "Hello";
	//char str2[30] = " World";

	//strcat_s(str1, str2);
	//cout << str1 << "\n";
	//cout << str2 << "\n";


	//---------- 7. strlen() - повертає довжину стрічки
	//char str[100];
	//cout << "Enter string: ";
	//gets_s(str);

	//cout << "Length: " << strlen(str) << "\n";

	//for (int i = 0; i < strlen(str); i++)
	//{
	//	cout << str[i] << " ";
	//}
	//cout << "\n";

	//for (int i = 0; str[i] != '\0'; i++)
	//{
	//	cout << str[i] << " ";
	//}


	//---------- 8. strchr() - шукає у стрічці символ(першого входження) та повертає вказівник на нього
	//char str[] = "hello";
	//char s = 'l';

	//char* ptr = strchr(str, s);

	//if (!ptr) cout << "Not Found!!!\n";
	//else {
	//	cout << "Exists!!!!\n";
	//	cout << ptr << "\n";//llo
	//}


	//------------- 9. strcmp() - порівняння стрічок. Повертає:
	// 1 - якщо перша стрічка більша від другою
	// -1 - якщо перша стрічка менша від другої
	// 0 - стрічки рівні

	//char str1[] = "hello";//104
	//char str2[] = "world";//119
	//
	//cout << strcmp(str1, str2) << "\n";//-1



	//------------- 10. strcpy_s() - копіює всі дані одніє стрічки в іншу
	//char str1[20] = "hello";//world
	//char str2[20] = "world";//hello
	//char tmp[20];

	//strcpy_s(tmp, str1);//hello
	//strcpy_s(str1, str2);//world
	//strcpy_s(str2, tmp);//hello

	//cout << str1 << "\n";//world
	//cout << str2 << "\n";//hello



	//const int size = 5;
	//char names[size][30]{
	//	"John",
	//	"Ann",
	//	"Doe",
	//	"Max",
	//	"William"
	//};

	//print_names(names, size);
	//sort_names(names, size);
	//print_names(names, size);



	//--------------- 11. strstr() - шукає підстрічку у стрічці
	//char str[] = "hello all world";
	//char substr[] = "all";

	//char* ptr = strstr(str, substr);

	//if (!ptr) cout << "Not Found!!!!\n";
	//else {
	//	cout << "EXISTS!!!!\n";
	//}


	//----- 12. _strrev() - реверс стрічки
	//char str[] = "hello";
	//_strrev(str);
	//cout << str << "\n";


	//--------- 13.atoi() - переконвертація у тип int
	//char str[] = "123";
	//int num = atoi(str);
	//cout << num + 1 << "\n";//124



	//--------- 14._itoa_s() - переконвертація int у стрічку
	//int num = 123;
	//char str[20];
	//_itoa_s(num, str, 10);
	//puts(str);


	//------- 15. _strlwr_s() - зведення у нижні регістр
	//char str[] = "hELlO wOrlD";
	//_strlwr_s(str);
	//cout << str << "\n";


	//------- 16. _strupr_s() - зведення у верхній регістр
	char str[] = "hELlO wOrlD";
	_strupr_s(str);
	cout << str << "\n";







	//const int size = 10;
	//char str[size] = { 'h','e','l','l','o','\0'};
	//int i = 0;
	//while (str[i] != '\0') {
	//	cout << str[i++] << " ";
	//}


	//char str[] = "hello";
	//cout << str[0] << "\n";//h
	//str[0] = 'H';
	//cout << str[0] << "\n";//H

	//cout << str << "\n";



	//char name[30];
	//cout << "Enter name: ";
	//cin >> name;
	//cout << "Name: " << name << "\n";




	cout << "\n\n";
	return 0;
}
