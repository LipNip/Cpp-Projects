#include <iostream>
#include <cstdlib> // для rand(), srand(), system()
using namespace std;

void insertCharacter(char str[], char symbol, int position) {
    int len = strlen(str);
    for (int i = len; i >= position; i--)
    {
        str[i + 1] = str[i];
    }
    str[position] = symbol;
}

void countCharacterTypes(char str[]) {
    int letters = 0;
    int numbers = 0;
    int other_symbols = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i])) {
            letters++;
        }
        else if (isdigit(str[i])) {
            numbers++;
        }
        else {
            other_symbols++;
        }
    }

    cout << "\n Letters: " << letters;
    cout << "\n Numbers: " << numbers;
    cout << "\n Other symbols: " << other_symbols << "\n";
}

void removeDigits(char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i])) {
            for (int j = i; str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
            i--; //щоб перевірити той самий індекс ще раз (раптом там була ще одна цифра)
        }
    }
}

int extractNumberFromString(char str[]) {
    char digits[200];

    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i])) {
            digits[j] = str[i];
            j++;
        }
    }

    digits[j] = '\0'; //закриваємо масив

    int num = atoi(digits);
    return num;
}

int menu() {
    int choice;
    
    cout << "0 - Exit\n";
    cout << "1 - Insert character\n";
    cout << "2 - Count character types\n";
    cout << "3 - Remove digits\n";
    cout << "4 - Extract number from string\n";

    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    char str[100];

    cout << "Enter string: ";
    gets_s(str);
  
    char symbol;
    int position;
    int num;

    do {
        system("cls");
        cout << "\n" << string(50, '-') << "\n";
        cout << str;
        cout << "\n" << string(50, '-') << "\n";

        int choice = menu();

        if (!choice) break;

        switch (choice) {
        case 1:
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter symbol: ";
            cin >> symbol;
            insertCharacter(str, symbol, position);
            break;
        case 2:
            countCharacterTypes(str);
            system("pause");
            break;
        case 3:
            removeDigits(str);
            break;
        case 4:
            num = extractNumberFromString(str);
            cout << num << "\n";
            system("pause");
            break;
        }
    } while (true);
    
    cout << "\n\n";
    return 0;
}