#include <iostream>
#include <string>
using namespace std;

class Student {
    string name, surname, gradebook;
    int age;
public:
    Student(): name("No name"), surname("No surname"), age(0), gradebook("No gradebook") {}
    Student(string name, string surname, int age, string gradebook): name(name), surname(surname), age(age), gradebook(gradebook) {}

    void print()const {
        cout << "Name: " << name << "\n";
        cout << "Surname: " << surname << "\n";
        cout << "Age: " << age << "\n";
        cout << "Gradebook: " << gradebook << "\n";
    }
};

class Aspirant : public Student {
    string diploma;
public:
    Aspirant(): Student(), diploma("No name diploma") {}
    Aspirant(string name, string surname, int age, string gradebook, string diploma):
        Student(name, surname, age, gradebook), diploma(diploma) {}

    void print()const {
        Student::print();
        cout << "Diploma: " << diploma << "\n";
    }
};

int main()
{
    Student s("John", "Jonson", 18, "KI-12");
    s.print();
    
    cout << "\n";

    Aspirant a("Alex", "Vance", 19, "CD-33", "Cloud systems development");
    a.print();

    cout << "\n\n";
    return 0;
}