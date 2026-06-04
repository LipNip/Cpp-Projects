#include <iostream>
#include <iomanip>
#include <cstdlib> // Для rand()
#include <ctime>   // Для time()
using namespace std;

template <class T>
void setArray(T arr1D[], int rows) {
	for (int i = 0; i < rows; i++)
	{
		arr1D[i] = rand() % 101 - 50;
	}
}

template <class T>
void setArray(T arr1D[][8], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr1D[i][j] = rand() % 101 - 50;
		}
	}
}

template <class T>
void printArray(T arr1D[], int rows) {
	for (int i = 0; i < rows; i++)
	{
		cout << setw(6) << arr1D[i];
	}
}

template <class T>
void printArray(T arr1D[][8], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(6) << arr1D[i][j];
		}
		cout << "\n";
	}
}

template <class T>
T minArry(T arr1D[], int rows) {
	T min = arr1D[0];
	for (int i = 0; i < rows; i++)
	{
		if (min > arr1D[i]) {
			min = arr1D[i];
		}
	}
	return min;
}

template <class T>
T minArry(T arr2D[][8], int rows, int cols) {
	T min = arr2D[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (min > arr2D[i][j]) {
				min = arr2D[i][j];
			}
		}
	}
	return min;
}

int main()
{
	srand(time(NULL));
	
	const int rows = 8, cols = 8;
	int arr1D[rows]{};
	setArray(arr1D, rows);
	printArray(arr1D, rows);
	cout << "\n\nMin element: " << minArry(arr1D, rows) << "\n\n";

	int arr2D[rows][cols]{};
	setArray(arr2D, rows, cols);
	printArray(arr2D, rows, cols);
	cout << "\n\nMin element: " << minArry(arr2D, rows, cols) << "\n\n";
	
	cout << "\n";
	return 0;
}