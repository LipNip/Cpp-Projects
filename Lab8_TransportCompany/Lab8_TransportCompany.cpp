// Lab8_TransportCompany.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
using namespace std;

class Transport {
    string departure, destination;
    double distance, baseCost;
public:
    //1. Конструктори
    Transport() : departure("No departure"), destination("No destination"), distance(0), baseCost(0) {}
    Transport(string departure, string destination, double distance, double baseCost) : departure(departure), destination(destination), distance(distance), baseCost(baseCost) {}

    //2. Віртуальний метод для виводу інформації про перевезення на консоль
    virtual void print()const {
        cout << "Departure: " << departure << "\n";
        cout << "Destination: " << destination << "\n";
        cout << "Distance: " << distance << "\n";
        cout << "Base cost: " << baseCost << "\n";
    }
    
    //3. Чисто віртуальний метод для розрахунку вартості перевезення
    virtual double calculateCost()const = 0;

    //4. Для кожного поля (get і set) – методи
    string getDeparture()const { return departure; }
    void setDeparture(const string& departure) { this->departure = departure; }

    string getDestination()const { return destination; }
    void setDestination(const string& destination) { this->destination = destination; }

    double getDistance()const { return distance; }
    void setDistance(double distance) { this->distance = distance; }

    double getBaseCost()const { return baseCost; }
    void setBaseCost(double baseCost) { this->baseCost = baseCost; }
};

class RailwayTransport : public Transport {
    double beddingCost;
public:
    RailwayTransport() : Transport(), beddingCost(0) {}
    RailwayTransport(string departure, string destination, double distance, double baseCost, double beddingCost) : Transport(departure, destination, distance, baseCost), beddingCost(beddingCost) {}

    double calculateCost()const override { return getBaseCost() + beddingCost; }
    void print()const {
        Transport::print();
        cout << "Bedding cost: " << beddingCost << "\n";
    }
};

int main()
{
   
    
    cout << "\n\n";
    return 0;
}