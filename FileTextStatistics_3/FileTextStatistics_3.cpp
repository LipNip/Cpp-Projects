#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>    // FILE, fopen, fgetc, fputc
#include <cctype>    // isdigit(), isalpha()
using namespace std;

int main()
{
    char path[] = "text.txt";
    FILE* file = fopen(path, "r");
    char result[100000];

    if (!file) {
        cout << "Error path!!!\n";
        return -1;
    }

    int i = 0;
    while (!feof(file)) {
        result[i] = fgetc(file);
        i++;
    }
    result[i - 1] = '\0';

    int size = i;
    fclose(file);

    char path2[] = "text_info.txt";
    FILE* fileinfo = fopen(path2, "w");

    if (!fileinfo) {
        cout << "Error path!!!\n";
        return -1;
    }

    int numbers = 0;
    int letters = 0;
    int symbols = size - 1;
    int spaces = 0;
    int lines = 1;

    for (int i = 0; i < size; i++)
    {
        if (isdigit((unsigned char)result[i])) {
            numbers++;
        }
        else if (isalpha((unsigned char)result[i])) {
            letters++;
        }
        else if (result[i] == ' ') {
            spaces++;
        }
        else if (result[i] == '\n') {
            lines++;
        }
    }

    fprintf(fileinfo, "Symbols: %i\n", symbols);
    fprintf(fileinfo, "Lines: %i\n", lines);
    fprintf(fileinfo, "Spaces: %i\n", spaces);
    fprintf(fileinfo, "Letters: %i\n", letters);
    fprintf(fileinfo, "Numbers: %i\n", numbers);

    fclose(fileinfo);

    printf("\n\n");
    return 0;
}