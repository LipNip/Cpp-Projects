#include <iostream>
using namespace std;
int main()
{
    double num_1, num_2, num_3, num_4;

    cout << "Enter the first number: ";
    cin >> num_1; 
    cout << "Enter the second number: ";
    cin >> num_2; 
    cout << "Enter the third number: ";
    cin >> num_3; 
    cout << "Enter the fourth number: ";
    cin >> num_4; 

    (num_1 >= num_2 && num_1 >= num_3 && num_1 >= num_4) ? cout << "Maximum first number ( " << num_1 << " ).\n" : (num_2 >= num_1 && num_2 >= num_3 && num_2 >= num_4) ? cout << "Maximum second number ( " << num_2 << " ).\n" : (num_3 >= num_1 && num_3 >= num_2 && num_3 >= num_4) ? cout << "Maximum third number ( " << num_3 << " ).\n" : cout << "Maximum fourth number ( " << num_4 << " ).\n";
    (num_1 <= num_2 && num_1 <= num_3 && num_1 <= num_4) ? cout << "Minimum first number ( " << num_1 << " ).\n" : (num_2 <= num_1 && num_2 <= num_3 && num_2 <= num_4) ? cout << "Minimum second number ( " << num_2 << " ).\n" : (num_3 <= num_1 && num_3 <= num_2 && num_3 <= num_4) ? cout << "Minimum third number ( " << num_3 << " ).\n" : cout << "Minimum fourth number ( " << num_4 << " ).\n";
    
    return 0;
}