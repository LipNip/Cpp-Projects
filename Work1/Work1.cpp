#include <iostream>
using namespace std;
int main()
{
	double a; //length
	cout << "Enter the length of the rectangle: ";
	cin >> a;
	double b; //width
	cout << "Enter the width of the rectangle: ";
	cin >> b;
	
	double P = 2 * (a + b);
	double S = a * b;

	cout << "\n" << "Perimeter of the rectangle: " << P << "\n";
	cout << "Area of the rectangle: " << S << "\n";

	return 0;
}