#include <iostream>
#include <iomanip>
using namespace std;

//1. Створює двовимірний динамічний масив.
void createArray(int**& arr, int rows, int cols) {
	arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
}

//2. Заповнює масив випадковими числами.
void setArray(int**& arr, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 101 - 50; // [-50;50]
		}
	}
}

//3. Виводить масив на екран.
void print(int** arr, int rows, int cols) {
	cout << "ROWS: " << rows << "\n";
	cout << "COLS: " << cols << "\n";

	cout << string(50, '-') << "\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(5) << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n" << string(50, '-') << "\n";
}

//4. Добавляє рядок в кінець масиву.
void add_row_end(int**& arr, int& rows, int cols) {
	int** p = new int* [rows + 1];

	for (int i = 0; i < rows; i++)
	{
		p[i] = arr[i];
	}

	p[rows] = new int[cols];

	for (int i = 0; i < cols; i++)
	{
		p[rows][i] = rand() % 101 - 50;
	}

	delete[] arr;
	arr = p;
	p = nullptr;
	rows++;
}

//5. Добавляє рядок напочаток масиву.
void add_row_begin(int**& arr, int& rows, int cols) {
	int** p = new int* [rows + 1];
	p[0] = new int[cols];
	for (int i = 0; i < cols; i++)
	{
		p[0][i] = rand() % 101 - 50;
	}

	for (int i = 0; i < rows; i++)
	{
		p[i + 1] = arr[i];
	}
	delete[] arr;
	arr = p;
	p = nullptr;
	rows++;
}

//6. Добавляє рядок у вказану позицію.
void add_row_position(int**& arr, int& rows, int cols, int pos) {
	int** p = new int* [rows + 1];
	for (int i = 0; i < pos; i++)
	{
		p[i] = arr[i];
	}
	p[pos] = new int[cols];
	for (int i = 0; i < cols; i++)
	{
		p[pos][i] = rand() % 101 - 50;
	}
	for (int i = pos; i < rows; i++)
	{
		p[i + 1] = arr[i];
	}
	delete[] arr;
	arr = p;
	p = nullptr;
	rows++;
}

//7. Добавляє декілька рядків починаючи зі вказаної позиції.
void add_row_block(int**& arr, int& rows, int cols, int pos, int count) {
	int** p = new int* [rows + count];
	for (int i = 0; i < pos; i++)
	{
		p[i] = arr[i];
	}
	for (int i = 0; i < count; i++)
	{
		p[pos + i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			p[pos + i][j] = rand() % 101 - 50;
		}
	}
	for (int i = pos; i < rows; i++)
	{
		p[i + count] = arr[i];
	}
	delete[] arr;
	arr = p;
	p = nullptr;
	rows += count;
}

//8. Видаляє рядок зкінця масиву.
void remove_row_end(int**& arr, int& rows) {
	int** p = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		p[i] = arr[i];
	}
	delete[] arr[rows - 1];
	delete[] arr;
	arr = p;
	rows--;
}

//9. Видаляє рядок з початку масиву.
void remove_row_begin(int**& arr, int& rows) {
	int** p = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		p[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr;
	arr = p;
	rows--;
}

//10. Видаляє двовимірний масив.
void remove(int**& arr, int& rows, int& cols) {
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
	rows = 0;
	cols = 0;
}

int menu() {
	int choice;
	cout << "0 - EXIT\n";
	cout << "1 - FILL ARRAY\n";
	cout << "2 - ADD ROW END\n";
	cout << "3 - ADD ROW BEGIN\n";
	cout << "4 - ADD ROW POSITION\n";
	cout << "5 - ADD ROW BLOCK\n";
	cout << "6 - DELETE ROW END\n";
	cout << "7 - DELETE ROW BEGIN\n";
	cout << "8 - DELETE ARRAY\n";

	cout << "Enter choice: ";
	cin >> choice;

	return choice;
}

int main()
{
	srand(time(NULL));
	
	int rows = 5, cols = 4;
	int** arr = nullptr;
	createArray(arr, rows, cols);
	setArray(arr, rows, cols);
	
	int pos, count;
	do
	{
		system("cls");
		print(arr, rows, cols);

		int choice = menu();

		switch (choice) {
		case 0:
			remove(arr, rows, cols);
			return 0;
		case 1:
			setArray(arr, rows, cols);
			break;
		case 2:
			add_row_end(arr, rows, cols);
			break;
		case 3:
			add_row_begin(arr, rows, cols);
			break;
		case 4:
			cout << "Enter position: ";
			cin >> pos;
			add_row_position(arr, rows, cols, pos);
			break;
		case 5:
			cout << "Enter position: ";
			cin >> pos;
			cout << "Enter count: ";
			cin >> count;
			add_row_block(arr, rows, cols, pos, count);
			break;
		case 6:
			remove_row_end(arr, rows);
			break;
		case 7:
			remove_row_begin(arr, rows);
			break;
		case 8:
			remove(arr, rows, cols);
			break;	
		}

	} while (true);
	
	cout << "\n\n";
	return 0;
}