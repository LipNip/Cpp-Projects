#include <iostream>
#include <string>
#include <cstdlib> // rand() srand() system()
#include <ctime>   // time()
#include <stdexcept>
using namespace std;

struct element {
    int data;
    element* next, * prev;
};

class list {
    element* head, * tail;
    int size;
public:
    list() {
        head = tail = nullptr;
        size = 0;
    }

    list(int size) {
        for (int i = 0; i < size; i++)
        {
            add_tail(rand() % 101 - 50);
        }
    }

    // Конструктор копіювання
    list(const list& obj) {
        head = tail = nullptr;
        size = 0;
        *this = obj;
    }

    void add_head(int value) {
        element* new_element = new element;
        new_element->data = value;
        new_element->next = new_element->prev = nullptr;

        if (size == 0) {
            head = tail = new_element;
        }
        else {
            new_element->next = head;
            head->prev = new_element;
            head = new_element;
        }
        size++;
    }

    void add_tail(int value) {
        element* new_element = new element;
        new_element->data = value;
        new_element->next = new_element->prev = nullptr;
        if (size == 0) {
            head = tail = new_element;
        }
        else {
            tail->next = new_element;
            new_element->prev = tail;
            tail = new_element;
        }
        size++;
    }

    // Вставка елемента в задану позицію
    void add_position(int pos, int value) {
        if (pos > size || pos < 0) { return; }
        if (!pos) { add_head(value); return; }
        if (pos == size) { add_tail(value); return; }

        element* new_element = new element;
        new_element->data = value;
        
        element* ptr1 = head;
            
        for (int i = 0; i < pos - 1; i++){ ptr1 = ptr1->next; }

        element* ptr2 = ptr1->next;
        new_element->prev = ptr1;
        new_element->next = ptr2;
        ptr1->next = new_element;
        ptr2->prev = new_element;

        size++;
    }
        
    void delete_head() {
        if (!size) {
            return;
        }
        element* temp = head;
        head = head->next;

        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

        delete temp;
        size--;
    }

    void delete_tail() {
        if (!size) {
            return;
        }
        element* temp = tail;
        tail = tail->prev;

        if (size != 1) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
        size--;
    }

    // Видалення елемента заданої позиції
    void delete_position(int pos) {
        if (pos < 0 || pos >= size) {
            return;
        }
        if (!pos) {
            delete_head();
        }
        else if (pos == size - 1) {
            delete_tail();
        }
        else {
            element* tmp = head;
            int i = 0;
            while (i++ < pos) {
                tmp = tmp->next;
            }
            element* ptr1 = tmp->prev, * ptr2 = tmp->next;
            ptr1->next = ptr2;
            ptr2->prev = ptr1;
            delete tmp;
            size--;
        }
    }

    // Пошук заданого елемента (функція повертає позицію знайденого елемента у разі успіху чи - 1 у разі невдачі)                       
    int search(int value) const {
        element* tmp = head;
        int pos = 0;

        while (tmp) {
            if (tmp->data == value) { return pos; }
            tmp = tmp->next;
            pos++;
        }

        return -1;
    }

    // Пошук та заміна заданого елемента (функція повертає кількість замінених елементів)
    int search_replace(int old_value, int new_value) {
        element* tmp = head;
        int count = 0;

        while (tmp) {
            if (tmp->data == old_value) {
                tmp->data = new_value;
                count++;
            }
            tmp = tmp->next;
        }

        return count;
    }

    // Видалення всіх елементів списку, рівних заданому
    void delete_all_search(int value) {
        if (!size) {
            return;
        }

        element* tmp = head;
        int i = 0;
        while (tmp) {
            if (tmp->data == value) {
                tmp = tmp->next;
                delete_position(i);
                continue;
            }
            tmp = tmp->next;
            i++;
        }
    }

    // Переворот списку(reverse)
    void reverse() {
        element* tmp = head;

        while (tmp) {
            element* next = tmp->next;

            tmp->next = tmp->prev;
            tmp->prev = next;

            tmp = next;
        }

        element* temp = head;
        head = tail;
        tail = temp;
    }

    void clear() {
        while (head) {
            delete_head();
        }
    }

    void print()const {
        cout << "SIZE: " << size << "\n";
        cout << string(100, '-') << "\n";
        element* tmp = head;
        while (tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n" << string(100, '-') << "\n";
    }

    // Перевантаження оператора індексації
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds!");
        }

        element* tmp = head;

        for (int i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
        
        return tmp->data;
    }

    // Перевантаження оператора індексації для const
    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds!");
        }

        element* tmp = head;

        for (int i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }

        return tmp->data;
    }

    // Перевантаження оператора присвоєння
    list& operator=(const list& obj) {
        if (this == &obj) {
            return *this;
        }

        clear();

        element* tmp = obj.head;
        while (tmp) {
            add_tail(tmp->data);
            tmp = tmp->next;
        }
        
        return *this;
    }

    ~list() {
        clear();
    }
};

int menu() {
    cout << "0 - EXIT\n";
    cout << "1 - ADD HEAD\n";
    cout << "2 - ADD TAIL\n";
    cout << "3 - ADD POSITION\n";
    cout << "4 - DELETE HEAD\n";
    cout << "5 - DELETE TAIL\n";
    cout << "6 - DELETE POSITION\n";
    cout << "7 - SEARCH\n";
    cout << "8 - SEARCH AND REPLACE\n";
    cout << "9 - SEARCH DELETE\n";
    cout << "10 - REVERSE\n";
    cout << "11 - CLEAR\n";

    int choise;
    cout << "Enter choise: ";
    cin >> choise;
    return choise;
}

int main()
{
    srand(time(NULL));

    list l(5);
    l.print();

    while (true) {
        system("cls");
        l.print();
        int choise = menu();

        if (!choise) break;

        int number, pos, new_number;
        switch (choise) {
        case 1:
            cout << "Enter number: ";
            cin >> number;
            l.add_head(number);
            break;
        case 2:
            cout << "Enter number: ";
            cin >> number;
            l.add_tail(number);
            break;
        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter number: ";
            cin >> number;
            l.add_position(pos, number);
            break;
        case 4:
            l.delete_head();
            break;
        case 5:
            l.delete_tail();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            l.delete_position(pos);
            break;
        case 7:
            cout << "Enter number: ";
            cin >> number;
            pos = l.search(number);

            if (pos != -1) {
                cout << "Element found at position: " << pos << "\n";
            }
            else {
                cout << "Element not found!\n";
            }

            system("pause");
            break;
        case 8:
            cout << "Enter number to replace: ";
            cin >> number;
            cout << "Enter new number: ";
            cin >> new_number;

            cout << "Replaced elements: " << l.search_replace(number, new_number) << "\n";

            system("pause");
            break;
        case 9:
            cout << "Enter number: ";
            cin >> number;
            l.delete_all_search(number);
            break;
        case 10:
            l.reverse();
            break;
        case 11:
            l.clear();
            break;
        }
    }

    cout << "\n\n";
    return 0;
}