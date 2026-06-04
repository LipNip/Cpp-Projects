#include <iostream>
using namespace std;

bool is_prime(int num) {
	if (num < 2) return false;

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int num;

	cout << "Enter num: ";
	cin >> num;

	cout << is_prime(num);
	
	cout << "\n";
	return 0;
}