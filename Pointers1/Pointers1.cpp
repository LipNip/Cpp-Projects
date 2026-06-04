#include <iostream>
using namespace std;

void set_arr (int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 101 - 50;
    }
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
}

void swapEvenOddElements(int* arr, int size) {
    for (int i = 0; i < size - 1; i+=2) 
    {
        int temp = *(arr + i);  
        *(arr + i) = *(arr + i + 1); 
        *(arr + i + 1) = temp; 
    }
}

int main()
{
    srand(time(NULL));
    
    const int size = 10;
    int arr[size] = {};

    set_arr(arr, size);
    print_arr(arr, size);
    
    swapEvenOddElements(arr, size);
    cout << "\n\n";
    print_arr(arr, size);
    
    cout << "\n\n";
    return 0;
}
