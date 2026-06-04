#include <iostream>
using namespace std;
int main()
{
	int number, reverse = 0;
	cout << "Enter a number: ";
	cin >> number; //12345
	int number_copy = number;
	while (number_copy != 0) {
		int last_digit = number_copy % 10; // Кожен раз last_digit буде дорівнювати остані цифрі
		reverse = (reverse * 10) + last_digit;
		number_copy = number_copy / 10; // Забираємо останю цифру від числа
	}
	
	cout << "\nReverse of the number ( " << number << " ): " << reverse << "\n";

	return 0;
}