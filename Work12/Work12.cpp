#include <iostream>
using namespace std;
int main()
{
    double lower, upper, num;
    cout << "Lower bound of the range: ";
    cin >> lower;
    cout << "Upper bound of the range: ";
    cin >> upper;
    cout << "Number to check: ";
    cin >> num;

    if (lower > upper) {
        swap(lower, upper); // Це ми ще не вчили, але я написав для себе. Метод swap просто міняє місцями дві змінні одного типу. 
        cout << "\nPerhaps you meant: (lower =  " << lower << " and upper = " << upper << " ), the program corrected it!\n";
    }


    if (num >= lower && num <= upper)
        cout << "\nThe number ( " << num << " ) is within the range.\n";
    else
        cout << "\nThe number ( " << num << " ) is not within the range.\n";
 
    return 0;
}