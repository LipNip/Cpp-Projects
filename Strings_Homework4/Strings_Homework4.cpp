#include <iostream>
using namespace std;

void doubleCharacters(const char str[], char newStr[]) {
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		newStr[j++] = str[i];
		newStr[j++] = str[i];
	}
	newStr[j] = '\0';
}

int main()
{
	const int size = 100;
	char str[size];

	cout << "Enter string: ";
	gets_s(str);

	const int newSize = size * 2;
	char newStr[newSize];

	doubleCharacters(str, newStr);
	cout << "\n----------------------------------";
	cout << "\nOriginal string: " << str;
	cout << "\nDoubled string:  " << newStr;
	cout << "\n----------------------------------";

	cout << "\n\n";
	return 0;
}