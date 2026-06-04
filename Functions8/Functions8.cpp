#include <iostream>
#include <iomanip>
#include <cstdlib> // Додано для rand() та srand()
#include <ctime>   // Додано для time()
using namespace std;

void fillRandomMatrix9x9(int matrix[][9], int lower_bound = -50, int upper_bound = 50) {
	if (lower_bound > upper_bound) {
		swap(lower_bound, upper_bound);
	}
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			matrix[i][j] = lower_bound + rand() % (upper_bound - lower_bound + 1);		// min + rand() % (max - min + 1) формула для генерації числа в діапазоні (знайшов в інтернеті)
		}
	}
}

void printMatrix(int matrix[][9]) {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << setw(6) << matrix[i][j];
		}
		cout << "\n";
	}
}

int main()
{
	srand(time(NULL));
	
	int lower_bound, upper_bound;
	int matrix[9][9];

	cout << "Enter the lower bound: ";
	cin >> lower_bound;
	cout << "Enter the upper bound: ";
	cin >> upper_bound;
	
	fillRandomMatrix9x9(matrix, lower_bound, upper_bound);
	printMatrix(matrix);
	
	cout << "\n";
	return 0;
}