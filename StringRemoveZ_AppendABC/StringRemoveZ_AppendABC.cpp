#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;

    cout << "Enter string: ";
    getline(cin, str);  // getline(потік, змінна);

    cout << "Original: " << str;
    
    int pos = str.find("z");
    while (pos != -1) {
        str.erase(pos, 1);
        pos = str.find("z", pos);
    }
    str += "ABC";

    cout << "\nNew: " << str;

    cout << "\n\n";
    return 0;
}