#include <iostream>
using namespace std;
int main()
{
	int num;

	cout << "Enter number: ";
	cin >> num;

	if (num >= 1 && num <= 9) {
		for (int i = 1; i < 10; i++) {
			cout << "\n" << i << " * " << num << " = " << i * num;
		}
		cout << "\n \n";
	}
	else {
		cout << "Enter a number from 1 to 9!\n";
		}
	
	return 0;
}