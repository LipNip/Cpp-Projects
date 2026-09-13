#include <iostream>
using namespace std;

class fraction {
    int numerator;
    int denominator;
public:
    fraction() {
        numerator = 0;
        denominator = 1; // Знаменник не може = 0
    }
    void set() {
        cout << "Enter numerator: ";
        cin >> numerator;
        do{
            cout << "Enter denominator: ";
            cin >> denominator;
        } while (denominator == 0);
    }
    void set(int n, int d) {
        numerator = n;
        denominator = d;
    }
    int get_integer() {
        return numerator / denominator;
    }
    double get_double() {
        return (double)numerator / denominator;
    }
    void print() {
        cout << numerator << "/" << denominator;
    }
    fraction add(fraction other) {
        fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }
    fraction sub(fraction other) {
        fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }
    fraction mul(fraction other) {
        fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        return result;
    }
    fraction div(fraction other) {
        fraction result;
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        return result;
    }
};

int main()
{
    fraction f;
    f.set();
    cout << "Fraction 1: ";
    f.print();
    
    cout << "\nInteger: " << f.get_integer();
    cout << "\nDouble: " << f.get_double() << "\n";

    fraction f2;
    f2.set(3, 5);
    cout << "Fraction 2: ";
    f2.print();
    
    fraction sum = f.add(f2);
    cout << "\nSum: ";
    sum.print();

    fraction difference = f.sub(f2);
    cout << "\nDifference: ";
    difference.print();

    fraction product = f.mul(f2);
    cout << "\nProduct: ";
    product.print();

    fraction quotient = f.div(f2);
    cout << "\nQuotient: ";
    quotient.print();

    cout << "\n\n";
    return 0;
}