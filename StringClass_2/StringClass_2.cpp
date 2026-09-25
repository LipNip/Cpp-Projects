#include <iostream>
#include <cstring> // strlen(), strcpy_s()
#include <stdexcept>
using namespace std;

class String {
    char* str;
    int capacity;
public:
    // Конструктор по замовчуванню, що дозволяє створити стрічку довжиною 80 символів;
    String() {
        capacity = 80;
        str = new char[capacity + 1]; // + 1 для '\0'
        str[0] = '\0';
    }
    // Конструктор, що дозволяє створювати стрічку довільного розміру;
    String(int size) {
        capacity = size;
        str = new char[capacity + 1];
        str[0] = '\0';
    }
    // Конструктор, який створює стрічку і ініціалізує її стрічкою, отриманою від користувача, як параметр;
    String(const char* text) {
        capacity = strlen(text);
        str = new char[capacity + 1];
        strcpy_s(str, capacity + 1, text);
    }
    // Конструктор копіювання;
    String(const String& other) {   
        capacity = other.capacity;
        str = new char[capacity + 1];
        strcpy_s(str, capacity + 1, other.str);
    }
    ~String() {
        delete[] str;
    }
    void setString(const char* text) {
        delete[] str;
        capacity = strlen(text);
        str = new char[capacity + 1];
        strcpy_s(str, capacity + 1, text);
    }
    const char* getString() const {
        return str;
    }
    // Метод для введення стрічки з клавіатури; 
    void input() {
        gets_s(str, capacity + 1);
    }
    // Методи для виведення стрічки на екран; 
    void print() const {
        cout << str << "\n";
    }
    int size() const {
        return strlen(str);
    }
    void insertChar(char symbol, int position) { // для символу
        int len = strlen(str);
        
        if (position < 0 || position > len)
            return;

        char* p = new char[len + 2]; // + 2 бо треба місце для '\0' і символа
        for (int i = 0; i < position; i++)
        {
            p[i] = str[i];
        }
        p[position] = symbol;
        for (int i = position; i < len; i++)
        {
            p[i + 1] = str[i];
        }
        p[len + 1] = '\0';
        delete[] str;
        str = p;
        capacity = len + 1;
    }
    void insertString(const char* text, int position) { // для символу підстрічки
        int len = strlen(str);
        int textLen = strlen(text);

        if (position < 0 || position > len)
            return;

        char* p = new char[len + textLen + 1];
        for (int i = 0; i < position; i++)
        {
            p[i] = str[i];
        }
        for (int i = 0; i < textLen; i++)
        {
            p[position + i] = text[i];
        }
        for (int i = position; i < len; i++)
        {
            p[textLen + i] = str[i];
        }
        p[len + textLen] = '\0';
        delete[] str;
        str = p;
        capacity = len + textLen;
    }
    void deleteChar(char symbol) { // видалення символу
        int len = strlen(str);
        int newLen = 0;
        for (int i = 0; i < len; i++)
        {
            if (str[i] != symbol) {
                newLen++;
            }
        }
        char* p = new char[newLen + 1];
        int j = 0;
        for (int i = 0; i < len; i++)
        {
            if (str[i] != symbol) {
                p[j] = str[i];
                j++;
            }
        }
        p[j] = '\0';

        delete[] str;
        str = p;
        capacity = newLen;
    }
    void deleteString(const char* text) { // видалення підстрічки
        int len = strlen(str);
        int textLen = strlen(text);
        int pos = find(text);

        if (pos == -1) {
            return;
        }

        char* p = new char[len - textLen + 1];
        int j = 0;
        for (int i = 0; i < pos; i++)
        {
            p[j++] = str[i];
        }
        for (int i = pos + textLen; i < len; i++)
        {
            p[j++] = str[i];
        }
        p[j] = '\0';

        delete[] str;
        str = p;
        capacity = j;
    }
    int find(const char* text) const {
        int len = strlen(str);
        int textLen = strlen(text);
        int pos = -1;

        for (int i = 0; i <= len - textLen; i++) {
            bool found = true;
            for (int j = 0; j < textLen; j++) {
                if (str[i + j] != text[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }
        return pos;
    }
    void replaceChar(char oldChar, char newChar) {
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            if (str[i] == oldChar) {
                str[i] = newChar;
            }
        }
    }
    void replaceString(const char* oldText, const char* newText) {
        int pos = find(oldText);

        if (pos == -1)
            return;

        deleteString(oldText);
        insertString(newText, pos);
    }

    bool operator==(const String& other) const {
        int len1 = strlen(str);
        int len2 = strlen(other.str);
        
        if(len1 != len2) return false;

        for (int i = 0; i < len1; i++)
        {
            if (str[i] != other.str[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    bool operator<(const String& other) const {
        return strcmp(str, other.str) < 0;
    }

    bool operator>(const String& other) const {
        return strcmp(str, other.str) > 0;
    }

    String operator+(const String& other) const {
        int newLen = strlen(str) + strlen(other.str);
        String result(newLen);
        strcpy_s(result.str, newLen + 1, str);
        strcat_s(result.str, newLen + 1, other.str);
        return result;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            capacity = other.capacity;
            str = new char[capacity + 1];
            strcpy_s(str, capacity + 1, other.str);
        }
        return *this;
    }

    // Для читання та зміни символу за індексом
    char& operator[](int index) {
        int len = strlen(str);
        if (index < 0 || index >= len) {
            throw out_of_range("Index out of bounds"); // В попередньому завданні я пояснив що це
        }
        return str[index];
    }

    // Тільки для читання, для константних об'єктів
    const char& operator[](int index) const {
        int len = strlen(str);
        if (index < 0 || index >= len) {
            throw out_of_range("Index out of bounds");
        }
        return str[index];
    }
};

int menu() {
    int choice;

    cout << "0 - Exit\n";
    cout << "1 - Insert Char\n";
    cout << "2 - Insert String\n";
    cout << "3 - Delete Char\n";
    cout << "4 - Delete String\n";
    cout << "5 - Replace Char\n";
    cout << "6 - Replace String\n";
    cout << "7 - Find String\n"; 
    cout << "8 - Get Size\n";
    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    String str1;    // 1. Конструктор за замовчуванням
    cout << "Enter first string: ";
    str1.input();

    cout << "First string: ";
    str1.print();

    String str2(100);   // 2. Конструктор довільного розміру

    cout << "\nEnter second string: ";
    str2.input();

    cout << "Second string: ";
    str2.print();

    char text[100];
    cout << "\nEnter third string: ";
    gets_s(text, 100);

    String str3(text);

    cout << "Third string: ";
    str3.print();

    char symbol, oldChar, newChar;
    int position;
    char oldText[100], newText[100];

    do {
        system("cls");
        cout << "\n" << string(50, '-') << "\n";
        str1.print();
        cout << string(50, '-') << "\n";

        int choice = menu();
        if (!choice) break;

        switch (choice) {
        case 1:
            cout << "Enter symbol: ";
            cin >> symbol;
            cout << "Enter position: ";
            cin >> position;
            str1.insertChar(symbol, position);
            break;
        case 2:
            cin.ignore();
            cout << "Enter text: ";
            gets_s(text, 100);
            cout << "Enter position: ";
            cin >> position;
            str1.insertString(text, position);
            break;
        case 3:
            cout << "Enter symbol: ";
            cin >> symbol;
            str1.deleteChar(symbol);
            break;
        case 4:
            cin.ignore();
            cout << "Enter text: ";
            gets_s(text, 100);
            str1.deleteString(text);
            break;
        case 5:
            cout << "Enter old char: ";
            cin >> oldChar;
            cout << "Enter new char: ";
            cin >> newChar;
            str1.replaceChar(oldChar, newChar);
            break;
        case 6:
            cin.ignore();
            cout << "Enter old string: ";
            gets_s(oldText, 100);
            cout << "Enter new string: ";
            gets_s(newText, 100);
            str1.replaceString(oldText, newText);
            break;
        case 7:
            cin.ignore();
            cout << "Enter text to find: ";
            gets_s(text, 100);
            position = str1.find(text);
            if (position != -1)
                cout << "Found at index: " << position << "\n";
            else
                cout << "Not found!\n";
            system("pause");
            break;
        case 8:
            cout << "Current string size: " << str1.size() << "\n";
            system("pause");
            break;
        }
    } while (true);

    cout << "\n\n";
    return 0;
}