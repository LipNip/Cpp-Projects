#include <iostream>
using namespace std;
int main()
{
	const int size = 10000;
	int arr[size]{};
	
	int number;
	do {
		cout << "Enter the number of elements in the array (up to " << size << " elements): ";
		cin >> number;
	} while (number <= 0 || number > size);

	int numeric;
	for (int i = 0; i < number; i++) {
		cout << "Enter the number by index: [" << i << "]: ";
		cin >> numeric;
		arr[i] = numeric;
	}

	cout << "Your array: ";
	for (int i = 0; i < number; i++) {
		cout << arr[i] << " ";
	}

	double sum = 0;
	int non_zero_count = 0;

	for (int i = 0; i < number; i++) {
		if (arr[i] != 0) {
			sum = sum + arr[i];
			non_zero_count++;
		}
	}

	if (non_zero_count == 0) {
		cout << "\nThere are no non-zero elements in the array.";
		return 0;
	}

	double arithmetic_mean;
	arithmetic_mean = sum / non_zero_count;

	cout << "\nThe arithmetic mean of the non-zero elements of this array: " << arithmetic_mean;
	
	cout << "\n \n";
	return 0;
}