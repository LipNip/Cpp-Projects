#include <iostream>
using namespace std;
int main()
{
	srand(time(NULL));

    int arr[20]{};

    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 101 - 50;
    }

    cout << "Array: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }

    int num;
    cout << "\nEnter a number: ";
    cin >> num;


    for (int i = 0; i < 20; i++) {
        if (num == arr[i]) {
            cout << "The number " << num << " is in the array, index [" << i << "]\n\n";
            return 0;
        }
    }
    cout << "The number " << num << " is not in the array";


	cout << "\n \n";
	return 0;
}