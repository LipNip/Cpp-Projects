#pragma warning(disable: 4996);
#include <windows.h>
#include <iostream>
#include <ctime>
using namespace std;

void set_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 101 - 50;
    }
}

void print_console_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void print_file_arr(int* arr, int size, FILE* file) {
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%i ", arr[i]);
    }
}

int main()
{
   //------------------ Ввід\вивід данних на консоль (чиста С)

    /*printf("Hello World");
    
    int a = 2;
    int b = 1;

    printf("\n");
    printf("a: %i | b: %i", a, b);

    printf("\n");
    printf("%"); //не виводе
    printf("i");*/

   //-------------------- Символи після % (плейсхолдери):
   // i, d - цілі числа
   // g - дійсні числа
   // с - символ
   // s - стрічка
   // p - вказівник

   /* printf("\n");
    printf("\n");
    char name[] = "John";
    printf("My name is: %s", name);
    printf("\n");
    printf("\n");


    printf("Enter number: ");
    scanf_s("%i", &a);
    scanf_s("%i", &b);

    printf("A: %i\nB: %i", a, b);

    printf("\n");
    printf("\n");*/


    /*int n, m;
    printf("Enter N: ");
    scanf_s("%i", &n); 
    printf("Enter M: ");
    scanf_s("%i", &m); 
    int s = n + m;
    printf("Sum: %i", s);*/


    /*
    printf("%%%%"); // %%
    */



    //------------------------------ ЗАПИС\ЗЧИТУВАННЯ ДАННИХ У\З ФАУЛУ
    // fprint() - для запису
    // fscanаf() - для зчитування


   /* char path[] = "data.txt";
    FILE* file = fopen(path, "w");
    if (!file) {
        cout << "Error path!!!\n";
        return -1;
    }
    
    fprintf(file, "HEllo\nWord");

    fclose(file);*/


   /* char path[] = "data.txt";
    FILE* file = fopen(path, "w");

    if (!file) {
        cout << "Error path!!!\n";
        return -1;
    }

    for (int i = 0; i < 100000000; i++)
    {
        fprintf(file, "%i Hello\n", i);
    }

    fclose(file);*/

    /*char path[] = "table.txt";
    FILE* file = fopen(path, "w");

    if (!file) {
        cout << "Error path!!!\n";
        return -1;
    }

 

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            fprintf(file, "%i * %i = %i\n", i, j, i*j);
        }
        fprintf(file, "\n");
    }

    fclose(file);*/


     /*char path[] = "vzlom.txt";
       FILE* file = fopen(path, "w");

       if (!file) {
           cout << "Error path!!!\n";
           return -1;
       }

       for (int i = 0; i < 10000000000000000000; i++)
       {
           fprintf(file, "%i Hello\n", i);
       }

       fclose(file);*/

        

    //char path[] = "data2.txt";
    //FILE* file = fopen(path, "a");

    //if (!file) {
    //    cout << "Error path!!!\n";
    //    return -1;
    //}
    //char grup[30];
    //cout << "Enter grup: ";
    //gets_s(grup);

    //for (int i = 0; i < 100000; i++)
    //{
    //    fprintf(file, " %s ", grup);
    //}
    //
    //fclose(file);



  /*  char name[30], surname[30];
    int age;*/
        
       
    

    /*cout << "Enter name: ";
    gets_s(name);

    cout << "Enter surname: ";
    gets_s(surname);

    cout << "Enter age: ";
    cin >> age;*/

   

    // зчитування
    
    /*char name[30];
    char path[] = "data2.txt";
    FILE* file = fopen(path, "r");

    if (!file) {
        cout << "Error path!!!\n";
        return -1;
    }

    fscanf(file, "%s", name);
    fclose(file);*/

SetConsoleOutputCP(12051); // для хлопушки 🎉;
SetConsoleCP(12051);
   
  /*  char name[30];
    char surname[30];
    char group[30];
    int age;
    char path[] = "name.txt";
    FILE* file = fopen(path, "r");

    if (!file) {
        cout << "Error path!!!\n";
        return -1;
    }

    fscanf(file, "%s%s%i%s", name, surname, &age, group);
    printf("%s %s %i %s", name, surname, age, group);

    fclose(file);


    cout << "\n\nYou win!🎉";*/


//const int size = 10;
//int arr[size];

   
//set_arr(arr, size);
//print_console_arr(arr, size);
//char path[] = "data4.txt";
//FILE* file = fopen(path, "w");
//if (!file) {
//    cout << "Error path!!!\n";
//    return -1;
//}
//print_file_arr(arr, size, file);
//fclose(file);



    // Посимвольне зчитування\запис у\з файлу
    // fgetc() - зчитування 1 символу
    // fputc() - запис 1 символу
    // feof() - зчитує поки не кінець файлу

//повністю считує
//char path[] = "data4.txt";
//FILE* file = fopen(path, "r");
//char result[100000];
//if (!file) {
//        cout << "Error path!!!\n";
//        return -1;
//    }
//
//
//int i = 0;
//while (!feof(file)) {
//    result[i] = fgetc(file);
//    i++;
//}
//result[i - 1] = '\0';
//fclose(file);
//cout << result << "\n";

//char path[] = "data4.txt";
//FILE* file = fopen(path, "w");
//char result[100000];
//if (!file) {
//    cout << "Error path!!!\n";
//    return -1;
//}
//
//fputc('h', file);
//fputc('e', file);
//fputc('l', file);
//fputc('l', file);
//fputc('o', file);
//fclose(file);


//while (true) {
//    system("color 02");
//    Sleep(1000);
//    system("color 05");
//    Sleep(1000);
//}

//cout << "HelloWorld";


//char path[] = "Files.cpp";
//FILE* file = fopen(path, "r");
//char result[100000];
//
//if (!file) {
//    cout << "Error path!!!\n";
//    return -1;
//}
//
//int i = 0;
//while (!feof(file)) {
//    result[i] = fgetc(file);
//    i++;
//}
//result[i - 1] = '\0';
//
//int copu_size = i;
//
//fclose(file);
//
//char pathh[] = "Files_copu.cpp";
//FILE* filecopu = fopen(pathh, "w");
//
//if (!filecopu) {
//    cout << "Error path!!!\n";
//    return -1;
//}
//
//for (int i = 0; i < copu_size - 1; i++)
//{
//    fputc(result[i], filecopu);
//}
//
//fclose(filecopu);
//cout << result << "\n";


///// реверс завд 2
/*
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
int coup_size = i;
fclose(file);

char pathh[] = "file2.txt";
FILE* filecopu = fopen(pathh, "w");

if (!filecopu) {
    cout << "Error path!!!\n";
    return -1;
}

//reverse(result, result + coup_size - 1);
_strrev(result);

for (int i = 0; i < coup_size - 1; i++) {
    fputc(result[i], filecopu);
}

fclose(filecopu);
*/
///// реверс завд 2
///// завд 3
/*
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

int copu_size = i;
fclose(file);

char pathh[] = "file1_info.txt";
FILE* filecopu = fopen(pathh, "w");

if (!filecopu) {
    cout << "Error path!!!\n";
    return -1;
}

int numbers = 0;
int letters = 0;
int symbols = strlen(result);
int spaces = 0;
int lines = 1;
for (int i = 0; i < strlen(result); i++) {
    
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
fprintf(filecopu, "Symbols: %i\n", symbols);
fprintf(filecopu, "Lines: %i\n", lines);
fprintf(filecopu, "Spaces: %i\n", spaces);
fprintf(filecopu, "Letters: %i\n", letters);
fprintf(filecopu, "Numbers: %i\n", numbers);
fclose(filecopu);
*/
///// завд 3
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

int copu_size = i;
fclose(file);


char path[] = "file1.txt";
FILE* file = fopen(path, "r");
char result2[100000];

if (!file) {
    cout << "Error path!!!\n";
    return -1;
}

int i = 0;
while (!feof(file)) {
    result2[i] = fgetc(file);
    i++;
}
result2[i - 1] = '\0';

int copu_size = i;
fclose(file);

if (!strcmp(result, result2)) {
    cout << "Рівні";
}
else {
    cout << "Не рівні";
}

}