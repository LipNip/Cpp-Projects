#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    srand(time(NULL));

	const int size = 10000;
	int arr[size]{};

	int number;
	do {
		cout << "Enter the number of elements in the array (up to " << size << " elements): ";
		cin >> number;
	} while (number <= 0 || number > size);

	for (int i = 0; i < number; i++) {
		arr[i] = rand() % 101 - 50;
	}
	
	cout << "Initial array:\n";
	for (int i = 0; i < number; i++) {
		cout << setw(5) << arr[i];
	}

	for (int i = 0; i < number / 2; i++) // Йдемо лише до середини масиву
	{
		int temp = arr[i];
		arr[i] = arr[number - 1 - i];
		arr[number - 1 - i] = temp;
	}
	
	cout << "\n\nModified array:\n";
	for (int i = 0; i < number; i++) {
		cout << setw(5) << arr[i];
	}

    cout << "\n \n";
    return 0;
}