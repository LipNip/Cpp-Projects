#include <iostream>
using namespace std;

void printPerfectNumbersInRange(int lower_bound, int upper_bound) {
	
	if (lower_bound > upper_bound) {
		swap(lower_bound, upper_bound); //swap міняє місцями два значення
	}

	for (int i = lower_bound; i <= upper_bound; i++) // i = 5
	{
		int sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0) {
				sum = sum + j;
			}
		}
		if (sum == i && i > 0) {
			cout << i << " ";
		}
	}
}

int main()
{
	int lower_bound, upper_bound;

	cout << "Enter the lower bound: ";
	cin >> lower_bound;
	cout << "Enter the upper bound: ";
	cin >> upper_bound;
	
	printPerfectNumbersInRange(lower_bound, upper_bound);

	cout << "\n";
	return 0;
}