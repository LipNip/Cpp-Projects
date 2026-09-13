#include <iostream>
#include <cstring> // strcpy_s
using namespace std;

class student {
    char surname[100];
    int age;
public:
    void set(const char* surname, int age) {
        strcpy_s(this->surname, surname);
        this->age = age;
    }
    const char* get_surname() { // const щоб не було порушення інкапсуляції
        return surname;
    }
    int get_age() {
        return age;
    }
    void print() {
        cout << "Surname: " << surname << "\n";
        cout << "Age: " << age << "\n";
    }
};

int main()
{
    student s1;
    s1.set("Jack", 15);
    s1.print();

    cout << "\n\n";
    return 0;
}