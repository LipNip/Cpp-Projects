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

    cout << "\nNew Array (All zeros are replaced with ones): ";
    for (int i = 0; i < 20; i++) {
        if (arr[i] == 0) {
            arr[i] = 1;
        }
        cout << arr[i] << " ";
    }

    cout << "\n \n";
    return 0;
}