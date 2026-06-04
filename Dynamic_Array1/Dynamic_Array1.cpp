#include <iostream>
using namespace std;

void set_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 101 - 50;
    }
}

void print_arr(int* arr, int size) {
    cout << "SIZE: " << size << "\n";
    cout << string(50, '-') << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n" << string(50, '-') << "\n";;

}

int* add_end(int* arr, int* size, int num) {
    int* p = new int[*size + 1];

    for (int i = 0; i < *size; i++)
    {
        p[i] = arr[i];
    }
    p[*size] = num;

    delete[] arr;
    arr = nullptr;
    (*size)++;
    return p;
}

int* add_begin(int* arr, int* size, int num) {
    int* p = new int[*size + 1];

    p[0] = num;
    for (int i = 0; i < *size; i++)
    {
        p[i + 1] = arr[i];
    }

    delete[] arr;
    arr = nullptr;
    (*size)++;
    return p;
}

int* add_position(int* arr, int* size, int num, int pos) {
    int* p = new int[*size + 1];

    for (int i = 0; i < pos; i++)
    {
        p[i] = arr[i];
    }

    p[pos] = num;

    for (int i = pos; i < *size; i++)
    {
        p[i + 1] = arr[i]; 
    }

    delete[] arr;
    arr = nullptr;
    (*size)++;
    return p;
}

int* delete_element(int* arr, int* size) {
    int* p = new int[*size - 1];

    for (int i = 0; i < *size - 1; i++)
    {
        p[i] = arr[i];
    }

    delete[] arr;
    arr = nullptr;
    (*size)--; 
    return p;
}


int* delete_begin(int* arr, int* size) {
    int* p = new int[*size - 1];

    for (int i = 1; i < *size; i++)
    {
        p[i - 1] = arr[i];
    }

    delete[] arr;
    arr = nullptr;
    (*size)--; 
    return p;
}

int* delete_position(int* arr, int* size, int pos) {
    int* p = new int[*size - 1];

    for (int i = 0; i < pos; i++)
    {
        p[i] = arr[i];
    }

    for (int i = pos; i < *size; i++)
    {
        p[i - 1] = arr[i]; 
    }

    delete[] arr;
    arr = nullptr;
    (*size)--; 
    return p;
}

int* delete_all(int* arr, int* size) {
    *size = 0;
    delete[] arr;
    arr = nullptr;
    return arr;
}

int* delete_position_count(int* arr, int* size, int pos, int count) {
    int* p = new int[*size - count];

    for (int i = 0; i < pos; i++)
    {
        p[i] = arr[i];
    }

    for (int i = pos + count; i < *size; i++)
    {
        p[i - count] = arr[i]; 
    }

    delete[] arr;
    arr = nullptr;
    (*size) = (*size) - count; 
    return p;
}

int index_found(int* arr, int size, int num) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}


int* delete_found(int* arr, int* size, int num) { 
    int pos = index_found(arr, *size, num);

    if (pos == -1) {
        cout << "Not found!!!";
        return arr;
    }

    int* p = new int[*size - 1];

    for (int i = 0; i < pos; i++)
    {
        p[i] = arr[i];
    }

    for (int i = pos + 1; i < *size; i++)
    {
        p[i - 1] = arr[i];
    }

    delete[] arr;
    arr = nullptr;
    (*size)--;
    return p;
}

int* replace_element(int* arr, int* size, int num, int newValue) { 
    for (int i = 0; i < *size; i++)
    {
        if (arr[i] == num) {
            arr[i] = newValue;
            break; // для першого входження
        }
    }
    return arr;
}

int* replace_element_position(int* arr, int size, int pos, int num) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position!!!";
        return arr;
    }
    arr[pos] = num;
    return arr;
}

int* delete_even_index_elements(int* arr, int* size) {
    int newSize = 0;

    for (int i = 0; i < *size; i++)
    {
        if (i % 2 != 0) {
            newSize++;
        }
    }

    int* p = new int[newSize];

    int j = 0;
    for (int i = 0; i < *size; i++)
    {
        if (i % 2 != 0) {
            p[j++] = arr[i];
        }
    }

    delete[] arr;
    arr = nullptr;
    *size = newSize;
    return p;
}

