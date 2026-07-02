#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

void encrypt(const char* text, const char* path, int key) {
    FILE* file_w = fopen(path, "w");

    if (!file_w) {
        cout << "Error opening file for writing!!!\n";
        return;
    }

    for (int i = 0; text[i] != '\0'; i++)
    {
        char encrypted_char = text[i] + key;
        fputc(encrypted_char, file_w);
    }

    fclose(file_w);
}

void decrypt(const char* path, int key) {
    FILE* file_r = fopen(path, "r");

    if (!file_r) {
        cout << "Error opening file for reading!!!\n";
        return;
    }

    int j = 0;
    while (!feof(file_r)) {
        cout << fgetc(file_r);
        j++;
    }

    fclose(file_r);
}

int main()
{
    char text[1000000];
    cout << "Enter text to encrypt: ";
    gets_s(text);

    int key = 5;

    char path[] = "secret_data.txt";

    encrypt(text, path, key);

    //decrypt(path, key);

    
    
    cout << "\n\n";
    return 0;
}