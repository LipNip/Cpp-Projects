#include <iostream>
#include <iomanip> 
#include <ctime> // для time(NULL)
#include <cstdlib> // для rand(), srand(), system()
using namespace std;

//1.	Створює двовимірний динамічний масив(прямокутну матрицю).
void create(int**& arr, int rows, int cols) {
    arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
}

//2.	Заповнює масив випадковими числами.
void set(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 101 - 50;
        }
    }
}

//3.	Виводить масив на екран.
void print(int** arr, int rows, int cols) {
    cout << "ROWS: " << rows << "\n";
    cout << "COLS: " << cols << "\n";
    cout << string(50, '-') << "\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << arr[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    cout << string(50, '-') << "\n";
}

//4.	Добавляє рядок в кінець масиву.
void add_row_end(int**& arr, int& rows, int cols) {
    int** p = new int* [rows + 1];

    for (int i = 0; i < rows; i++)
    {
        p[i] = arr[i];
    }
    p[rows] = new int[cols];

    for (int i = 0; i < cols; i++)
    {
        p[rows][i] = rand() % 101 - 50;
    }
    delete[] arr;
    arr = p;
    p = nullptr;
    rows++;
}

//5.	Добавляє рядок напочаток масиву.
void add_row_begin(int**& arr, int& rows, int cols) {
    int** p = new int* [rows + 1];
    p[0] = new int[cols];

    for (int i = 0; i < cols; i++)
    {
        p[0][i] = rand() % 101 - 50;
    }

    for (int i = 0; i < rows; i++)
    {
        p[i + 1] = arr[i];
    }

    delete[] arr;
    arr = p;
    p = nullptr;
    rows++;
}

//6.	Добавляє рядок у вказану позицію.
void add_row_pos(int**& arr, int& rows, int cols, int pos) {
    int** p = new int* [rows + 1];

    for (int i = 0; i < pos; i++)
    {
        p[i] = arr[i];
    }

    p[pos] = new int[cols];

    for (int j = 0; j < cols; j++)
    {
        p[pos][j] = rand() % 101 - 50;
    }

    for (int i = pos; i < rows; i++)
    {
        p[i + 1] = arr[i];
    }

    delete[] arr;
    arr = p;
    p = nullptr;
    rows++;
}

//7.	Добавляє декілька рядків починаючи зі вказаної позиції.
void add_row_block_pos(int**& arr, int& rows, int cols, int pos, int count) {
    for (int i = 0; i < count; i++)
    {
        add_row_pos(arr, rows, cols, pos);
    }
}

//8.	Видаляє рядок зкінця масиву.
void remove_end(int**& arr, int& rows, int cols) {
    delete[] arr[rows - 1];

    int** p = new int* [rows - 1];

    for (int i = 0; i < rows - 1; i++)
    {
        p[i] = arr[i];
    }

    delete[] arr;
    arr = p;
    p = nullptr;
    rows--;
}

//9.	Видаляє рядок з початку масиву.
void remove_begin(int**& arr, int& rows, int cols) {
    delete[] arr[0];
    int** p = new int* [rows - 1];
    for (int i = 0; i < rows - 1; i++)
    {
        p[i] = arr[i + 1];
    }
    delete[] arr;
    arr = p;
    p = nullptr;
    rows--;
}

//10.	Видаляє двовимірний масив.
void remove(int**& arr, int& rows, int& cols) {
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];

    }
    delete[] arr;
    arr = nullptr;
    rows = 0; // Обнуляємо розміри
    cols = 0;
}

//11.	Видаляє рядок зі вказаної позиції.
void remove_row_pos(int**& arr, int& rows, int cols, int pos) {
    delete[] arr[pos];
    int** p = new int* [rows - 1];
    for (int i = 0; i < pos; i++)
    {
        p[i] = arr[i];
    }
    for (int i = pos; i < rows - 1; i++)
    {
        p[i] = arr[i + 1];
    }
    delete[] arr;
    arr = p;
    p = nullptr;
    rows--;
}

//12.	Видаляє блок рядків починаючи зі вказаної позиції.
void remove_row_block_pos(int**& arr, int& rows, int cols, int pos, int count) {
    for (int i = 0; i < count; i++)
    {
        remove_row_pos(arr, rows, cols, pos);
    }
}

void add_end(int*& arr, int& size, int num) {
    int* p = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        p[i] = arr[i];
    }

    p[size] = num;

    delete[] arr;
    arr = nullptr;

    arr = p;
}

//13.	Добавляє стовпець в кінець масиву.
void add_col_end(int**& arr, int rows, int& cols) {
    for (int i = 0; i < rows; i++)
    {
        add_end(arr[i], cols, rand() % 101 - 50);

    }
    cols++;
}

