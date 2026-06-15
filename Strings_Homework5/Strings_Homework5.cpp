#include <iostream>
using namespace std;

int calculateSmsCost(const char str[], int price) {
	int length = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		length++;
	}
	return length * price;
}

int main()
{
	const int size = 100;
	char str[size];

	cout << "Enter message: ";
	gets_s(str);

	int price = 10;

	cout << "\nMessage: " << str;
	int cost = calculateSmsCost(str, price);
	cout << "\nMessage price: " << cost;

	cout << "\n\n";
	return 0;
}