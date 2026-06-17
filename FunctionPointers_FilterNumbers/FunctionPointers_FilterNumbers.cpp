#include <iostream>
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



int* getPrimes(int* arr, int size) {

}

int menu() {
	int choice;

	cout << "1 - Prime numbers\n";
	cout << "2 - Multiples of 3\n";
	cout << "3 - Even numbers\n";
	cout << "Any other key - Exit\n\n";

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
	
	
	

	cout << "\n\n";
	return 0;
}