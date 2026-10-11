#include <iostream>
#include <string>
using namespace std;

class Pet {
    string name;
    double age, weight;
public:
    Pet(): name("No name"), age(0), weight(0) {}
    Pet(string name, double age, double weight): name(name), age(age), weight(weight) {}

    void print()const {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Weight: " << weight << "\n";
    }
};

class Dog : public Pet{
    string breed;
public:
    Dog(): Pet(), breed("No breed") {}
    Dog(string name, double age, double weight, string breed):
        Pet(name, age, weight), breed(breed) {}

    void print()const {
        Pet::print();
        cout << "Breed: " << breed << "\n";
    }
};

class Cat : public Pet {
    string furColor;
public:
    Cat() : Pet(), furColor("No fur color") {}
    Cat(string name, double age, double weight, string furColor) :
        Pet(name, age, weight), furColor(furColor) {
    }

    void print()const {
        Pet::print();
        cout << "Fur color: " << furColor << "\n";
    }
};

class Parrot : public Pet {
    bool canSpeak;
public:
    Parrot() : Pet(), canSpeak(false) {}
    Parrot(string name, double age, double weight, bool canSpeak) :
        Pet(name, age, weight), canSpeak(canSpeak) {
    }

    void print()const {
        Pet::print();
        cout << "Can speak: " << (canSpeak ? "Yes" : "No") << "\n";
    }
};

int main()
{
    Dog myDog("Rex", 3.5, 15.8, "German Shepherd");
    myDog.print();
    cout << "\n";
    Cat myCat("Luna", 2.2, 4.2, "Black");
    myCat.print();
    cout << "\n";
    Parrot myParrot("Kesha", 1.1, 0.3, true);
    myParrot.print();
    
    cout << "\n\n";
    return 0;
}