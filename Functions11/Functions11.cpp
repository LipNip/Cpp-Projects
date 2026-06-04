#include <iostream>
#include <iomanip>
using namespace std;

void set(int arr[][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 101 - 50;
        }
    }
}void print(int arr[][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << arr[i][j];
        }        cout << '\n';

    }
}

int not_zero(int arr[][5], int rows, int cols) {
    int not_zero = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] != 0)
                not_zero++;
        }
    }
    return not_zero;
}

int zero_elements(int arr[][5], int rows, int cols) {
    int zero_elements = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 0)
                zero_elements++;
        }
    }
    return zero_elements;
}

int positive_elements(int arr[][5], int rows, int cols) {
    int positive_elements = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > 0)
                positive_elements++;
        }
    }
    return positive_elements;
}

long long int product_of_positives(int arr[][5], int rows, int cols) {
    long long int product = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > 0) {
                product = product * arr[i][j];
            }
        }
    }
    return product;
}

long long int product_of_negative(int arr[][5], int rows, int cols) {
    long long int product = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < 0) {
                product = product * arr[i][j];
            }
        }
    }
    return product;
}


int count_remainder_1_mod_6(int arr[][5], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] % 6 == 1)
                count++;
        }
    }
    return count;
}

int min_in_arr(int arr[][5], int rows, int cols) {
    int min = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int max_in_arr(int arr[][5], int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int the_sum_of_the_negative(int arr[][5], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < 0) {
                sum = sum + arr[i][j];
            }
        }
    }
    return sum;
}

double formula_1(double x) {
    double y = sqrt(pow(x, 2) + 5 * x + 8);
    return y;
}

double formula_2(double x) {
    double y = (3 * pow(x, 2) - 4) / (x + 1);
    return y;
}

double formula_3(double x) {
    double y = x - sqrt(x + 2);
    return y;
}

double formula_5(double x) {
    double y = pow(x, 3) + 4 * pow(x, 2) + x - 2;
    return y;
}

double formula_9(double x) {
    double y = sqrt(x + 2) - sqrt(x + 3);
    return y;
}

double formula_12(double x) {
    double y = sqrt(x) - sqrt(x + 1);
    return y;
}

int main()
{
    srand(time(NULL));

    const int rows = 5, cols = 5;
    int arr[rows][cols]{};
    set(arr, rows, cols);
    print(arr, rows, cols);
    cout << "\n\nNumber of non-zero elements: " << not_zero(arr, rows, cols);
    cout << "\nNumber of elements that are zero: " << zero_elements(arr, rows, cols);
    cout << "\nThe number of positive elements: " << positive_elements(arr, rows, cols);
    cout << "\nThe product of all positive elements: " << product_of_positives(arr, rows, cols);
    cout << "\nThe product of all negative elements: " << product_of_negative(arr, rows, cols);
    cout << "\nThe number of elements that when divided by 6 give a remainder of 1: " << count_remainder_1_mod_6(arr, rows, cols);
    cout << "\nMinimal element: " << min_in_arr(arr, rows, cols);
    cout << "\nMaximum element: " << max_in_arr(arr, rows, cols);
    cout << "\nSum of all negative elements: " << the_sum_of_the_negative(arr, rows, cols);

    cout << "\n\n----------------Formulas----------------\n";
    double x;
    cout << "Enter a number: ";
    cin >> x;

    cout << "Formula 1: " << formula_1(x);
    cout << "\nFormula 2: " << formula_2(x);
    cout << "\nFormula 3: " << formula_3(x);
    cout << "\nFormula 5: " << formula_5(x);
    cout << "\nFormula 9: " << formula_9(x);
    cout << "\nFormula 12: " << formula_12(x);
    cout << "\n\n";
    return 0;
}