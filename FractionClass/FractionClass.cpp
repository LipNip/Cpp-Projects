#include <iostream>
#include <stdexcept> // Бібліотека для винятків
using namespace std;

class fraction {
    int numerator, denominator;
public:
    fraction() {
        numerator = 0;
        denominator = 1; // Знаменник не може = 0
    }
    fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("The denominator cannot be zero!"); // Це ми не вчили. Викидаємо помилку, якщо знаменник = 0. throw - зупиняє виконання програми і викидає цю помилку нагору, 
                                                                       // invalid_argument - готовий клас помилки з вбудованої бібліотеки <stdexcept> (крім invalid_argument бувають: out_of_range,
                                                                       // length_error, runtime_error, overflow_error тощо).   
        }
        if (denominator < 0) {                  // Якщо знаменник від'ємний, міняємо знаки в обох для операторів порівняння
            numerator = -numerator;
            denominator = -denominator;         // Щоб прибрати -, бо - на - дає +
        }
        this->numerator = numerator;
        this->denominator = denominator;
    }
    void set_numerator(int numerator) {
        this->numerator = numerator;
    }
    void set_denominator(int denominator) {
        if (denominator == 0) {
            throw invalid_argument("The denominator cannot be zero!");
        }
        if (denominator < 0) { 
            numerator = -numerator;
            denominator = -denominator;
        }
        this->denominator = denominator;
    }
    int get_numerator() const { return numerator; }
    int get_denominator() const { return denominator; }
    void print_fraction() const {
        cout << numerator << "/" << denominator << "\n";
    }
    int getIntegerPart() const { return numerator / denominator; }
    double toDouble() const { return (double)numerator / denominator; }

    bool operator==(const fraction& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }
    bool operator!=(const fraction& other) const {
        return !(*this == other);
    }
    bool operator<(const fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }
    bool operator>(const fraction& other) const {
        return other < *this;
    }
    bool operator<=(const fraction& other) const {
        return !(*this > other);
    }
    bool operator>=(const fraction& other) const {
        return !(*this < other);
    }
    fraction& operator+=(const fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        return *this;
    }
    fraction& operator-=(const fraction& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        return *this;
    }
    fraction& operator*=(const fraction& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        return *this;
    }
    fraction& operator/=(const fraction& other) {
        if (other.numerator == 0) {
            throw invalid_argument("The denominator cannot be zero!");
        }
        numerator *= other.denominator;
        denominator *= other.numerator;
        if (denominator < 0) { 
            numerator = -numerator;
            denominator = -denominator;
        }
        return *this;
    }
};

fraction operator+(fraction f1, const fraction& f2) { return f1 += f2; }
fraction operator-(fraction f1, const fraction& f2) { return f1 -= f2; }
fraction operator*(fraction f1, const fraction& f2) { return f1 *= f2; }
fraction operator/(fraction f1, const fraction& f2) { return f1 /= f2; }

int main()
{
    int numerator, denominator;
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    try{                                        // В блок try обгортаємо той код, який може потенційно викликати помилку
    fraction f1(numerator, denominator);
    fraction f2(1, 5);

    f1.print_fraction();
    f2.print_fraction();

    cout << "f1 == f2: " << (f1 == f2 ? "True" : "False") << "\n"; // Дужки потрібні через пріоритет операторів.
    cout << "f1 != f2: " << (f1 != f2 ? "True" : "False") << "\n";
    
    fraction f3 = f1 + f2;
    cout << "f1 + f2 = "; f3.print_fraction();
    }
    catch (const invalid_argument& e) {         // Блок catch виконається якщо в блоці try вилетить помилка. Програма не завершиться аварійно.
        cout << "Error: " << e.what() << "\n";
    }
    
    cout << "\n\n";
    return 0;
}