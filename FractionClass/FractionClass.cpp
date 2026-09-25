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
            if (denominator < 0) {                  // Якщо знаменник від'ємний, міняємо знаки в обох для операторів порівняння
                numerator = -numerator;
                denominator = -denominator;
            }      
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
        return numerator == other.numerator && denominator == other.denominator;
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
        return *this;
    }
};

fraction operator+(const fraction& f1, const fraction& f2) {
    fraction f;
    f.set_numerator(f1.get_numerator() * f2.get_denominator() + f2.get_numerator() * f1.get_denominator());
    f.set_denominator(f1.get_denominator() * f2.get_denominator());
    return f;
}

fraction operator-(const fraction& f1, const fraction& f2) {
    fraction f;
    f.set_numerator(f1.get_numerator() * f2.get_denominator() - f2.get_numerator() * f1.get_denominator());
    f.set_denominator(f1.get_denominator() * f2.get_denominator());
    return f;
}

fraction operator*(const fraction& f1, const fraction& f2) {
    fraction f;
    f.set_numerator(f1.get_numerator() * f2.get_numerator());
    f.set_denominator(f1.get_denominator() * f2.get_denominator());
    return f;
}

fraction operator/(const fraction& f1, const fraction& f2) {
    fraction f;
    f.set_numerator(f1.get_numerator() * f2.get_denominator());
    f.set_denominator(f1.get_denominator() * f2.get_numerator());
    return f;
}

int main()
{
    
    
    cout << "\n\n";
    return 0;
}