#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

void start(char arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = '+';
        }
    }
}void print(char arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << arr[i][j];
        }        cout << '\n';

    }
}

bool checkWin(char arr[3][3], char player)
{
    for (int i = 0; i < 3; i++)
        if (arr[i][0] == player && arr[i][1] == player && arr[i][2] == player)
            return true;

    for (int j = 0; j < 3; j++)
        if (arr[0][j] == player && arr[1][j] == player && arr[2][j] == player)
            return true;

    if (arr[0][0] == player && arr[1][1] == player && arr[2][2] == player)
        return true;

    if (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player)
        return true;

    return false;
}

int main()
{
    srand(time(NULL));
    SetConsoleCP(65001);//1251
    SetConsoleOutputCP(65001);//1251

    const int rows = 3, cols = 3;
    char arr[rows][cols]{};

    int choooice, playAgain;
    do{                             //перший do для playAgain (в кінці завдання потрібно було зробити)
        start(arr, rows, cols);
    do {
        cout << "Гра із комп’ютером (1) або з другим користувачем (2) ";
        cin >> choooice;
        if (choooice != 1 && choooice != 2) {
            cout << "Неправильний номер(1 або 2). Спробуйте ще раз\n\n";
        }
    } while (choooice != 1 && choooice != 2);

    char player = 'X';
    bool gameOver = false;

    if (choooice == 2) {
        do {
            int rows_choiсe, cols_choiсe;
            print(arr, rows, cols);
            cout << "\n" << player << ":";
            do{
            cout << "\n" << "Рядочок(0 - 2): ";
            cin >> rows_choiсe;
            cout << "Стовбець(0 - 2): ";
            cin >> cols_choiсe;

            if (rows_choiсe > 2 || cols_choiсe > 2 || rows_choiсe < 0 || cols_choiсe < 0) {
                cout << "Неправильний номер(0 - 2). Спробуйте ще раз\n";
            }
            else if (arr[rows_choiсe][cols_choiсe] != '+') {
                cout << "Комірка не порожня. Спробуйте ще раз\n";
            }
            else {
                break;
            }
            } while (true);
            arr[rows_choiсe][cols_choiсe] = player;

            if (checkWin(arr, player)) {
                cout << "\n---------------------------\n";
                cout << player << " - Перемога";
                cout << "\n---------------------------";
                gameOver = true;
                break;
            }
            if (player == 'X') {
                player = 'O';
            }
            else if (player == 'O') {
                player = 'X';
            }
        } while (!gameOver);
    }
    else if (choooice == 1) {
        do {
            int rows_choiсe, cols_choiсe;
            print(arr, rows, cols);

            player = 'X';
            cout << "\n" << player << ":";
            do {
                cout << "\n" << "Рядочок(0 - 2): ";
                cin >> rows_choiсe;
                cout << "Стовбець(0 - 2): ";
                cin >> cols_choiсe;

                if (rows_choiсe > 2 || cols_choiсe > 2 || rows_choiсe < 0 || cols_choiсe < 0) {
                    cout << "Неправильний номер(0 - 2). Спробуйте ще раз\n";
                }
                else if (arr[rows_choiсe][cols_choiсe] != '+') {
                    cout << "Комірка не порожня. Спробуйте ще раз\n";
                }
                else {
                    break;
                }
            } while (true);
            arr[rows_choiсe][cols_choiсe] = player;

            if (checkWin(arr, player)) {
                cout << "\n---------------------------\n";
                cout << player << " - Перемога";
                cout << "\n---------------------------";
                gameOver = true;
                break;
            }

            player = 'O';
            int aiRows, aiCols;
            do {
                aiRows = rand() % 3;
                aiCols = rand() % 3;
            } while (arr[aiRows][aiCols] != '+');
                arr[aiRows][aiCols] = player;
              
                if (checkWin(arr, player)) {
                    cout << "\n---------------------------\n";
                    cout << player << " - Перемога";
                    cout << "\n---------------------------";
                    gameOver = true;
                    break;
                }

        } while (!gameOver);
    }
    cout << "1 - Зіграти ще раз?\n0 - Вихід";
    cin >> playAgain;
    }while (playAgain == 1);
    return 0;
}