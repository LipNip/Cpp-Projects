#include <iostream>
using namespace std;

bool isPalindrome(const char str[]) {
	int length = strlen(str);
	for (int i = 0; i < length / 2; i++)
	{
		if (tolower(str[i]) != tolower(str[length - 1 - i])) { // tolower() — зведення у нижній регістр (_strlwr_s() працює з рядком, а не символом). Нижній регістр потрібний, тому що Anna — це паліндром, але A != a, тому потрібно, щоб було anna, тоді a = a.
			return false;
		}
	}
	return true;
}

int main()
{
	const int size = 100;
	char str[size];

	cout << "Enter string: ";
	gets_s(str);

	cout << "\n----------------------------------";
	cout << "\nString: " << str;
	cout << "\nIs palindrome? ";
	if (isPalindrome(str)) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
	
	cout << "\n\n";
	return 0;
}