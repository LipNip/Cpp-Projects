#include <iostream>
using namespace std;

int checkArrayUsage(const char str[]) { // const, тому що ми не змінюємо масив
	int used = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		used++;
	}
	return used;
}

int main()
{
	const int size = 50;
	char str[size];

	cout << "Enter string: ";
	gets_s(str);

	int used = checkArrayUsage(str);
	int free = size - used;
	cout << "\n----------------------------------\nUsed: " << used << "\nFree: " << free << "\n----------------------------------";
	
	cout << "\n\n";
	return 0;
}