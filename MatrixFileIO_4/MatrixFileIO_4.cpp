#pragma warning(disable: 4996)
#include <iostream>
#include <iomanip>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
#include <cstdio>  // FILE, fopen, fprintf, fscanf
using namespace std;


template <int R, int C>
void set_matrix(int(&matrix)[R][C]) {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            matrix[i][j] = rand() % 101 - 50; //[-50; 50]
}

template <int R, int C>
void print_matrix(int(&matrix)[R][C]) {
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++)
            cout << setw(6) << matrix[i][j];
        cout << "\n";
    }
}

int main()
{
    srand(time(NULL));

    const int rows = 10, cols = 10;
    int matrix[rows][cols];

    set_matrix(matrix);
    print_matrix(matrix);

    char path[] = "text.txt";
    FILE* file = fopen(path, "w");

    if (!file) {
        cout << "Error path!!!\n";
        return -1;
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            fprintf(file, "%6i ", matrix[i][j]); // "%6i " як setw(6)
        fprintf(file, "\n");
    }
            
    fclose(file);

    FILE* file_r = fopen(path, "r");

    if (!file_r) {
        cout << "Error path!!!\n";
        return -1;
    }

    int matrix2[rows][cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fscanf(file_r, "%i", &matrix2[i][j]);

       
    fclose(file_r);

    cout << "\nMatrix from file:\n";
    print_matrix(matrix2);

    cout << "\n\n";
    return 0;
}