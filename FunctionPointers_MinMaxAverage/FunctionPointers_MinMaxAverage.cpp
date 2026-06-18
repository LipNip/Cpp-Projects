#include <iostream>
#include <ctime> // для time(NULL)
#include <cstdlib> // для rand(), srand(), system()
using namespace std;

void set_arr(double* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = (rand() % 5001) / 100.0; // дійсні числа від 0 до 50
	}
}

void print_arr(double* arr, int size) {
	cout << "SIZE: " << size << "\n";
	cout << string(50, '-') << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n" << string(50, '-') << "\n";
}

double minElement(double* arr, int size) {
	double min = arr[0];
	for (int i = 1; i < size; i++)
	{
		min = (min > arr[i]) ? arr[i] : min;	//(умова) ? значення_якщо_ТАК : значення_якщо_НІ; В завдані було сказано не використовувати if і switch
	}
	return min;
}

double maxElement(double* arr, int size) {
	double max = arr[0];
	for (int i = 1; i < size; i++)
	{
		max = (max < arr[i]) ? arr[i] : max;
	}
	return max;
}

double average(double* arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
	}
	return sum / size;
}

int menu() {
	int choice;

	cout << "1 - Min element\n";
	cout << "2 - Max element\n";
	cout << "3 - Average\n";
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

	double* arr = new double[size];
	set_arr(arr, size);
	
	double (*functions[3])(double*, int) = {
		minElement,
		maxElement,
		average
	};

	system("cls");
	print_arr(arr, size);
	int choice = menu();

	while(choice >= 1 && choice <=3){
		cout << "\nResult: " << functions[choice - 1](arr, size) << "\n\n";
		system("pause");

		system("cls");
		print_arr(arr, size);
		choice = menu();
	}
	
	delete[] arr;

	cout << "\n\n";
	return 0;
}