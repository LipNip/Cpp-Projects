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
    
    cout << "\nmass:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(6) << arr[i][j];
        }
        cout << "\n";
    }
    

    for (int i = 0; i < rows; i++)
    {
        int max = arr[i][0], min = arr[i][0];
        int index_i_max = i, index_j_max = 0;
        int index_i_min = i, index_j_min = 0;

        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > max) {
                max = arr[i][j];
                index_i_max = i;
                index_j_max = j;
            }

            if (arr[i][j] < min) {
                min = arr[i][j];
                index_i_min = i;
                index_j_min = j;
            }

        }
        cout << "\nmax of " << i << " row: " << setw(6) << max << setw(12) << "index: " << setw(6) << "[" << index_i_max << "] [" << index_j_max << "]";
        cout << "\nmin of " << i << " row: " << setw(6) << min << setw(12) << "index: " << setw(6) << "[" << index_i_min << "] [" << index_j_min << "]";
    }
    
    cout << "\n \n";
    return 0;
}