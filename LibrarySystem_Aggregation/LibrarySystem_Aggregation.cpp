#include <iostream>
#include <string>
#include <vector>   // Динамічний масив, який вміє автоматично змінювати свій розмір під час роботи програми.
#include <algorithm>    // find()
using namespace std;

class Book {
    string author, title;
    int year;
public:
    Book() : author("No author"), title("No title"), year(-1) {}
    Book(const string& author, const string& title, int year) : author(author), title(title), year(year) {}   // Передаємо рядки за константним посиланням для оптимізації

    void print()const {
        cout << "Author: " << author << "\n";
        cout << "Title: " << title << "\n";
        cout << "Year: " << year << "\n";
    }
};

class Shelf {
    int number;
    vector<Book*> books;
public:
    Shelf(int number) : number(number) {}

    void addBook(Book* book) { books.push_back(book); }
    void removeBook(Book* book) {
        auto it = find(books.begin(), books.end(), book);   // Auto - автоматично визначити тип змінної. .find повертає ітератор
        if (it != books.end()) {    
            books.erase(it);
        }
        else {
            cout << "Not found!\n";
        }
    }
    void print()const {
        for (size_t i = 0; i < books.size(); i++)    //.size() повертає значення типу size_t
        {
            books[i]->print();
            cout << "\n";
        }
    }
};

int main()
{
    Book book1("Antoine de Saint-Exupery", "The Little Prince", 1943);
    Book book2("J.R.R. Tolkien", "The Lord of the Rings", 1954);
    Book book3("J.K. Rowling", "Harry Potter and the Philosopher's Stone", 1997);
    Book book4("Agatha Christie", "And Then There Were None", 1939);
    
    Shelf shelf1(101);
    shelf1.addBook(&book1);
    shelf1.addBook(&book2);

    cout << "Shelf 1:\n";
    shelf1.print();

    Shelf shelf2(102);
    shelf2.addBook(&book3);
    shelf2.addBook(&book4);

    cout << "Shelf 2:\n";
    shelf2.print();

    cout << "\n\n";
    return 0;
}