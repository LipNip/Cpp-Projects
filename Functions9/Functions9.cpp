#include <iostream>
using namespace std;

int findMaxElement(int arr[], int newSize) {
	int max = arr[0];
	for (int i = 0; i < newSize; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

double findMaxElement(double arr[], int newSize) {
	double max = arr[0];
	for (int i = 0; i < newSize; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

template <class T>
void printArray(T arr[], int newSize) {
	for (int i = 0; i < newSize; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	const int size = 10000;
	int newSize, type;

	do{
		cout << "Choose the array type (int - 1, double - 2): ";
		cin >> type;
		if(type != 1 && type != 2) {
			cout << "Invalid choice. Try again!\n";
		}
	} while (type != 1 && type != 2);
	
	cout << "Enter the array size (up to 10000 elements): ";
	cin >> newSize;
	
		if (type == 1) {
			int arr[size]{};
			for (int i = 0; i < newSize; i++)
			{
				cout << "Enter the number for the index [" << i << "]: ";
				cin >> arr[i];
			}
			printArray(arr, newSize);
			cout << "\nMax: " << findMaxElement(arr, newSize);
		}
		else if (type == 2) {
			double arr[size]{};
			for (int i = 0; i < newSize; i++)
			{
				cout << "Enter the number for the index [" << i << "]: ";
				cin >> arr[i];
			}
			printArray(arr, newSize);
			cout << "\nMax: " << findMaxElement(arr, newSize);
		}
		
	cout << "\n";
	return 0;
}