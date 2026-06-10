#include <iostream>
using namespace std;

void calculateFactorial(int* num, long long* result) {
    *result = 1;
    for (int i = 1; i <= *num; i++) 
        *result *= i;
}

int main()
{
    int* num = new int; //пам'ять для числа
    long long* result = new long long; //память для факторіалу

    cout << "Enter num: ";
    cin >> *num;

    if (*num < 0) 
        cout << "Factorial is not defined for negative numbers";
    else {
        calculateFactorial(num, result);
        cout << "Factorial " << *num << " = " << *result;
    }
    
    delete num;
    delete result;
    cout << "\n\n";
    return 0;
}