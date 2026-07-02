#include <iostream>
#include <cstring> // strcmp()
using namespace std;

struct Car {
    char name[30];          // назва
    double length;          // довжина
    double groundClearance; // висота посадки
    double engineVolume;    // об'єм двигуна
    int power;              // потужність двигуна
    double wheelDiameter;   // діаметр коліс
    char color[20];         // колір
    char gearbox[20];       // тип коробки передач
    int mileage;            // пробіг
};

void set_car(Car& c) {
    cout << "\nEnter car name: ";
    gets_s(c.name);

    cout << "Enter length: ";
    cin >> c.length;

    cout << "Enter ground clearance: ";
    cin >> c.groundClearance;

    cout << "Enter engine volume: ";
    cin >> c.engineVolume;

    cout << "Enter power: ";
    cin >> c.power;

    cout << "Enter wheel diameter: ";
    cin >> c.wheelDiameter;
    cin.ignore();

    cout << "Enter color: ";
    gets_s(c.color);

    cout << "Enter gearbox type (manual/automatic): ";
    gets_s(c.gearbox);

    cout << "Enter mileage: ";
    cin >> c.mileage;
    cin.ignore();
}

void set_cars(Car* cars, int size) {
    for (int i = 0; i < size; i++)
    {
        set_car(cars[i]);
    }
    cout << '\n';
}

void print_car(Car& c) {
    cout << "\n--- Car Info ---\n";
    cout << "Name: " << c.name << "\n";
    cout << "Length: " << c.length << "\n";
    cout << "Ground clearance: " << c.groundClearance << "\n";
    cout << "Engine volume: " << c.engineVolume << "\n";
    cout << "Power: " << c.power << "\n";
    cout << "Wheel diameter: " << c.wheelDiameter << "\n";
    cout << "Color: " << c.color << "\n";
    cout << "Gearbox: " << c.gearbox << "\n";
    cout << "Mileage: " << c.mileage << "\n";
}

void print_cars(Car* cars, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << "Car " << i + 1;
        print_car(cars[i]);
    }
}

int find_car_by_name(Car* cars, int size, const char* name) {           
    for (int i = 0; i < size; i++)                          //  strcmp() - порівняння стрічок.Повертає:
    {                                                       //  1 - якщо перша стрічка більша від другою
        if (strcmp(cars[i].name, name) == 0) {              //  -1 - якщо перша стрічка менша від другої
            return i;                                       //  0 - стрічки рівні
        }
    }                                                                                                                                                                     
    return -1;
}

void add_car(Car*& cars, int& size) {
    Car* newCars = new Car[size + 1];

    for (int i = 0; i < size; i++)
    {
        newCars[i] = cars[i];
    }
    cout << "\n--- Add new car ---\n";
    set_car(newCars[size]);

    size++;
    delete[] cars;
    cars = newCars;
}

void delete_car(Car*& cars, int& size, int index) {
    Car* newCars = new Car[size - 1];

    for (int i = 0; i < index; i++)
    {
        newCars[i] = cars[i];
    }

    for (int i = index; i < size - 1; i++)
    {
        newCars[i] = cars[i + 1];
    }

    size--;
    delete[] cars;
    cars = newCars;
}

int main()
{
    int size;

    do{
    cout << "Enter size: ";
    cin >> size;
    cin.ignore();
    } while (size <= 0);

    Car* cars = new Car[size];
    
    set_cars(cars, size);
    print_cars(cars, size);

    char name[30];
    cout << "\nEnter car name to found: ";
    gets_s(name);

    int index = find_car_by_name(cars, size, name);

    if (index == -1) {
        cout << "Car not found!\n";
    }
    else {
        cout << "Car found!\n";
        print_car(cars[index]);
    }

    add_car(cars, size);

    cout << "Enter car name to delete: ";
    gets_s(name);
    
    index = find_car_by_name(cars, size, name);
    if (index == -1) {
        cout << "\nCar not found!\n";
    }
    else {
        delete_car(cars, size, index);
    }

    delete[] cars;
    cout << "\n\n";
    return 0;
}