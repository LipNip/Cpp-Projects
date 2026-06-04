#include <iostream>
using namespace std;
int main()
{
    srand(time(NULL));

    int arr[20]{};

    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 101 - 50;
    }
        
    cout << "Original Array: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nEven indices: ";
    for (int i = 0; i < 20; i++) {
        if (i % 2 == 0) {
            cout << arr[i] << " ";
        }
    }

    cout << "\nOdd indices: ";
    for (int i = 0; i < 20; i++) {
        if (i % 2 == 1) {
            cout << arr[i] << " ";
        }
    }
    
    cout << "\n \n";
    return 0;
}