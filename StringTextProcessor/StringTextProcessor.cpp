#include <iostream>
#include <string>
#include <cstdlib> // system()
#include <algorithm> // reverse()
using namespace std;

int menu() {
    int choice;

    cout << "0 - EXIT\n";
    cout << "1 - FIND WORD\n";
    cout << "2 - REPLACE WORD\n";
    cout << "3 - DELETE WORD\n";
    cout << "4 - REVERSE TEXT\n";

    cout << "\nEnter choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    string str;

    cout << "Enter string: ";
    getline(cin, str);
    
    int symbols, pos, count;
    int offset; // Змінна, яка рахує кількість видалених символів для правильного виводу в консоль індексів звідки видалили
    string word, new_word;
    do {
        system("cls");
        symbols = str.length();
        cout << "Symbol count: " << symbols;
        cout << "\n" << string(50, '-') << "\n";
        cout << str;
        cout << "\n" << string(50, '-') << "\n\n";

        int choice = menu();

        if (!choice) break;
        
        switch (choice) {
        case 1:
            cout << "Enter word: ";
            cin >> word;
            pos = str.find(word);
            if (pos == -1) {
                cout << "\nNot found!\n";
                system("pause");
                break;
            }
            count = 0;
            cout << "\nPositions:\n";
            while (pos != -1) {
                cout << pos << "\n";
                count++;
                pos = str.find(word, pos + word.length());
            }

            cout << "\nTotal found: " << count << " times\n";
            system("pause");
            break;
        case 2:
            cout << "Enter word to replace: ";
            cin >> word;
            pos = str.find(word);
            if(pos == -1){
                cout << "\nNot found\n";
                system("pause");
                break;
            }
            cout << "Enter new word: ";
            cin >> new_word;

            count = offset = 0;
            cout << "\nPositions:\n";
            while (pos != -1) {
                cout << pos - offset << "\n";
                count++;
                str.replace(pos, word.length(), new_word);
                offset += (int)new_word.length() - (int)word.length();  // Рахуємо різницю в довжині слів. Перетворюємо в (int), бо length() повертає беззнаковий тип size_t
                pos = str.find(word, pos + new_word.length());
            }
            cout << "\nTotal replaced: " << count << " times\n";
            system("pause");
            break;
        case 3:
            cout << "Enter word to delete: ";
            cin >> word;
            pos = str.find(word);
            if (pos == -1) {
                cout << "\nNot found\n";
                system("pause");
                break;
            }
            count = offset = 0;
            cout << "\nPositions:\n";
            while (pos != -1) {
                cout << pos + offset << "\n";
                count++;
                str.erase(pos, word.length());
                offset += word.length();
                pos = str.find(word, pos);
            }
            cout << "\nTotal deleted: " << count << " times\n";
            system("pause");
            break;
        case 4:
            reverse(str.begin(), str.end());
            break;
        }
    } while (true);
    
    cout << "\n\n";
    return 0;
}