void add_begin(int*& arr, int& size, int num) {
    int* p = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        p[i + 1] = arr[i];
    }

    *p = num;

    delete[] arr;
    arr = nullptr;

    arr = p;
}

//14.	Добавляє стовпець напочаток масиву.
void add_col_begin(int**& arr, int rows, int& cols) {
    for (int i = 0; i < rows; i++)
    {
        add_begin(arr[i], cols, rand() % 101 - 50);

    }
    cols++;
}

void add_position(int*& arr, int& size, int pos, int num) {
    int* p = new int[size + 1];

    for (int i = 0; i < pos; i++)
    {
        p[i] = arr[i];
    }

    p[pos] = num;

    for (int i = pos + 1; i < size + 1; i++)
    {
        p[i] = arr[i - 1];
    }

    delete[] arr;
    arr = nullptr;

    arr = p;
}

//15.	Добавляє стовпець у вказану позицію.
void add_col_position(int**& arr, int rows, int& cols, int pos) {
    for (int i = 0; i < rows; i++)
    {
        add_position(arr[i], cols, pos, rand() % 101 - 50);
    }
    cols++;
}

//16.	Добавляє декілька стовпіців починаючи зі вказаної позиції.
void add_col_position_count(int**& arr, int rows, int& cols, int pos, int count) {

    for (int i = 0; i < count; i++)
    {
        add_col_position(arr, rows, cols, pos);
    }
}

void delete_end(int*& arr, int& size) {
    int* p = new int[size - 1];

    for (int i = 0; i < size - 1; i++)
    {
        p[i] = arr[i];
    }

    delete[] arr;
    arr = nullptr;

    arr = p;
}

//17.	Видаляє стовпець зкінця масиву.
void delete_col_end(int**& arr, int rows, int& cols) {
    for (int i = 0; i < rows; i++)
    {
        delete_end(arr[i], cols);
    }
    cols--;
}

void delete_begin(int*& arr, int& size) {
    int* p = new int[size - 1];

    for (int i = 1; i < size; i++)
    {
        p[i - 1] = arr[i];
    }

    delete[] arr;
    arr = nullptr;

    arr = p;
}

//18.	Видаляє стовпець з початку масиву.
void delete_col_begin(int**& arr, int rows, int& cols) {
    for (int i = 0; i < rows; i++)
    {
        delete_begin(arr[i], cols);
    }
    cols--;
}

void delete_position(int*& arr, int size, int pos) {
    int* p = new int[size - 1];
    for (int i = 0; i < pos; i++)
    {
        p[i] = arr[i];
    }

    for (int i = pos; i < size - 1; i++)
    {
        p[i] = arr[i + 1];
    }

    delete[] arr;
    arr = nullptr;

    arr = p;

}

//19.	Видаляє стовпець зі вказаної позиції.
void delete_col_position(int**& arr, int rows, int& cols, int pos) {
    for (int i = 0; i < rows; i++)
    {
        delete_position(arr[i], cols, pos);
    }
    cols--;
}

//20.	Видаляє блок стовпців починаючи зі вказаної позиції.
void delete_col_block_pos(int** arr, int rows, int& cols, int pos, int count) {
    for (int i = 0; i < count; i++)
    {
        delete_col_position(arr, rows, cols, pos);
    }
}

//21.	Виводить максимальний елемент кожного рядка.
void max_element_rows(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++)
    {
        int max = arr[i][0];
        for (int j = 1; j < cols; j++)
        {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
        cout << "Max in row " << i << " = " << max << "\n";
    }
}

//22.	Виводить мінімальний елемент кожного рядка.
void min_element_rows(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++)
    {
        int min = arr[i][0];
        for (int j = 1; j < cols; j++)
        {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
        cout << "Min in row " << i << " = " << min << "\n";
    }
}

//23.	Виводить максимальний елемент цілого масиву.
void max_element_arr(int** arr, int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    cout << "Max in arr = " << max << "\n";
}

//24.	Виводить мінімальний елемент цілого масиву.
void min_element_arr(int** arr, int rows, int cols) {
    int min = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    cout << "Min in arr = " << min << "\n";
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//25.	Сортує рядок по вказаній позиції по зростанню.
void sort_row_pos_asc(int** arr, int& rows, int cols, int pos) {
    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < cols - i - 1; j++) {
            if (arr[pos][j] > arr[pos][j + 1]) {
                int temp = arr[pos][j];
                arr[pos][j] = arr[pos][j + 1];
                arr[pos][j + 1] = temp;
            }
        }
    }
}

//26.	Сортує рядок по вказаній позиції по спаданню.
void sort_row_pos_desc(int** arr, int& rows, int cols, int pos) {
    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < cols - i - 1; j++) {
            if (arr[pos][j] < arr[pos][j + 1]) {
                int temp = arr[pos][j];
                arr[pos][j] = arr[pos][j + 1];
                arr[pos][j + 1] = temp;
            }
        }
    }
}

