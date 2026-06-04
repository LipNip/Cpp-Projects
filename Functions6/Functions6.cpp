#include <iostream>
#include <cmath> //Для sqrt() краще підключати, знайшов в інтернеті
using namespace std;

double area_of_figures(double a, double b, double c) {
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}

double area_of_figures(double a, double b) {
	double s = a * b;
	return s;
}

double area_of_figures(double r) {
	const double PI = 3.141592653589793;
	double s = PI * (r*r);
	return s;
}

int main()
{
	int choice;
	cout << "What area are we looking for?\n1 - Area of a triangle on three sides\n2 - Area of the rectangle\n3 - Area of a circle\n";
	cin >> choice;

	double a, b, c, r;
	if (choice == 1) {
		cout << "Enter a (First side): ";
		cin >> a;
		cout << "Enter b (Second side): ";
		cin >> b;
		cout << "Enter c (Third side): ";
		cin >> c;

		cout << "Area of the triangle = " << area_of_figures(a, b, c);
	}
	else if (choice == 2) {
		cout << "Enter a (First side): ";
		cin >> a;
		cout << "Enter b (Second side): ";
		cin >> b;

		cout << "Area of a rectangle = " << area_of_figures(a, b);
	}
	else if (choice == 3) {
		cout << "Enter r (Radius): ";
		cin >> r;

		cout << "Area of a circle = " << area_of_figures(r);
	}
	
	cout << "\n";
	return 0;
}