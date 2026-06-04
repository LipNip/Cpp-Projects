#include <iostream>
using namespace std;
int main()
{
    int hours;
    cout << "Enter the number of hours: ";
    cin >> hours;

    int minutes;
    cout << "Enter the number of minutes: ";
    cin >> minutes;

    int seconds;
    cout << "Enter the number of seconds: ";
    cin >> seconds;

    int result = (hours * 3600) + (minutes * 60) + seconds;
    
    cout << "\n---------------------------------------------\n" << result << " seconds\n---------------------------------------------\n";

    int hours2 = result / 3600;
    int minutes2 = (result - (hours2 * 3600)) / 60;
    int seconds2 = result - (hours2 * 3600) - (minutes2 * 60);
    
    cout << "\n" << "Number of hours: " << hours2 << "\n";
    cout << "Number of minutes: " << minutes2 << "\n";
    cout << "Number of seconds: " << seconds2 << "\n";

    return 0;
}