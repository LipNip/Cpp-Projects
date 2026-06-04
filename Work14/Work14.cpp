#include <iostream>
using namespace std;
int main()
{
    int num, i = 1;
    cout << "Enter a number (1-9): ";
    cin >> num;
    if (num < 10 && num > 0) {
        while (i < 11) {
            cout << "\n" << i << " * " << num << " = " << i * num;
            i++;
        }
        cout << "\n";
    }
    else
        cout << "\nERROR: It must be a number from one to nine!\n";

    return 0;
}