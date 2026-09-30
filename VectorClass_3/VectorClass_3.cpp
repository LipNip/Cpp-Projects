#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
#include <stdexcept> // throw
#include <cstdio>  // sprintf_s()
#include <cstring> // strcat_s()
#include <string> // string, to_string(), c_str()
using namespace std;

template <typename T>
class Vector {
    T* data;
    int size;
public:
    Vector() {
        data = nullptr;
        size = 0;
    }
    Vector(int size) {
        this->size = size;
        data = new T[size]{};
    }
    Vector(const Vector& other) {
        this->size = other.size;
        this->data = new T[other.size]; // size
        for (int i = 0; i < size; i++)
        {
            this->data[i] = other.data[i];
        }
    }
    ~Vector() {
        delete[] data;
    }
    void set_arr() {
        for (int i = 0; i < size; i++)
        {
            data[i] = (T)(rand() % 101 - 50);
        }
    }
    void print_arr() const {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
    }
    void add_end(T value) {
        T* p = new T[size + 1];
        for (int i = 0; i < size; i++)
        {
            p[i] = data[i];
        }
        p[size] = value;
        delete[] data;
        data = p;
        p = nullptr;
        size++;
    }
    void add_begin(T value) {
        T* p = new T[size + 1];
        p[0] = value;
        for (int i = 0; i < size; i++)
        {
            p[i + 1] = data[i];
        }
        delete[] data;
        data = p;
        p = nullptr;
        size++;
    }
    void add_position(T value, int position) {
        if (position < 0 || position > size) { // Перевіряємо, чи існує така позиція
            cout << "Error: Invalid position!\n";
            system("pause");
            return;
        }
        T* p = new T[size + 1];
        for (int i = 0; i < position; i++)
        {
            p[i] = data[i];
        }
        p[position] = value;
        for (int i = position; i < size; i++)
        {
            p[i + 1] = data[i];
        }
        delete[] data;
        data = p;
        p = nullptr;
        size++;
    }
    void remove_begin() {
        if (size == 0) return; // Якщо масив порожній, нічого не робимо
        if (size == 1) { remove_arr(); return; }
        T* p = new T[size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            p[i] = data[i + 1];
        }
        delete[] data;
        data = p;
        p = nullptr;
        size--;
    }
    void remove_end() {
        if (size == 0) return;
        if (size == 1) { remove_arr(); return; }
        T* p = new T[size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            p[i] = data[i];
        }
        delete[] data;
        data = p;
        p = nullptr;
        size--;
    }
    void remove_position(int position) {
        if (position < 0 || position >= size) { // Тут >= бо не можна видалити елемент за межами
            cout << "Error: Invalid position!\n";
            system("pause");
            return;
        }
        if (size == 1) { remove_arr(); return; }
        T* p = new T[size - 1];
        for (int i = 0; i < position; i++)
        {
            p[i] = data[i];
        }
        for (int i = position; i < size - 1; i++)
        {
            p[i] = data[i + 1];
        }
        delete[] data;
        data = p;
        p = nullptr;
        size--;
    }
    void remove_arr() {
        delete[] data;
        data = nullptr;
        size = 0;
    }
    T return_max() const {
        if (size == 0) {
            cout << "Array is empty!\n";
            system("pause");
            return T();
        }
        T max = data[0];
        for (int i = 0; i < size; i++)
        {
            if (max < data[i]) {
                max = data[i];
            }
        }
        return max;
    }
    T return_min() const {
        if (size == 0) {
            cout << "Array is empty!\n";
            system("pause");
            return T();
        }
        T min = data[0];
        for (int i = 0; i < size; i++)
        {
            if (min > data[i]) {
                min = data[i];
            }
        }
        return min;
    }
    int return_size() const {
        return size;
    }
    T return_byIndex(int index) const {
        if (index < 0 || index >= size) {
            cout << "Error: Invalid index!\n";
            system("pause");
            return T();
        }
        return data[index];
    }
    //Bubble Sort
    void sort_up() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (data[j] > data[j + 1]) {
                    T temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
    void sort_down() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (data[j] < data[j + 1]) {
                    T temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
    void reverse_arr() {
        for (int i = 0; i < size / 2; i++) {
            T temp = data[i];
            data[i] = data[size - 1 - i];
            data[size - 1 - i] = temp;
        }
    }

    bool operator==(const Vector& other) const {
        if (size != other.size) { return false; }
        for (int i = 0; i < size; i++)
        {
            if (data[i] != other.data[i]) { return false; }
        }
        return true;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    Vector operator+(const Vector& other) const {
        Vector result(size + other.size);
        for (int i = 0; i < size; i++)
        {
            result.data[i] = data[i];
        }
        for (int i = 0; i < other.size; i++)
        {
            result.data[size + i] = other.data[i];
        }
        return result;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            if (size > 0) {
                data = new T[size];
                for (int i = 0; i < size; i++)
                {
                    data[i] = other.data[i];
                }
            }
            else {
                data = nullptr;
            }
        }
        return *this;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void operator()(T value) {
        for (int i = 0; i < size; i++)
        {
            data[i] += value;
        }
    }

    operator T() const {
        T sum = T();
        for (int i = 0; i < size; i++)
        {
            sum += data[i];
        }
        return sum;
    }

    operator char* () const {
        if (size == 0) {
            char* emptyStr = new char[1];
            emptyStr[0] = '\0';
            return emptyStr;
        }

        /*      Старий код, тільки для int
        int bufferSize = size * 12 + 1;     // Одне ціле число може займати до 11 символів (наприклад, -1234567890) + 1 пробіл
        char* strResult = new char[bufferSize];
        strResult[0] = '\0';

        char temp[20];
        for (int i = 0; i < size; i++)
        {
            sprintf_s(temp, "%d ", data[i]);    // Перетворюємо число на текст
            strcat_s(strResult, bufferSize, temp);  // Об'єднання двох стрічок
        }
        */

        string tempStr = "";
        for (int i = 0; i < size; i++)
        {
            tempStr += to_string(data[i]) + " ";
        }

        char* strResult = new char[tempStr.length() + 1];
        strcpy_s(strResult, tempStr.length() + 1, tempStr.c_str()); // c_str() з класу string, переводить з string до const char*

        return strResult;
    }
};

int menu() {
    int choice;

    cout << "0 - EXIT\n";
    cout << "1 - ADD END\n";
    cout << "2 - ADD BEGIN\n";
    cout << "3 - ADD POSITION\n";
    cout << "4 - REMOVE BEGIN\n";
    cout << "5 - REMOVE END\n";
    cout << "6 - REMOVE POSITION\n";
    cout << "7 - REMOVE ARR\n";
    cout << "8 - RETURN MAX\n";
    cout << "9 - RETURN MIN\n";
    cout << "10 - RETURN SIZE\n";
    cout << "11 - RETURN INDEX\n";
    cout << "12 - SORT UP\n";
    cout << "13 - SORT DOWN\n";
    cout << "14 - REVERSE ARR\n";

    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    srand(time(NULL));
    
    Vector<int> testV(5);
    testV.set_arr();
    testV.print_arr();
    cout << "\n";

    testV(100);
    testV.print_arr();

    int sum = testV;
    cout << "Sum of elements: " << sum << "\n";
    char* strOutput = testV;
    cout << "Vector as char*: " << strOutput << "\n";
    delete[] strOutput;

    cout << "--------------------------------------------------------\n\n\n";

    Vector<int> v(10);
    v.set_arr();
    v.print_arr();
    Vector<int> v2 = v;
    Vector<int> v3 = v + v2;
    cout << "\nv == v2: " << (v == v2 ? "True" : "False") << "\n";
    v3.print_arr();
    cout << "\nElement v[0]: " << v[0] << "\n\n";;
    system("pause");

    int element, position, index;

    do {
        system("cls");
        cout << "\n" << string(50, '-') << "\n";
        v.print_arr();
        cout << "\n" << string(50, '-') << "\n";

        int choice = menu();

        if (!choice) break;

        switch (choice) {
        case 1:
            cout << "Enter element to add: ";
            cin >> element;
            v.add_end(element);
            break;
        case 2:
            cout << "Enter element to add: ";
            cin >> element;
            v.add_begin(element);
            break;
        case 3:
            cout << "Enter element to add: ";
            cin >> element;
            cout << "Enter position: ";
            cin >> position;
            v.add_position(element, position);
            break;
        case 4:
            v.remove_begin();
            break;
        case 5:
            v.remove_end();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> position;
            v.remove_position(position);
            break;
        case 7:
            v.remove_arr();
            break;
        case 8:
            cout << "Max element: " << v.return_max() << "\n";
            system("pause");
            break;
        case 9:
            cout << "Min element: " << v.return_min() << "\n";
            system("pause");
            break;
        case 10:
            cout << "Size arr: " << v.return_size() << "\n";
            system("pause");
            break;
        case 11:
            cout << "Enter index: ";
            cin >> index;
            cout << "Element of index[" << index << "]: " << v.return_byIndex(index) << "\n";
            system("pause");
            break;
        case 12:
            v.sort_up();
            break;
        case 13:
            v.sort_down();
            break;
        case 14:
            v.reverse_arr();
            break;
        }
    } while (true);

    cout << "\n\n";
    return 0;
}