#include <iostream>
using namespace std;

int sumRange(int num_1, int num_2) {
	
	if (num_1 > num_2) {
		swap(num_1, num_2); // Це ми не вчили. swap міняє місцями два значення. Потрібно, щоб якщо користувач введе 10 і 5, рахувало, а не вибивало 0
	}
	
	int sum = 0;
	for (int i = num_1; i <= num_2; i++)
	{
		sum = sum + i;
	}
	return sum;
}

int main()
{
	int num_1, num_2;

	cout << "Enter the first integer: ";
	cin >> num_1;
	cout << "Enter the second integer: ";
	cin >> num_2;
	
	cout << "\nSum of numbers in a range [" << num_1 << ";" << num_2 << "] = " << sumRange(num_1, num_2);
	
	cout << "\n";
	return 0;
}