#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // find()
using namespace std;

class Employee {
    string name, surname, phone;
public:
    Employee() : name("No name"), surname("No surname"), phone("No phone") {}
    Employee(string name, string surname, string phone) : name(name), surname(surname), phone(phone) {}

    void print()const {
        cout << "Name: " << name << "\n";
        cout << "Surname: " << surname << "\n";
        cout << "Phone: " << phone << "\n";
    }
};

class Department {
    string departmentName;
    Employee* manager;
    vector<Employee*> subordinates;
public:
    Department(const string& departmentName, Employee* manager) : departmentName(departmentName), manager(manager) {}

    void addEmployee(Employee* employee) { subordinates.push_back(employee); }
    void removeEmployee(Employee* employee) {
        auto it = find(subordinates.begin(), subordinates.end(), employee);
        if (it != subordinates.end()) {
            subordinates.erase(it);
        }
        else {
            cout << "Not found!";
        }
    }

    void print()const {
        cout << "Department name: " << departmentName << "\n";
        cout << "Manager:\n";
        manager->print();
        cout << "\n";
        for (size_t i = 0; i < subordinates.size(); i++)
        {
            subordinates[i]->print();
            cout << "\n";
        }
    }
};

int main()
{
    Employee manager1("John", "Jonson", "+380501112233");
    Employee manager2("Tim", "Cook", "(408)996–1010");
    
    Employee emp1("Andriy", "Shevchenko", "+380633334455");
    Employee emp2("Maksym", "Boyko", "+380974445566");
    Employee emp3("Oksana", "Bondar", "+380935556677");
    Employee emp4("Taras", "Tkachenko", "+380666667788");

    Department dep1("IT Department", &manager1);
    dep1.addEmployee(&emp1);
    dep1.addEmployee(&emp2);
    dep1.print();

    cout << "\n";
    
    Department dep2("Marketing Department", &manager2);
    dep2.addEmployee(&emp3);
    dep2.addEmployee(&emp4);
    dep2.print();
    
    cout << "\n\n";
    return 0;
}