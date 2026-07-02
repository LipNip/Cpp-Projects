#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>    // FILE, fopen, fgetc, fputc
#include <algorithm> // reverse
using namespace std;

int main()
{
    char path[] = "text.txt";
    FILE* file = fopen(path, "r");
    char result[100000];

    if (!file) {
        printf("Error path!!!\n");
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

    char path2[] = "text2.txt";
    FILE* fileCopy = fopen(path2, "w");

    if (!fileCopy) {
        printf("Error path!!!\n");
        return -1;
    }

    reverse(result, result + size - 1);
    //_strrev(result);

    for (int i = 0; i < size - 1; i++) {
        fputc(result[i], fileCopy);
    }

    printf("File copied and reversed successfully!");
    fclose(fileCopy);
    
    printf("\n\n");
    return 0;
}