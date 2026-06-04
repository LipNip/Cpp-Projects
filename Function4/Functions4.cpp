#include <iostream>
#include <iomanip>
using namespace std;

void fillArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101 - 50;
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << setw(6) << arr[i];
	}
}

void sort_array(int arr[], int size) { // Це Bubble Sort, ви нам показували його на уроці, тому я ним скористався
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int getMax(int arr[], int size) {
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int getMin(int arr[], int size) {
	int min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

void reverseArray(int arr[], int size) {
	for (int i = 0; i < size / 2; i++) // Йдемо лише до середини масиву
	{
		int temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}

int main()
{
	srand(time(NULL));

	const int size = 15;
	int arr[size]{};

	fillArray(arr, size);
	cout << "\nInitial array: ";
	printArray(arr, size);
	cout << "\nMax: " << getMax(arr, size);
	cout << "\nMin: " << getMin(arr, size);
	cout << "\nReverse: ";
	reverseArray(arr, size);
	printArray(arr, size);
	cout << "\nSorted array in descending order: ";
	sort_array(arr, size);
	printArray(arr, size);

	cout << "\n \n";
	return 0;
}