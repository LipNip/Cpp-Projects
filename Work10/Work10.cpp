#include <iostream>
using namespace std;
int main()
{
    double num_1, num_2, num_3, num_4;
    int count = 0;

    cout << "Enter the first number: ";
    cin >> num_1;
    cout << "Enter the second number: ";
    cin >> num_2;
    cout << "Enter the third number: ";
    cin >> num_3;
    cout << "Enter the fourth number: ";
    cin >> num_4;
    
    if (num_1 != 0)
        count++;
    if (num_2 != 0)
        count++;
    if (num_3 != 0)
        count++;
    if (num_4 != 0)
        count++;

    cout << "\n" << "Number of values that are not equal to zero: " << count << "\n";

    return 0;
}