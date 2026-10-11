#include <iostream>
#include <string>
using namespace std;

class Passport {
    string name, surname, number, issueDate;
public:
    Passport(): name("No name"), surname("No surname"), number("No number"), issueDate("No issue date") {}
    Passport(string name, string surname, string number, string issueDate): name(name), surname(surname), number(number), issueDate(issueDate) {}

    void print()const {
        cout << "Name: " << name << "\n";
        cout << "Surname: " << surname << "\n";
        cout << "Number: " << number << "\n";
        cout << "Issue date: " << issueDate << "\n";
    }
};

class ForeignPassport : public Passport {
    string visas, foreignNumber;
public:
    ForeignPassport(): Passport(), visas("No visas"), foreignNumber("No foreign number") {}
    ForeignPassport(string name, string surname, string number, string issueDate, string visas, string foreignNumber):
        Passport(name, surname, number, issueDate), visas(visas), foreignNumber(foreignNumber) {}

    void print()const {
        Passport::print();
        cout << "Visas: " << visas << "\n";
        cout << "Foreign number: " << foreignNumber << "\n";
    }
};

int main()
{
    Passport p("Ivan", "Petrenko", "AB123456", "15.04.2018");
    p.print();

    cout << "\n";

    ForeignPassport f("Oleg", "Koval", "ME987654", "20.08.2021", "Schengen, USA", "FG555666");
    f.print();

    cout << "\n\n";
    return 0;
}