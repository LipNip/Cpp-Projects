#include <iostream>
using namespace std;

class train {
    char* train_number;
    char* train_name;
    int* carriages;
    int carriage_count;
public:
    train() {
        train_number = new char[100];
        train_name = new char[100];
        carriages = nullptr;
        carriage_count = 0;
    }
    train(const char* train_number, const char* train_name, const int* carriages, int carriage_count) {
        this->train_number = new char[strlen(train_number) + 1];
        strcpy_s(this->train_number, strlen(train_number) + 1, train_number);
        this->train_name = new char[strlen(train_name) + 1];
        strcpy_s(this->train_name, strlen(train_name) + 1, train_name);
        this->carriage_count = carriage_count;

    }
    train(const train& other) {
        carriage_count = other.carriage_count;
        train_number = new char[strlen(other.train_number) + 1];
        strcpy_s(train_number, strlen(other.train_number) + 1, other.train_number);
        train_name = new char[strlen(other.train_name) + 1];
        strcpy_s(train_name, strlen(other.train_name) + 1, other.train_name);
    }
    ~train() {
        delete[] train_number;
        delete[] train_name;
        delete[] carriages;
    }

    void train_number(const char* train_number) {
        this->train_number = new char[strlen(train_number) + 1];
        strcpy_s(this->train_number, strlen(train_number) + 1, train_number);
    }

    const char* get_train_number() const {
        return train_number;
    }

    const char* get_train_name() const {
        return train_name;
    }

    void set_carriage_count(int carriage_count) {
        this->carriage_count = carriage_count;
    }
    int get_carriage_count() {
        return carriage_count;
    }
};

int main()
{
    

    cout << "\n\n";
    return 0;
}