//27.	Сортує кожен рядок масиву по зростанню.
void sort_row_asc(int** arr, int& rows, int cols) {
    for (int r = 0; r < rows; r++){
        for (int i = 0; i < cols - 1; i++) {
            for (int j = 0; j < cols - i - 1; j++) {
                if (arr[r][j] > arr[r][j + 1]) {
                    int temp = arr[r][j];
                    arr[r][j] = arr[r][j + 1];
                    arr[r][j + 1] = temp;
                }
            }
        }
    }
}

//28.	Сортує кожен рядок масиву по спаданню.
void sort_row_desc(int** arr, int& rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int i = 0; i < cols - 1; i++) {
            for (int j = 0; j < cols - i - 1; j++) {
                if (arr[r][j] < arr[r][j + 1]) {
                    int temp = arr[r][j];
                    arr[r][j] = arr[r][j + 1];
                    arr[r][j + 1] = temp;
                }
            }
        }
    }
}

//29.	Перевертає кожен рядок задом наперед.
void reverse_rows(int** arr, int& rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int i = 0; i < cols / 2; i++) {
            int temp = arr[r][i];
            arr[r][i] = arr[r][cols - i - 1];
            arr[r][cols - i - 1] = temp;
        }
    }
}

//30.	Перевертає кожен стовпець задом наперед.
void reverse_columns(int** arr, int rows, int& cols) {
    for (int c = 0; c < cols; c++) {
        for (int i = 0; i < rows / 2; i++) {
            int temp = arr[i][c];
            arr[i][c] = arr[rows - i - 1][c];
            arr[rows - i - 1][c] = temp;
        }
    }
}

//31.	Розширює масив на вказану кількість рядків і стовпців.
void resize_matrix(int**& arr, int& rows, int& cols, int add_rows, int add_cols) {
    int new_rows = rows + add_rows;
    int new_cols = cols + add_cols;

    int** p = new int* [new_rows];

    for (int i = 0; i < new_rows; i++)
    {
        p[i] = new int[new_cols];
    }

    for (int i = 0; i < new_rows; i++)
    {
        for (int j = 0; j < new_cols; j++)
        {
            if (i < rows && j < cols) {
                p[i][j] = arr[i][j];
            }
            else {
                p[i][j] = rand() % 101 - 50;
            }
        }
    }

    remove(arr, rows, cols);

    arr = p;
    rows = new_rows;
    cols = new_cols;
}

