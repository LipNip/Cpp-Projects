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
		arr[i] = rand() % 4;	//від 0 до 3 включно щоб був більший шанс випадіння нуля
	}

	cout << "Initial array:\n";
	for (int i = 0; i < number; i++) {
		cout << setw(5) << arr[i];
	}
	
	int writeIndex = 0;

	for (int i = 0; i < number; i++) {
		if (arr[i] != 0) {
			arr[writeIndex] = arr[i];
			writeIndex++;
		}
	}

	cout << "\nModified array:\n";
	for (int i = 0; i < writeIndex; i++)
	{
		cout << setw(5) << arr[i];
	}

    cout << "\n \n";
    return 0;
}