int* delete_odd_index_elements(int* arr, int* size) {
    int newSize = 0;

    for (int i = 0; i < *size; i++)
    {
        if (i % 2 == 0) {
            newSize++;
        }
    }

    int* p = new int[newSize];

    int j = 0;
    for (int i = 0; i < *size; i++)
    {
        if (i % 2 == 0) {
            p[j++] = arr[i];
        }
    }

    delete[] arr;
    arr = nullptr;
    *size = newSize;
    return p;
}

int* delete_even_index_elements(int* arr, int* size) {
    int newSize = 0;

    for (int i = 0; i < *size; i++)
    {
        if (i % 2 != 0) {
            newSize++;
        }
    }

    int* p = new int[newSize];

    int j = 0;
    for (int i = 0; i < *size; i++)
    {
        if (i % 2 != 0) {
            p[j++] = arr[i];
        }
    }

    delete[] arr;
    arr = nullptr;
    *size = newSize;
    return p;
}

int* delete_odd_elements(int* arr, int* size) {
    int newSize = 0;

    for (int i = 0; i < *size; i++)
    {
        if (arr[i] % 2 == 0) {
            newSize++;
        }
    }

    int* p = new int[newSize];

    int j = 0;
    for (int i = 0; i < *size; i++)
    {
        if (arr[i] % 2 == 0) {
            p[j++] = arr[i];
        }
    }

    delete[] arr;
    arr = nullptr;
    *size = newSize;
    return p;
}


int menu() {
    int choise;
    cout << "0 - EXIT\n";
    cout << "1 - ADD END\n";
    cout << "2 - ADD BEGIN\n";
    cout << "3 - ADD POSITION\n";
    cout << "4 - DELETE ELEMENT\n";
    cout << "5 - DELETE BEGIN\n";
    cout << "6 - DELETE POSITION\n";
    cout << "7 - DELETE ARRAY\n";
    cout << "8 - DELETE POSITION RANGE\n";
    cout << "9 - DELETE FOUND\n";
    cout << "10 - REPLACE ELEMENT\n";
    cout << "11 - REPLACE ELEMENT POSITION\n";
    cout << "12 - DELETE ELEMENTS WITH EVEN INDEXES\n";
    cout << "13 - DELETE ELEMENTS WITH ODD INDEXES\n";
    cout << "14 - DELETE ELEMENTS WITH EVEN ELEMENTS\n";

    cout << "Enter choice: ";
    cin >> choise;

    return choise;
}

int main()
{
    srand(time(NULL));

    int size;
    cout << "Enter size: ";
    cin >> size;

    int* arr = new int[size];
    set_arr(arr, size);

    int num, pos, count, newNum;
    do {
        system("cls");
        print_arr(arr, size);

        int choise = menu();

        if (!choise) break;

        switch (choise) {
        case 1:
            cout << "Enter number: ";
            cin >> num;

            arr = add_end(arr, &size, num);
            break;
        case 2:
            cout << "Enter number: ";
            cin >> num;
            arr = add_begin(arr, &size, num);
            break;
        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter number: ";
            cin >> num;
            arr = add_position(arr, &size, num, pos);
            break;
        case 4:
            arr = delete_element(arr, &size);
            break;
        case 5:
            arr = delete_begin(arr, &size);
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            arr = delete_position(arr, &size, pos);
            break;
        case 7:
            arr = delete_all(arr, &size);
            break;
        case 8:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter count: ";
            cin >> count;
            arr = delete_position_count(arr, &size, pos, count);
            break;
        case 9:
            cout << "Enter num: ";
            cin >> num;
            arr = delete_found(arr, &size, num);
            system("pause");
            break;
        case 10:
            cout << "Enter value to replace: ";
            cin >> num;
            cout << "Enter new value: ";
            cin >> newNum;
            arr = replace_element(arr, &size, num, newNum);
            break;
        case 11:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter num: ";
            cin >> num;
            replace_element_position(arr, size, pos, num);
            break;
        case 12:
            arr = delete_even_index_elements(arr, &size);
            break;
        case 13:
            arr = delete_odd_index_elements(arr, &size);
            break;
        case 14:
            arr = delete_odd_elements(arr, &size);
            break;
        }

    } while (true);

    cout << "\n\n";
    return 0;
}