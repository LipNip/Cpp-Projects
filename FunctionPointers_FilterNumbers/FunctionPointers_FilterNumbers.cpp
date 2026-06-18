#include <iostream>
#include <ctime> // для time(NULL)
#include <cstdlib> // для rand(), srand(), system()
using namespace std;

void set_arr(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101 - 50; // [-50 ; 50]
	}
}

void print_arr(int* arr, int size) {
	cout << "SIZE: " << size << "\n";
	cout << string(50, '-') << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n" << string(50, '-') << "\n";
}

bool isPrime(int num) {
	bool prime = num >= 2;
	for (int i = 2; i * i <= num; i++)
	{
		prime = (num % i == 0) ?  false : prime;
	}
	return prime;
}

//1 - Шукає прості числа і заносить їх у новий масив
int* getPrimes(int* arr, int size, int& newSize) {
	newSize = 0;
	for (int i = 0; i < size; i++)
	{
		newSize = newSize + isPrime(arr[i]);
	}
	int* newArr = new int[newSize];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		bool condition = isPrime(arr[i]);
		condition && (newArr[index] = arr[i]);	// Якщо condition дорівнює false - права частина не виконається, якщо true виконуємо праву чатину. Те саме що if(condition){
										    	//																												newArr[index] = arr[i];
												//																											}	
		index = index + condition; // Індекс зсунеться вперед ТІЛЬКИ якщо число нам підійшло
	}
	return newArr;
}

//2 - Шукає усі числа кратні трьом і заносить їх у новий масив
int* getMultiplesOf3(int* arr, int size, int& newSize) {
	newSize = 0;
	for (int i = 0; i < size; i++)
	{
		newSize = newSize + (arr[i] % 3 == 0); // true 1, false 0
	}

	int* newArr = new int[newSize];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		bool condition = (arr[i] % 3 == 0);
		condition && (newArr[index] = arr[i]);
		index += condition;
	}
	return newArr;
}

//3 - Шукає усі парні числа і заносить їх у новий масив
int* getEvens(int* arr, int size, int& newSize) {
	newSize = 0;
	for (int i = 0; i < size; i++)
	{
		newSize = newSize + (arr[i] % 2 == 0);
	}
	int* newArr = new int[newSize];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		bool condition = (arr[i] % 2 == 0);
		condition && (newArr[index] = arr[i]);
		index += condition;
	}
	return newArr;
}



int menu() {
	int choice;
	cout << "\n" << string(30, '*') << "\n";
	cout << "1 - Prime numbers\n";
	cout << "2 - Multiples of 3\n";
	cout << "3 - Even numbers\n";
	cout << "0 - EXIT\n";
	cout << "Any other key - Exit\n";
	cout << string(30, '*') << "\n";

	cout << "Enter choice: ";
	cin >> choice;

	return choice;
}

int main()
{
	srand(time(NULL));

	int size;
	cout << "Enter size: ";
	cin >> size;

	int* arr = new int[size];
	set_arr(arr, size);

	int* (*functions[3])(int*, int, int&) = { //[тип_даних] [назва_змінної] = {значення_1, значення_2, значення_3};
		getPrimes,			// choice = 1
		getMultiplesOf3,	// choice = 2
		getEvens			// choice = 3
	};

	system("cls");
	print_arr(arr, size);
	int newSize = 0;
	int choice = menu();
	while (choice >= 1 && choice <= 3) {
		int* resultArr = functions[choice - 1](arr, size, newSize);
		system("cls");
		print_arr(resultArr, newSize);
		delete[] resultArr;

		choice = menu();
	}

	delete[] arr;
	
	cout << "\n\n";
	return 0;
}