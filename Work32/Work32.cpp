#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    srand(time(NULL));

    const int rows_arr = 100, cols_arr = 100;
    int arr[rows_arr][cols_arr]{};

    int rows, cols;
    cout << "rows: ";
    cin >> rows;
    cout << "cols: ";
    cin >> cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 101 - 50;
        }
    }

    cout << "\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(6) << arr[i][j];
        }
        cout << "\n";
    }

    cout << "\n";
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << setw(6) << arr[i][j];
        }
        cout << "\n";
    }

    cout << "\n \n";
    return 0;
}