//32.	Транспонує матрицю.
void transpose_matrix(int**& arr, int& rows, int& cols) {
    int new_rows = cols;
    int new_cols = rows;

    int** p = new int* [new_rows];

    for (int i = 0; i < new_rows; i++)
    {
        p[i] = new int[new_cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            p[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    arr = p;
    rows = new_rows;
    cols = new_cols;
}

//void sort_row_pos(int** arr, int rows, int cols, int pos) {
//    bubbleSort
//}

//int* max_element_row(int*& arr, int rows, int cols) {
//    for (int i = 0; i < rows; i++)
//    {
//        int max = arr[i];
//        for (int j = 0; j < cols; j++)
//        {
//            if (max < arr[j]) {
//                max = arr[j]
//            }
//        }
//    }
//    return max;
//}

int* delete_all(int* arr, int* size) {
    *size = 0;
    delete[] arr;
    arr = nullptr;
    return arr;
}

////// /////////////////////////////
//void delete_block(int*& arr, int* size, int pos, int count) {
//    for (int i = 0; i < count; i++)
//    {
//        arr = delete_position(arr, size, pos);
//    }
//}

//void delete_col_block(int**& arr, int rows, int& cols, int pos, int count) {
//    for (int i = 0; i < rows; i++)
//    {
//        delete_block(arr[i], &cols, pos, count);
//    }
//}

int find_position(int* arr, int size, int num) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}

//int* delete_search_number(int* arr, int* size, int num) {
//    int pos = find_position(arr, *size, num);
//    if (pos != -1)
//        return delete_position(arr, size, pos);
//    cout << "Number Not FOUND!!!!\n";
//    return arr;
//}

int menu() {
    int choice;
    cout << "0 - EXIT\n";
    cout << "1 - ADD ROW END\n";
    cout << "2 - ADD ROW BEGIN\n";
    cout << "3 - ADD ROW POSITION\n";
    cout << "4 - ADD ROW BLOCK POSITION\n";
    cout << "5 - DELETE ROW END\n";
    cout << "6 - DELETE ROW BEGIN\n";
    cout << "7 - DELETE ARRAY\n";
    cout << "8 - DELETE ROW POSITION\n";
    cout << "9 - DELETE ROW BLOCK POSITION\n";
    cout << "10 - ADD COL END\n";
    cout << "11 - ADD COL BEGIN\n";
    cout << "12 - ADD COL POSITION\n";
    cout << "13 - ADD COL BLOCK POSITION\n";
    cout << "14 - DELETE COL END\n";
    cout << "15 - DELETE COL BEGIN\n";
    cout << "16 - DELETE COL POSITION\n";
    cout << "17 - DELETE COL BLOCK POSITION\n";
    cout << "18 - MAX ELEMENT ROW\n";
    cout << "19 - MIN ELEMENT ROW\n";
    cout << "20 - MAX ELEMENT ARR\n";
    cout << "21 - MIN ELEMENT ARR\n";
    cout << "22 - SORT ROW POSITION ASC\n";
    cout << "23 - SORT ROW POSITION DESC\n";
    cout << "24 - SORT ALL ROWS ASC\n";
    cout << "25 - SORT ALL ROWS DESC\n";
    cout << "26 - REVERSE ROWS\n";
    cout << "27 - REVERSE COLUMNS\n";
    cout << "28 - RESIZE MATRIX\n";
    cout << "29 - TRANSPOSE MATRIX\n";
    
    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    srand(time(NULL));

    int rows = 5, cols = 4;
    int** arr = nullptr;

    create(arr, rows, cols);
    set(arr, rows, cols);

    /*print(arr, rows, cols);
    add_row_end(arr, rows, cols);
    print(arr, rows, cols);
    remove(arr, rows);*/

    int pos, count, size, num, add_rows, add_cols;

    do {
        system("cls");
        print(arr, rows, cols);

        int choice = menu();

        if (!choice) break;

        switch (choice) {
        case 1:
            add_row_end(arr, rows, cols);
            break;
        case 2:
            add_row_begin(arr, rows, cols);
            break;
        case 3:
            cout << "Enter position: ";
            cin >> pos;
            add_row_pos(arr, rows, cols, pos);
            break;
        case 4:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter count: ";
            cin >> count;
            add_row_block_pos(arr, rows, cols, pos, count);
            break;
        case 5:
            remove_end(arr, rows, cols);
            break;
        case 6:
            remove_begin(arr, rows, cols);
            break;
        case 7:
            remove(arr, rows, cols);
            break;
        case 8:
            cout << "Enter position: ";
            cin >> pos;
            remove_row_pos(arr, rows, cols, pos);
            break;
        case 9:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter count: ";
            cin >> count;
            remove_row_block_pos(arr, rows, cols, pos, count);
            break;
        case 10:
            add_col_end(arr, rows, cols);
            break;
        case 11:
            add_col_begin(arr, rows, cols);
            break;
        case 12:
            cout << "Enter pos: ";
            cin >> pos;
            add_col_position(arr, rows, cols, pos);
            break;
        case 13:
            cout << "Enter pos: ";
            cin >> pos;
            cout << "Enter count: ";
            cin >> count;
            add_col_position_count(arr, rows, cols, pos, count);
            break;
        case 14:
            delete_col_end(arr, rows, cols);
            break;
        case 15:
            delete_col_begin(arr, rows, cols);
            break;
        case 16:
            cout << "Enter pos: ";
            cin >> pos;
            delete_col_position(arr, rows, cols, pos);
            break;
        case 17:
            cout << "Enter pos: ";
            cin >> pos;
            cout << "Enter count: ";
            cin >> count;
            delete_col_block_pos(arr, rows, cols, pos, count);
            break;
        case 18:
            max_element_rows(arr, rows, cols);
            system("pause");
            break;
        case 19:
            min_element_rows(arr, rows, cols);
            system("pause");
            break;
        case 20:
            max_element_arr(arr, rows, cols);
            system("pause");
            break;
        case 21:
            min_element_arr(arr, rows, cols);
            system("pause");
            break;
        case 22:
            cout << "Enter pos: ";
            cin >> pos;
            sort_row_pos_asc(arr, rows, cols, pos);
            break;
        case 23:
            cout << "Enter pos: ";
            cin >> pos;
            sort_row_pos_desc(arr, rows, cols, pos);
            break;
        case 24:
            sort_row_asc(arr, rows, cols);
            break;
        case 25:
            sort_row_desc(arr, rows, cols);
            break;
        case 26:
            reverse_rows(arr, rows, cols);
            break;
        case 27:
            reverse_columns(arr, rows, cols);
            break;
        case 28:
            cout << "Enter rows to add: ";
            cin >> add_rows;
            cout << "Enter cols to add: ";
            cin >> add_cols;
            resize_matrix(arr, rows, cols, add_rows, add_cols);
            break;
        case 29:
            transpose_matrix(arr, rows, cols);
            break;
        }
    } while (true);

    remove(arr, rows, cols);
    cout << "\n\n";
    return 0;
}