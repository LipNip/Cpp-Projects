#include <iostream>
#include <iomanip>
using namespace std;

// 1. Показ всіх наявних номерів
void printDirectory(int* arr, int size) {
	cout << "\n" << string(30, '-') << "\n";
	cout << "TELEPHONE DIRECTORY:\n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << arr[i] << "\n";
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
	int index;
	for (int i = 0; i < size; i++) {
		if (arr[i] == number) {
			index = i;
			break;
		}
	}
}

// 4. Пошук потрібного номеру
bool searchNumber(int* arr, int size, int number) {
	bool found = false;
	for (int i = 0; i < size; i++) {
		if (arr[i] == number) {
			return true;
		}
	}
	return false;
}

//5. Cортування за номером телефону від меншого номера до більшого
void sortDirectory(int* arr, int size) {
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
	cout << "1 - Add a new number: \n";
	cout << "3 - Find the number\n";
	cout << "4 - Sort the directory (ascending)\n";
	cout << "5 - Delete all numbers\n";
	
	cout << "Enter choice: ";
	cin >> choice;

	return choice;
}

int main()
{
	srand(time(NULL));
	
	int size;
	cout << "Enter the number of phone numbers: ";
	cin >> size;

	int* arr = nullptr;

	if (size > 0) {
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 9000 + 1000; // [1000; 9999]
		}
	}
	
	int choice, number;

	do {
		printDirectory(arr, size);
		choice = menu();

		switch (choice) {
		case 1:
			cout << "Enter number: ";
			cin >> number;
			addNumber(arr, size, number);
		case 3:
			cout << "Enter number: ";
			cin >> number;
			if (searchNumber(arr, size, number)) {
				cout << "Number " << number << " is FOUND!\n";
			}
			else {
				cout << "Number " << number << " is NOT FOUND!\n";
			}
			break;
		case 4:
			sortDirectory(arr, size);
			break;
		case 5:
			deleteAll(arr, size);
			break;
		}
	} while (choice != 0);

	cout << "\n\n";
	return 0;
}
