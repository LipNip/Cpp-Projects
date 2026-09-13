#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>   // FILE, fopen, fclose, fscanf, fprintf
#include <cstring>  // strcmp
using namespace std;

struct Employee {
    char name[50];
    char surname[50];
    int age;
    char position[50];
    int salary;
};

void addEmployee(Employee employees[], int& size) {
    cout << "Name: ";
    cin >> employees[size].name;

    cout << "Surname: ";
    cin >> employees[size].surname;

    cout << "Age: ";
    cin >> employees[size].age;

    cout << "Position: ";
    cin >> employees[size].position;

    cout << "Salary: ";
    cin >> employees[size].salary;

    size++;
}

void editEmployee(Employee employees[], int size) {
    char surname[50];

    cout << "Enter surname: ";
    cin >> surname;

    for (int i = 0; i < size; i++) {
        if (strcmp(employees[i].surname, surname) == 0) {
            cout << "New name: ";
            cin >> employees[i].name;

            cout << "New surname: ";
            cin >> employees[i].surname;

            cout << "New age: ";
            cin >> employees[i].age;

            cout << "New position: ";
            cin >> employees[i].position;

            cout << "New salary: ";
            cin >> employees[i].salary;

            cout << "Employee edited.\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}

void deleteEmployee(Employee employees[], int& size) {
    char surname[50];

    cout << "Enter surname: ";
    cin >> surname;

    for (int i = 0; i < size; i++) {
        if (strcmp(employees[i].surname, surname) == 0) {
            for (int j = i; j < size - 1; j++) {
                employees[j] = employees[j + 1];
            }
            size--;
            cout << "Employee deleted.\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}

void searchEmployee(Employee employees[], int size) {
    char surname[50];

    cout << "Enter surname: ";
    cin >> surname;

    for (int i = 0; i < size; i++) {
        if (strcmp(employees[i].surname, surname) == 0) {
            cout << "\nName: " << employees[i].name << "\n";
            cout << "Surname: " << employees[i].surname << "\n";
            cout << "Age: " << employees[i].age << "\n";
            cout << "Position: " << employees[i].position << "\n";
            cout << "Salary: " << employees[i].salary << "\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}

void showEmployees(Employee employees[], int size) {
    if (size == 0) {
        cout << "No employees.\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "\nEmployee #" << i + 1 << "\n";
        cout << "Name: " << employees[i].name << "\n";
        cout << "Surname: " << employees[i].surname << "\n";
        cout << "Age: " << employees[i].age << "\n";
        cout << "Position: " << employees[i].position << "\n";
        cout << "Salary: " << employees[i].salary << "\n";
    }
}

int menu() {
    int choice;

    cout << "0 - Exit\n";
    cout << "1 - Add employee\n";
    cout << "2 - Edit employee\n";
    cout << "3 - Delete employee\n";
    cout << "4 - Search by surname\n";
    cout << "5 - Show all employees\n";

    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    const int max = 100;
    Employee employees[max];

    int size = 0;

    char path[100];

    cout << "Enter path: ";
    gets_s(path);

    FILE* file = fopen(path, "r");

    if (file)
    {
        while (fscanf(file, "%s %s %d %s %d", employees[size].name, employees[size].surname, &employees[size].age, employees[size].position, &employees[size].salary) == 5)
        {
            size++;
        }
        fclose(file);
    }

    int choice;
    do {
        choice = menu();

        switch (choice) {
        case 1:
            if (size < max) {
                addEmployee(employees, size);
            } else {
                cout << "List is full!\n";
            }
            break;
        case 2:
            editEmployee(employees, size);
            break;
        case 3:
            deleteEmployee(employees, size);
            break;
        case 4:
            searchEmployee(employees, size);
            break;
        case 5:
            showEmployees(employees, size);
            break;
        }
    }while(choice != 0);

    file = fopen(path, "w");

    if (file)
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(file, "%s %s %d %s %d\n", employees[i].name, employees[i].surname, employees[i].age, employees[i].position, employees[i].salary);
        }
        fclose(file);
    }
    else
    {
        cout << "Error writing file!\n";
    }

    cout << "\n\n";
    return 0;
}