#include <iostream>
using namespace std;
int main()
{
	long long int number, number_copy;
	int i = 0;

	cout << "Enter a number: ";
	cin >> number;

	number_copy = number;
	
	if (number_copy == 0) // Якщо користувач введе 0 то це одна цифра також
		i = 1;

	while (number_copy != 0) { 
		number_copy = number_copy / 10; 
		i++; 
	}
	
	cout << "\nNumber of digits in the entered number ( " << number << " ): " << i << "\n";
	
	return 0;
}