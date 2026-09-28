#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int menu() {
    int choice;

    cout << "0 - EXIT\n";
    cout << "1 - FIND WORD\n";
    cout << "2 - \n";
    cout << "3 - \n";
    cout << "4 - REVERSE TEXT\n";
    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    string str;

    cout << "Enter string: ";
    getline(cin, str);
    
    int symbols, pos, count;
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
            for (int i = 0; i < symbols; i++)
            {
                while (pos != -1) {
                    cout << pos << "\n";
                    count++;
                    pos = str.find(word, pos + word.length());
                }
            }
            cout << "\nTotal found: " << count << " times\n";
            system("pause");
            break;
        case 2:
            cout << "Enter word to replace: ";
            cin >> word;
            cout << "Enter new word: ";
            cin >> new_word;
            break;
        case 3:
            break;
        case 4:
            reverse(str.begin(), str.end());    ///////
            break;
        }
    } while (true);
    
    
    
    cout << "\n\n";
    return 0;
}