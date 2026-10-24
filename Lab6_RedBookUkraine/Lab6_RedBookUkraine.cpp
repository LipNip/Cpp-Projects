#include <iostream>
#include <string>
using namespace std;

class Animals {
    string name, habitat;
    double age, weight;
public:
    Animals(string name, double age, double weight, string habitat) : name(name), age(age), weight(weight), habitat() {}

    string getName() const { return name; }
    int getAge() const { return age; }
    double getWeight() const { return weight; }
    string getHabitat() const { return habitat; }
    int getPopulation() const { return population; }
};

int main()
{
    
    
    
    
    cout << "\n\n";
    return 0;
}