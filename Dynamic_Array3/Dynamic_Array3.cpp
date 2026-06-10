#include <iostream>
#include <iomanip>
using namespace std;

void set_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 101 - 50;
    }
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << arr[i];
    }
}

bool isInArray(int* arr, int size, int value) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int findCommonElements(int* arr_A, int size_A, int* arr_B, int size_B, int* arr_C) {
    int size_C = 0;
    for (int i = 0; i < size_A; i++)
    {
        bool foundInB = false;
        for (int j = 0; j < size_B; j++)
        {
            if (arr_A[i] == arr_B[j]) {
                foundInB = true;
                break;
            }
        }
        if (foundInB && !isInArray(arr_C, size_C, arr_A[i])) {
            arr_C[size_C] = arr_A[i];
            size_C++;
        }
    }
    return size_C;
}

int main()
{
    srand(time(NULL));
    
    int size_A;
    cout << "Enter size(A): ";
    cin >> size_A;
    int* arr_A = new int[size_A];
    set_arr(arr_A, size_A);

    int size_B;
    cout << "Enter size(B): ";
    cin >> size_B;
    int* arr_B = new int[size_B];
    set_arr(arr_B, size_B);

    cout << "\nArr_A (Size: " << size_A << ")\n";
    print_arr(arr_A, size_A);

    cout << "\nArr_B (Size: " << size_B << ")\n";
    print_arr(arr_B, size_B);

    int max_size_C;
    if (size_A < size_B)
        max_size_C = size_A;
    else
        max_size_C = size_B;

    int* arr_C = new int[max_size_C];
    int size_C = findCommonElements(arr_A, size_A, arr_B, size_B, arr_C);

    cout << "\nArr_C (Size: " << size_C << ")\n";
    print_arr(arr_C, size_C);
    
    delete[] arr_A;
    delete[] arr_B;
    delete[] arr_C;
    cout << "\n\n";
    return 0;
}