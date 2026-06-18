#include <iostream>
#include <ctime> // для time(NULL)
#include <cstdlib> // для rand(), srand(), system()
using namespace std;

void setDirectory(int*& arr, int size) {
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 9000 + 1000; // [1000; 9999]
	}
}

// 1. Показ всіх наявних номерів
void printDirectory(int* arr, int size) {
	cout << "\n" << string(30, '-') << "\n";
	cout << "TELEPHONE DIRECTORY:\n";
	if (size == 0) {
		cout << "Directory is EMPTY!\n";
	}else{
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ".  " << arr[i] << "\n";
	}
	}
	cout << string(30, '-') << "\n";
}

// 2. Додавання нового номеру телефону
void addNumber(int*& arr, int& size, int number) {
	int* p = new int[size + 1];

	for (int i = 0; i < size; i++) {
		p[i] = arr[i];
	}

	p[size] = number;
	delete[] arr;
	arr = p;   
	size++;       
}

// 3. Видалення зазначеного номеру з довідника
void deleteNumber(int*& arr, int& size, int number) {
	if (size == 0) return; // Не видаляємо з порожнього масиву. return зупиняємо функцію (далі код не виконається)
	
	int index = -1;

	for (int i = 0; i < size; i++) {
		if (arr[i] == number) {
			index = i;
			break;
		}
	}

	if (index == -1) { // Якщо номер не знайдено
		cout << "\n" << string(30, '-') << "\n";
		cout << "Number " << number << " not found to delete!";
		cout << "\n" << string(30, '-') << "\n";
		return;
	}

	int* p = new int[size - 1];

	for (int i = 0; i < index; i++)
	{
		p[i] = arr[i];
	}

	for (int i = index; i < size - 1; i++)
	{
		p[i] = arr[i + 1];
	}
	
	delete[] arr;
	arr = p;
	size--;
	cout << "\n" << string(30, '-') << "\n";
	cout << "Number " << number << " deleted successfully.";
	cout << "\n" << string(30, '-') << "\n";
}

// 4. Пошук потрібного номеру
bool searchNumber(int* arr, int size, int number) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == number) {
			return true;
		}
	}
	return false;
}

//5. Cортування за номером телефону від меншого номера до більшого
void sortDirectory(int* arr, int size) {
	if (size < 2) return; // Немає сенсу сортувати 0 або 1 елемент
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// 6. Видалення всіх номерів
void deleteAll(int*& arr, int& size) {
	delete[] arr;
	arr = nullptr;
	size = 0;
}

int menu() {
	int choice;

	cout << "\n" << string(30, '*') << "\n";
	cout << "1 - Add a new number\n";
	cout << "2 - Delete number\n";
	cout << "3 - Find the number\n";
	cout << "4 - Sort the directory (ascending)\n";
	cout << "5 - Delete all numbers\n";
	cout << "0 - EXIT\n";
	cout << string(30, '*') << "\n";

	cout << "Enter choice: ";
	cin >> choice;

	return choice;
}

int main()
{
	srand(time(NULL));
	
	int size;
	do{
	cout << "Enter the number of phone numbers: ";
	cin >> size;
	} while (size <= 0);

	int* arr = nullptr;
	setDirectory(arr, size);
	
	int choice, number;

	do {
		system("cls");
		printDirectory(arr, size);
		choice = menu();

		switch (choice) {
		case 1:
			cout << "Enter number: ";
			cin >> number;
			addNumber(arr, size, number);
			break;
		case 2:
			cout << "Enter number: ";
			cin >> number;
			deleteNumber(arr, size, number);
			system("pause");
			break;
		case 3:
			cout << "Enter number: ";
			cin >> number;
			if (searchNumber(arr, size, number)) {
				cout << "Number " << number << " is FOUND!\n";
			}
			else {
				cout << "Number " << number << " is NOT FOUND!\n";
			}
			system("pause");
			break;
		case 4:
			sortDirectory(arr, size);
			break;
		case 5:
			deleteAll(arr, size);
			break;
		}
	} while (choice != 0);
	
	delete[] arr;

	cout << "\n\n";
	return 0;
}