#include <iostream>
using namespace std;
int main()
{
    int num, count = 0, sum = 0, reverse = 0, copy_num;
    cout << "Enter number: ";
    cin >> num;
    copy_num = num;
    if (num < 0) {
        num = -num;
    }

    do {
        sum = sum + (num % 10);
        reverse = (reverse * 10) + (num % 10);
        num = num / 10;
        count++;
    } while (num != 0);

    if (copy_num < 0) {
        reverse = -reverse;
    }

    cout << "\n" << "Number of digits of the number: " << count << "\n";
    cout << "Sum of the digits of the number: " << sum << "\n";
    cout << "Reversed number: " << reverse << "\n";
    return 0;
}