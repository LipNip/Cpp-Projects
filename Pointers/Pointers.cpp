#include <iostream>
#include <iomanip>
using namespace std;

void func(int* a) {
	*a = 100;
	cout << *a << '\n';
}

/////////////////////////////////
void swap_(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/////////////////////////////////

void ser_arr(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		//cout << arr[i] << " ";
		cout << *( arr + i ) << " ";
	}
	cout << "\n";
}


void func2(int* arr) {
	arr[4] = 100;
}





void set_arr(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		 *(arr + i) = rand() % 101 - 50;
	}
}

void print_arr(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
}

int min(int* arr, int size) {
	int min = *arr;
	for (int i = 0; i < size; i++)
	{
		if (min > *(arr + i)) { /////////////
			min = *(arr + i);
		}
	}
	return min;
}


int* mina(int* a, int* b) {
	if (*a < *b) {
		return a;
	}
	else {
		return b;
	}
}

int main()
{
	srand(time(NULL));
	
	int a = 1;
	int b = 4;
	
	cout << mina(&a, &b);
	
	
	//int a = 4;
	//int* ptr = &a;
	//int** dptr = &ptr;

	//cout << &a << "\n"; // адреса а
	//cout << *dptr << "\n" // адреса 
	


	
	
	/*const int size = 10;
	int arr[size]{};

	set_arr(arr, size);
	print_arr(arr, size);
	cout << "\n\nMin: " << min(arr, size);*/





	//---------------- Арифметика вказівників(++ -- - *(розвдресування) +=число -=число +числ)

	/*const int size = 5;
	int arr[size]{3, 4, 5, 21, 5};
	int* ptr = arr;
	
	ser_arr(arr, size);*/

	


	/*cout << *arr << " ";
	cout << *(arr + 1) << " ";
	cout << *(arr + 2) << " ";*/

	/*cout << *ptr << "\n";
	ptr++;
	cout << *ptr << "\n";
	ptr++;
	cout << *ptr << "\n";
	ptr--;
	cout << *ptr << "\n";
	ptr += 2;
	cout << *ptr << "\n";
	ptr = ptr - 3;
	cout << ptr << "\n";

	cout << *ptr << "\n";
	int* ptr3 = arr + 3;
	cout << *ptr << "\n";*/

	
	/*const int size = 5;
	int arr[size]{3, 4, 5, 21, 5};
	cout << *arr << "\n";
	
	cout << &arr[0] << "\n";
	cout << arr << "\n";
	func2(arr);
	cout << arr[4] << "\n";*/
	
	/////////////////////////////////
	/*int a = 4, b = 7;
	cout << "A: " << a << " | B: " << b << "\n";
	swap_(&a, &b);
	cout << "A: " << a << " | B: " << b << "\n";*/
	/////////////////////////////////
	
	
	
	/*int a = 2;
	int* ptr = &a;

	cout << &a << "\n";
	cout << ptr << "\n";
	cout << &ptr << "\n";
	cout << *ptr << "\n";

	*ptr = 100;
	cout << a << "\n";
	cout << "\n\n";

	int* p = nullptr;
	int  a = 100;
	p = &a;*/


	/*int a = 2;
	cout << a << "\n";
	func(&a);
	cout << a << "\n";

	cout << "\n";*/
	return 0;
}