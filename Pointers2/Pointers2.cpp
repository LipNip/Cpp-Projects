#include <iostream>
#include <iomanip>
using namespace std;

void set_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 99 + 2; // числа від 2 до 100 включно
    }
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << *(arr + i);
    }
}

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int j = 2; j < num; j++)
    {
        if (num % j == 0) {
            return false;
        }
    }
    return true;
}

void printPrimeElements(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        if (isPrime(*(arr + i))) {
            cout << setw(4) << *(arr + i);
        }
    }
}

int sumPrimeElements(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (isPrime(*(arr + i))) {
            sum = sum + *(arr + i);
        }
    }
    return sum;
}

int countPrimeElements(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (isPrime(*(arr + i))) {
            count++;
        }
    }
    return count;
}

double primeElementsPercentage(int* arr, int size) {
    return countPrimeElements(arr, size) * 100.0 / size;
}

int main()
{
    srand(time(NULL));
    
    int size;
    cout << "elements: ";
    cin >> size;
    
    if (size <= 0) {
        cout << "Invalid array size\n\n";
        return 0;
    }

    int* arr = new int[size];
    
    set_arr(arr, size);
    print_arr(arr, size);
    cout << "\n\n" << string(50, '-') << "\n"; //малюємо лінію
    
    cout << "prime elements:";
    printPrimeElements(arr, size);
    cout << "\nprime sum = " << sumPrimeElements(arr, size);
    cout << "\nprime count = " << countPrimeElements(arr, size);
    cout << "\nprime percent = " << primeElementsPercentage(arr, size);

    delete[] arr;
    arr = nullptr;
    
    cout << "\n\n";
    return 0;
}