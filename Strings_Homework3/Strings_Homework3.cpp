#include <iostream>
using namespace std;

void replace_o_with_ha(const char str[], char newStr[]) {
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'o') {
			newStr[j++] = 'h';
			newStr[j++] = 'a';
		}
		else {
			newStr[j++] = str[i];
		}
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
	replace_o_with_ha(str, newStr);
	cout << "\n----------------------------------";
	cout << "\nString: " << str;
	cout << "\nNew string (o = ha): " << newStr;
	cout << "\n----------------------------------";

	cout << "\n\n";
	return 0;
}