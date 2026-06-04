#include <iostream>
using namespace std;
int main()
{
    int num, sum = 0, max, min;

    cout << "Enter number: ";
    cin >> num;

    max = min = num;   // перше число = початкові max і min
   
    while (num != 0) {
        sum = sum + num;

        if (num > max) 
            max = num;

        if (num < min) 
            min = num;
        
        cout << "Enter number: ";
        cin >> num; 
    } 
    cout << "\nsum:      " << sum;
    cout << "\nmax:      " << max;
    cout << "\nmin:      " << min << "\n";
    return 0;
}