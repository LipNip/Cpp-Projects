#include <iostream>
#include <windows.h> // Обов'язково для Sleep()
using namespace std;

int main()
{
    system("color 02");
    cout << "\n" << string(30, '-') << "\n";
    cout << "\n" << string(30, '-');

    int s = 0;
    int s2 = 0;
    int m1 = 0;
    int m2 = 0;
    int h1 = 0;
    int h2 = 0;
    cout << "\x1b[1A\r";
    for (int i = 1; i < 60; i++)
    {
        if (i > 9) {
            i = 0;
            s2++;
        }
        if (s2 == 6 && i == 0) {
            s2 = 0;
            i = 0;
            m1++;
        }

        if (m1 > 9) {
            m1 = 0;
            m2++;
        }

        if (m2 == 6 && m1 == 0) {
            m2 = 0;
            m1 = 0;
            h1++;
        }

        if (h1 > 9) {
            h1 = 0;
            h2++;
        }

        cout << "\r" << h2 << h1 << ":" << m2 << m1 << ":" << s2 << i;
        // this_thread::sleep_for(chrono::seconds(1)); #include <thread> #include <chrono>
        Sleep(1000); 
    }

    /*cout << "\nHello";
    system("color 02");
    cout << "\rll";*/

    cout << "\n\n";
    return 0;
}