#include <iostream>
#include <cstring>  // strlen() strcpy_s()
using namespace std;

class Employee {
    char* surname;
    int age;
    char gender; // M/F
    double salary;
    char phone[20];
public:
    Employee() {
        surname = new char[100];
        surname[0] = '\0';
        age = 0;
        gender = '-';
        salary = 0;
        strcpy_s(phone, 20, "None");
    }

    Employee(const char* surname, int age, char gender, double salary, const char* phone) {
        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);
        this->age = age;
        this->gender = gender;
        this->salary = salary;
        strcpy_s(this->phone, 20, phone);
    }

    Employee(const Employee& other) {
        this->surname = new char[strlen(other.surname) + 1];
        strcpy_s(this->surname, strlen(other.surname) + 1, other.surname);
        this->age = other.age;
        this->gender = other.gender;
        this->salary = other.salary;
        strcpy_s(this->phone, 20, other.phone);
    }

    void set() {
        char tempBuffer[256];   // щоб не вийти за межі
        cout << "Enter surname: ";
        gets_s(tempBuffer, 256);
        setSurname(tempBuffer);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter gender (M/F): ";
        cin >> gender;
        cout << "Enter salary: ";
        cin >> salary;
        cin.ignore();
        cout << "Enter phone number: ";
        gets_s(phone, 20);
    }

    ~Employee() {
        delete[] surname;
    }

    void setSurname(const char* surname) {
        delete[] this->surname;
        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);
    }
    const char* getSurname() const { return surname; }

    void setAge(int age) { this->age = age; }
    int getAge() const { return age; }

    void setGender(char gender) { this->gender = gender; }
    char getGender() const { return gender; }

    void setSalary(double salary) { this->salary = salary; }
    double getSalary() const { return salary; }

    void setPhone(const char* phone) { strcpy_s(this->phone, 20, phone); }
    const char* getPhone() const { return phone; }

    void print() const {
        cout << "Employee: " << surname << " | Age: " << age
            << " | Gender: " << gender << " | Salary: " << salary
            << " | Phone: " << phone << "\n";
    }  
};

void showEmployeeInfo(Employee emp) {
    emp.print();
}

Employee createDefaultManager() {
    Employee manager("Petrov", 35, 'M', 25000.50, "+380671112233");
    return manager;
}

int main()
{
    Employee emp1("Ivanov", 28, 'M', 18500.0, "+380931234567");
    emp1.print();
    
    cout << "\nCASE 1: Direct initialization from another object\n";
    Employee emp2 = emp1;
    cout << "emp2 data: ";
    emp2.print();

    cout << "\nCASE 2: Passing object to a function by value\n";
    showEmployeeInfo(emp1);

    cout << "\nCASE 3: Returning object from a function by value\n";
    Employee emp3 = createDefaultManager();
    cout << "emp3 data: ";
    emp3.print();

    cout << "\n\n";
    return 0;
}