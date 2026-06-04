#include <iostream>
using namespace std;
int main()
{
	int number, max = 0;
	cout << "Enter a number: ";
	cin >> number;
	int number_copy = number;

	if (number_copy < 0) // Якщо користувач введе відємне число то програма перетворить на додатнє
		number_copy = -number_copy; // -(-123) = 123

	while (number_copy != 0) {
		int last_digit = number_copy % 10;
		if (last_digit > max)
			max = last_digit;
		number_copy = number_copy / 10;
	}
	
	cout << "\nLargest digit of the entered number ( " << number << " ): " << max << "\n";
	
	return 0;
}