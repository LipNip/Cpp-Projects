#include <iostream>
using namespace std;

int calculatePower(int num, int power) {
    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result = result * num;
    }
    return result;
}

int main()
{
    int num, power;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter the power: ";
    cin >> power;

    cout << "\n" << num << "^" << power << " = " << calculatePower(num, power);
    
    cout << "\n \n";
    return 0;
}