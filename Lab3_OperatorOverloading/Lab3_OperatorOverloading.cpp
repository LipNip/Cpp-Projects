#include <iostream>
#include <cstdlib> // srand(), rand()
#include <ctime>   // time()
using namespace std;

class Student {
    int* grades;
    int size;
    double average;
public:
    Student() {
        size = 12;
        grades = new int[size];
        for (int i = 0; i < size; i++)
        {
            grades[i] = 0;
        }
        average = 0;
    }
    Student(int size) {
        this->size = size;
        grades = new int[size];
        for (int i = 0; i < size; i++)
        {
            grades[i] = 0;
        }
        average = 0;
    }
    Student(const Student& other) {
        size = other.size;
        grades = new int[size];
        for (int i = 0; i < size; i++)
        {
            grades[i] = other.grades[i];
        }
        average = other.average;
    }
    ~Student() {
        delete[] grades;
    }
    void setSize(int size) {
        if (size <= 0) {
            return;
        }
        delete[] grades;
        this->size = size;
        grades = new int[size];
        for (int i = 0; i < size; i++)
        {
            grades[i] = 0;
        }
        average = 0;
    }
    void setGrade(int index, int value) {
        if (index >= 0 && index < size) {
            grades[index] = value;
            findAverage();
        }
    }
    void setAverage(double average) {
        this->average = average;
    }
    int getSize() const {
        return size;
    }
    int getGrade(int index) const {
        if (index >= 0 && index < size) {
            return grades[index];
        }
        return -1;
    }
    double getAverage() const {
        return average;
    }
    int findMaxIndex() const {
        if (size == 0) return -1;
            
        int maxIdx = 0;
        for (int i = 1; i < size; i++)
        {
            if (grades[maxIdx] < grades[i]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }
    int findMinIndex() const {
        if (size == 0) return -1;

        int minIdx = 0;
        for (int i = 1; i < size; i++)
        {
            if (grades[minIdx] > grades[i]) {
                minIdx = i;
            }
        }
        return minIdx;
    }
    int findSum() const {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum = sum + grades[i];
        }
        return sum;
    }
    double findAverage() {
        if (size == 0) {
            average = 0;
            return average;
        }
        int sum = findSum();
        average = (double)sum / size;
        return average;
    }
    void fillRandom() {
        for (int i = 0; i < size; i++)
        {
            grades[i] = 1 + rand() % 12;
        }
        findAverage();
    }
    Student& operator=(const Student& other) {
        if (this == &other) {
            return *this;
        }
        delete[] grades;
        size = other.size;
        grades = new int[size];
        for (int i = 0; i < size; i++)
        {
            grades[i] = other.grades[i];
        }
        average = other.average;
        return *this;
    }
    bool operator>(const Student& other) const {
        return average > other.average;
    }
    bool operator<(const Student& other) const {
        return average < other.average;
    }
    bool operator>=(const Student& other) const {
        return average >= other.average;
    }
    bool operator<=(const Student& other) const {
        return average <= other.average;
    }
    bool operator==(const Student& other) const {
        return average == other.average;
    }
    bool operator!=(const Student& other) const {
        return average != other.average;
    }
    int& operator[](int index) {    // дозволяє змінювати значення
        return grades[index];
    }
    const int& operator[](int index) const {    // тільки для читання
        return grades[index];
    }
    int operator()(int grade) const {
        for (int i = 0; i < size; i++)
        {
            if (grades[i] == grade) {
                return i;
            }
        }
        return -1;
    }

    Student operator+(const Student& other) const {
        Student temp(size);
        for (int i = 0; i < size; i++)
        {
            temp.grades[i] = this->grades[i] + other.grades[i];
        }
        temp.findAverage();
        return temp;
    }

    Student operator-(const Student& other) const {
        Student temp(size);
        for (int i = 0; i < size; i++)
        {
            temp.grades[i] = this->grades[i] - other.grades[i];
        }
        temp.findAverage();
        return temp;
    }

    void print() const {
        cout << "Grades: ";

        for (int i = 0; i < size; i++)
        {
            cout << grades[i] << " ";
        }

        cout << "\n";
        cout << "Size: " << size << "\n";
        cout << "Average: " << average << "\n";
    }

};
ostream& operator<<(ostream& os, const Student& s) {
    for (int i = 0; i < s.getSize(); i++)
    {
        os << s[i] << " ";
    }
    os << "\n";
    return os;
}

istream& operator>>(istream& is, Student& s) {
    for (int i = 0; i < s.getSize(); i++)
    {
        is >> s[i];
    }
    s.findAverage();
    return is;
}
int main()
{
    srand(time(NULL));
    
    const int count = 6;
    Student s[count];

    for (int i = 0; i < count; i++)
    {
        s[i].fillRandom();
        cout << "Student " << i + 1 << ": " << s[i];
    }
    
    // Пошук найкращого та найгіршого студента
    int bestIndex = 0;
    int worstIndex = 0;

    for (int i = 1; i < count; i++)
    {
        if (s[i] > s[bestIndex]) bestIndex = i;
        if (s[i] < s[worstIndex]) worstIndex = i;
    }
    
    cout << "\nBest student: " << bestIndex + 1 << ": " << s[bestIndex];
    cout << "Worst student: " << worstIndex + 1 << ": " << s[worstIndex] << "\n";

    // Для кожного об’єкту вивести місяць з найкращою і найгіршою оцінкою
    for (int i = 0; i < count; i++)
    {
        int bestMonth = s[i].findMaxIndex();
        int worstMonth = s[i].findMinIndex();

        cout << "\nStudent " << i + 1 << ":\nBest month: " << bestMonth + 1 << " Grade: " << s[i][bestMonth] << "\nWorst month: " << worstMonth + 1 << " Grade: " << s[i][worstMonth] << "\n"; 
    }

    // Створити об’єкт, в який записати суму всіх інших об’єктів
    Student sumObject(12);
    for (int i = 0; i < count; i++)
    {
        sumObject = sumObject + s[i];
    }

    cout << "\n\nAn object with the sum of all grades:\n" << sumObject;

    // Створити об’єкт, в який записати різницю найкращого та найгіршого
    Student diffObject = s[bestIndex] - s[worstIndex];
    cout << "\nDifference between best and worst student grades:\n" << diffObject;

    cout << "\n\n";
    return 0;
}