#include <iostream>
#include <cstring> // strcmp()
using namespace std;

struct Film {
    char title[50];      // назва фільму
    char director[50];   // режисер
    char genre[30];      // жанр
    double rating;       // рейтинг популярності
    double price;        // ціна диска
};

void set_film(Film& f) {
    cout << "\nEnter title: ";
    gets_s(f.title);

    cout << "Enter director: ";
    gets_s(f.director);

    cout << "Enter genre: ";
    gets_s(f.genre);

    cout << "Enter rating: ";
    cin >> f.rating;

    cout << "Enter price: ";
    cin >> f.price;
    cin.ignore();
}

void set_films(Film* films, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << "\nFilm: " << i + 1;
        set_film(films[i]);
    }
    cout << '\n';
}

void print_film(Film& f)
{
    cout << "\n--- Film Info ---\n";
    cout << "Title: " << f.title << "\n";
    cout << "Director: " << f.director << "\n";
    cout << "Genre: " << f.genre << "\n";
    cout << "Rating: " << f.rating << "\n";
    cout << "Price: " << f.price << "\n";
}

void print_films(Film* films, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << "\nFilm " << i + 1;
        print_film(films[i]);
    }
}

int find_film_by_title(Film* films, int size, const char* name) {
    for (int i = 0; i < size; i++)                          //  strcmp() - порівняння стрічок.Повертає:
    {                                                       //  1 - якщо перша стрічка більша від другою
        if (strcmp(films[i].title, name) == 0) {            //  -1 - якщо перша стрічка менша від другої
            return i;                                       //  0 - стрічки рівні
        }
    }
    return -1;
}

int find_film_by_genre(Film* films, int size, const char* name, int* result) {
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(films[i].genre, name) == 0) {
            result[count] = i;
            count++;
        }
    }
    return count;
}

int find_film_by_director(Film* films, int size, const char* name, int* result) {
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(films[i].director, name) == 0) {
            result[count] = i;
            count++;
        }
    }
    return count;
}

void add_film(Film*& films, int& size) {
    Film* temp = new Film[size + 1];

    for (int i = 0; i < size; i++)
    {
        temp[i] = films[i];
    }

    cout << "\nEnter new film:\n";
    set_film(temp[size]);

    delete[] films;

    films = temp;
    size++;
}

int find_best_film_by_genre(Film* films, int size, const char* genre) {
    int index = -1;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(films[i].genre, genre) == 0) {
            if (index == -1 || films[i].rating > films[index].rating) {
                index = i;
            }
        }
    }

    return index;
}

int menu() {
    int choice;
  
    cout << "\n===== FILM DATABASE MENU =====\n";
    cout << "0 - Exit\n";
    cout << "1 - Show all films\n";
    cout << "2 - Search film by title\n";
    cout << "3 - Search films by genre\n";
    cout << "4 - Search films by director\n";
    cout << "5 - Find best film in genre\n";
    cout << "6 - Add new film\n";
    cout << "==============================\n";

    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    system("color 03");
    int size;

    do {
        cout << "Enter number of films: ";
        cin >> size;
        cin.ignore();
    } while (size <= 0);
    
    Film* films = new Film[size];

    set_films(films, size);
    char name[30];
    int* result = new int[size];
    char genre[30];
    int index, count;
    do {
        system("cls");

        int choice = menu();

        if (!choice) break;

        switch (choice) {
        case 1:
            print_films(films, size);
            system("pause");
            break;
        case 2:
            cin.ignore();
            
            cout << "\nEnter film name to found: ";
            gets_s(name);

            index = find_film_by_title(films, size, name);

            if (index == -1) {
                cout << "Film not found!\n";
            }
            else {
                cout << "Film found!\n";
                print_film(films[index]);
            }
            system("pause");
            break;
        case 3:
            cin.ignore();
            
            cout << "\nEnter film genre to found: ";
            gets_s(name);

            count = find_film_by_genre(films, size, name, result);

            if (count == 0) {
                cout << "Film not found!\n";
            }
            else {
                cout << "Film found!\n";
                for (int i = 0; i < count; i++)
                {
                    print_film(films[result[i]]);
                }
            }
            system("pause");
            break;
        case 4:
            cin.ignore();
            
            cout << "\nEnter film director to found: ";
            gets_s(name);

            count = find_film_by_director(films, size, name, result);

            if (count == 0) {
                cout << "Film not found!\n";
            }
            else {
                cout << "Film found!\n";
                for (int i = 0; i < count; i++)
                {
                    print_film(films[result[i]]);
                }
            }
            system("pause");
            break;
        case 5:
            cin.ignore();

            cout << "\nEnter genre: ";
            gets_s(genre);

            index = find_best_film_by_genre(films, size, genre);

            if (index == -1) {
                cout << "No films found in this genre!\n";
            }
            else {
                cout << "\nBest film in genre:\n";
                print_film(films[index]);
            }

            system("pause");
            break;
        case 6:
            cin.ignore();
            add_film(films, size);
            break;
        }
    } while (true);
    
    delete[] films;
    delete[] result;
    cout << "\n\n";
    return 0;
}