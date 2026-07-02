#include <iostream>
using namespace std;

struct WashingMachine {
    char brand[30];     // фірма
    char color[30];     // колір
    double width;       // ширина
    double length;      // довжина
    double height;      // висота
    int power;          // потужність (Вт)
    int spinSpeed;      // швидкість віджиму (об/хв)
    int temperature;    // температура нагріву (°C)
};

void set_WashingMachine(WashingMachine& wm) {
    cout << "Enter brand: ";
    gets_s(wm.brand);

    cout << "Enter color: ";
    gets_s(wm.color);

    cout << "Enter width: ";
    cin >> wm.width;

    cout << "Enter length: ";
    cin >> wm.length;

    cout << "Enter height: ";
    cin >> wm.height;

    cout << "Enter power (W): ";
    cin >> wm.power;

    cout << "Enter spin speed (RPM): ";
    cin >> wm.spinSpeed;

    cout << "Enter temperature (°C): ";
    cin >> wm.temperature;
}

void print_WashingMachine(WashingMachine wm) {
    cout << "\n--- Washing Machine Info ---\n";
    cout << "Brand: " << wm.brand << "\n";
    cout << "Color: " << wm.color << "\n";
    cout << "Width: " << wm.width << "\n";
    cout << "Length: " << wm.length << "\n";
    cout << "Height: " << wm.height << "\n";
    cout << "Power: " << wm.power << "\n";
    cout << "Spin Speed: " << wm.spinSpeed << "\n";
    cout << "Temperature: " << wm.temperature << "\n";
}

int main()
{
    WashingMachine wm;

    set_WashingMachine(wm);
    print_WashingMachine(wm);

    cout << "\n\n";
    return 0;
}