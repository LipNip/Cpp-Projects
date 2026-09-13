#include <iostream>
#include <cstdio> // gets_s
using namespace std;

class student {
    char* surname;
    int* grades;
public:
    student() {
        surname = new char[100];
        grades = new int[5];
    }
    ~student() {
        delete[] surname;
        delete[] grades;
    }
    void set() {
        cout << "Enter surname: ";
        gets_s(surname, 100);
        for (int i = 0; i < 5; i++)
        {
            cout << "Grade " << i + 1 << ": ";
            cin >> grades[i];
            cin.ignore();
        }
    }
    void print() {
        cout << "\nSurname: " << surname << "\n";
        for (int i = 0; i < 5; i++)
        {
            cout << "Grade " << i + 1 << ": " << grades[i] << "\n";
        }
    }
};

class group {
    char* groupName;
    student* students;
    int studentCount;
public:
    group(int studentCount) {
        groupName = new char[100];
        this->studentCount = studentCount;
        students = new student[studentCount];
    }
    ~group() {
        delete[] groupName;
        delete[] students;
    }
    void set() {
        cout << "\nGroup name: ";
        gets_s(groupName, 100);
        for (int i = 0; i < studentCount; i++)
        {
            cout << "Student " << i + 1 << ":\n";
            students[i].set();
        }
    }
    void print() {
        cout << "Group name: " << groupName;
        for (int i = 0; i < studentCount; i++)
        {
            cout << "\n\nStudent " << i + 1 << ": ";
            students[i].print();
        }
    }
};

int main()
{
    group g1(4);
    g1.set();

    group g2(5);
    g2.set();

    cout << "\n";
    g1.print();
    cout << "\n";
    g2.print();
    
    cout << "\n\n";
    return 0;
}