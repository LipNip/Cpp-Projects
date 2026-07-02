#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>  // FILE, fopen, fgets, fclose
#include <cstring> // strcmp
using namespace std;


int main()
{
    char path[] = "file1.txt";
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

    fclose(file);


    char path2[] = "file2.txt";
    FILE* file2 = fopen(path2, "r");
    char result2[100000];

    if (!file2) {
        cout << "Error path!!!\n";
        return -1;
    }

    int j = 0;
    while (!feof(file2)) {
        result2[j] = fgetc(file2);
        j++;
    }
    result2[j - 1] = '\0';

    fclose(file2);

    if (!strcmp(result, result2)) {
        cout << "The lines match.\n";
    }
    else {
        cout << "The lines don't match.\n";
    
        cout << "\nFILE 1:\n";
        cout << result << "\n";

        cout << "\nFILE 2:\n";
        cout << result2;
    }
    cout << "\n\n";
    return 0;
}