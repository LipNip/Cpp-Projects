#include <iostream>
using namespace std;

int checkNumber(double num) {
    if (num < 0) {
        return -1;
    }
    else if (num > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    double num;
    cout << "\nEnter a number: ";
    cin >> num;

    cout << checkNumber(num);

    cout << "\n \n";
    return 0;
}