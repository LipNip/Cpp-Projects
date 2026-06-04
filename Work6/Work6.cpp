#include <iostream>
using namespace std;
int main()
{
    int number;
    cout << "Enter a four-digit number: ";
    cin >> number;

    int first = number / 1000;
    cout << "\n \n------------------------------------\n" << "First digit number: " << first << "\n";

    int second = (number / 100) % 10;
    cout << "Second digit number: " << second << "\n";

    int third = (number / 10) % 10;
    cout << "Third digit number: " << third << "\n";

    int last = number % 10;
    cout <<"Fourth digit number:" << last << "\n------------------------------------\n \n";
    return 0;
}