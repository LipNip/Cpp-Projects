#include <iostream>
using namespace std;

void replace_a_with_b(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) // Цикл працює доти, доки поточний символ не є '\0'
	{
		if (str[i] == 'a') {
			str[i] = 'b';
		}
	}
}

int main()
{
	const int size = 100;
	char str[size];

	cout << "Enter string: ";
	gets_s(str);

	cout << "\nString: " << str;
	replace_a_with_b(str);
	cout << "\nNew string (a = b): " << str;

	cout << "\n\n";
	return 0;
}