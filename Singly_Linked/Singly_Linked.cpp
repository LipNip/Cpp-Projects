#include <iostream>
#include <stdexcept>
using namespace std;

struct element {
    int data;
    element* next;
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
            //add_head(rand() % 101 - 50);
            add_tail(rand() % 101 - 50);
        }
        this->size = size;
    }

    // Конструктор копіювання
    list(const list& obj) {
        head = tail = nullptr;
        size = 0;
        *this = obj;
    }

    int get_size() const { return size; }
    bool is_empty() const { return !size; }

    void add_head(int value) {
        element* new_element = new element;
        new_element->data = value;
        new_element->next = nullptr;

        if (!size) {
            head = tail = new_element;
        }
        else {
            new_element->next = head;
            head = new_element;
        }
        size++;
    }

    void print()const {
        cout << "SIZE: " << size << "\n";
        cout << string(100, '=') << "\n";
        element* tmp = head;
        while (tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n" << string(100, '=') << "\n";
    }

    void add_tail(int value) {
        element* new_element = new element;
        new_element->data = value;
        new_element->next = nullptr;

        if (!size) {
            head = tail = new_element;
        }
        else {
            tail->next = new_element;
            tail = new_element;
        }
        size++;
    }

    // Вставка елемента в задану позицію
    void add_position(int pos, int value) {
        if (pos > size && pos < 0) {
            return;
        }
        element* new_element = new element;
        new_element->data = value;

        if (!pos) {
            add_head(value);
        }
        else {
            element* ptr = head;
            int i = 0;
            while (i++ < pos - 1) {
                ptr = ptr->next;
            }
            new_element->next = ptr->next;
            ptr->next = new_element;
        }
        if (!pos) {
            tail = new_element;
        }
        size++;
    }

    void delete_head() {
        if (!size) { return; }
        element* tmp = head;
        head = head->next;
        delete tmp;
        size--;
    }

    void delete_tail() {
        if (!size) { return; }
        if (head == tail) { delete_head(); }
        else {
            element* tmp = head;
            while (tmp) {
                if (tmp->next == tail) {
                    delete tail;
                    tail = tmp;
                    tail->next = nullptr;
                    break;
                }
                tmp = tmp->next;
            }
            size--;
        }
    }

    // Видалення елемента із заданої позиції
    void delete_position(int pos) {
        if (pos >= size) {
            return;
        }
        if (!pos) {
            delete_head();
        }
        else {
            element* ptr = head;
            element* tmp;
            int i = 0;
            while (i++ < pos - 1) {
                ptr = ptr->next;
            }

            tmp = ptr->next;
            if (pos == size - 1) {
                tail = ptr;
            }
            ptr->next = tmp->next;
            delete tmp;
            size--;
        }
    }

    // Пошук заданого елемента (функція повертає позицію знайденого елемента у разі успіху чи -1 у разі невдачі)
    int search(int value) const {
        element* ptr = head;
        int pos = 0;

        while (ptr) {
            if (ptr->data == value) { return pos; }
            ptr = ptr->next;
            pos++;
        }
        return -1;
    }

    // Пошук та заміна заданого елемента (функція повертає кількість замінених елементів) 
    int search_and_replace(int old_value, int new_value) {
        element* ptr = head;
        int count = 0;

        while (ptr) {
            if (ptr->data == old_value) {
                ptr->data = new_value;
                count++;
            }
            ptr = ptr->next;
        }
        return count;
    }

    // Видалення всіх елементів списку, рівних заданому 
    int search_delete(int value) {
        int count = 0;

        while (head && head->data == value) {
            delete_head();
            count++;
        }

        element* ptr = head;

        while (ptr && ptr->next) {
            if (ptr->next->data == value) {
                element* tmp = ptr->next;
                ptr->next = tmp->next;

                if (tmp == tail) {
                    tail = ptr;
                }

                delete tmp;
                size--;
                count++;
            }
            else {
                ptr = ptr->next;
            }
        }
        return count;
    }

    void reverse() {
        if (size <= 1) { return; }

        element* prev = nullptr;
        element* current = head;
        element* next_element = nullptr;

        tail = head;

        while (current) {
            next_element = current->next;
            current->next = prev;
            prev = current;
            current = next_element;
        }

        head = prev;
    }

    void clear() {
        while (head) {
            delete_head();
        }
    }

    list& operator=(const list& obj) {
        if (this == &obj) { return *this; }
        clear();
        
        element* tmp = obj.head;
        while (tmp) {
            add_tail(tmp->data);
            tmp = tmp->next;
        }

        return *this;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index is out of bounds!");
        }

        element* ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        return ptr->data;
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index is out of bounds!");
        }

        element* ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        return ptr->data;
    }

    ~list() {
        clear();
    }

};

int menu() {
    cout << "\n0 - EXIT\n";
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
    cout << "Enter coise: ";
    cin >> choise;
    return choise;
}

int main()
{
    srand(time(NULL));
    list l(5);
    /*try{
    
    const list& const_l = l;

    const_l.print();
    cout << const_l[1] << "\n\n\n";

    }
    catch(const out_of_range& e){
        cout << "Error: " << e.what() << "\n";
    }*/

    //system("pause");
    while (true) {
        system("cls");
        l.print();
        int choise = menu();

        if (!choise) break;

        int number, pos;
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
                cout << "Element not found\n";
            }
            system("pause");
            break;
        case 8:
            cout << "Enter element to replace: ";
            cin >> number;
            int new_number;
            cout << "Enter new element: ";
            cin >> new_number;
            cout << "Replaced: " << l.search_and_replace(number, new_number) << " element\n";
            system("pause");
            break;
        case 9:
            cout << "Enter element to delete: ";
            cin >> number;
            cout << "Deleted: " << l.search_delete(number) << " element\n";
            system("pause");
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