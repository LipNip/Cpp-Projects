#include <iostream>
#include <conio.h>
using namespace std;

int countCharOccurrences(const char str[], char symbol) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == symbol) {
			count++;
		}
	}
	return count;
}

int main()
{
	const int size = 100;
	char str[size];

	cout << "Enter string: ";
	gets_s(str);

	cout << "Enter symbol: ";
	char symbol = _getch();

	cout << "\n\n" << string(50, '-');
	cout << "\nString: " << str;
	cout << "\nNumber of occurrences of a character [ " << symbol << " ]: " << countCharOccurrences(str, symbol);
	cout << "\n" << string(50, '-');
	cout << "\n\n";
	return 0;
}