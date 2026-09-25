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
        train_number[0] = '\0';
        train_name = new char[100];
        train_name[0] = '\0';
        carriages = nullptr;
        carriage_count = 0;
    }
    train(const char* train_number, const char* train_name, const int* carriages, int carriage_count) {
        this->train_number = new char[strlen(train_number) + 1];
        strcpy_s(this->train_number, strlen(train_number) + 1, train_number);
        this->train_name = new char[strlen(train_name) + 1];
        strcpy_s(this->train_name, strlen(train_name) + 1, train_name);
        this->carriage_count = carriage_count;
        if (carriage_count > 0 && carriages != nullptr) {
            this->carriages = new int[carriage_count];
            for (int i = 0; i < carriage_count; i++)
            {
                this->carriages[i] = carriages[i];
            }
        }
        else {
            this->carriages = nullptr;
        }
    }
    train(const train& other) {
        carriage_count = other.carriage_count;
        train_number = new char[strlen(other.train_number) + 1];
        strcpy_s(train_number, strlen(other.train_number) + 1, other.train_number);
        train_name = new char[strlen(other.train_name) + 1];
        strcpy_s(train_name, strlen(other.train_name) + 1, other.train_name);
        if (carriage_count > 0 && other.carriages != nullptr) {
            carriages = new int[carriage_count];
            for (int i = 0; i < carriage_count; i++)
            {
                carriages[i] = other.carriages[i];
            }
        }
        else {
            carriages = nullptr;
        }
    }
    ~train() {
        delete[] train_number;
        delete[] train_name;
        delete[] carriages;
    }

    void set_train_number(const char* train_number) {
        delete[] this->train_number;
        this->train_number = new char[strlen(train_number) + 1];
        strcpy_s(this->train_number, strlen(train_number) + 1, train_number);
    }

    const char* get_train_number() const {
        return train_number;
    }

    void set_train_name(const char* name) {
        delete[] this->train_name;
        this->train_name = new char[strlen(name) + 1];
        strcpy_s(this->train_name, strlen(name) + 1, name);
    }

    const char* get_train_name() const {
        return train_name;
    }

    void set_carriages(const int* arr, int count) {
        delete[] this->carriages;
        carriage_count = count;
        if (count > 0 && arr != nullptr) {
            carriages = new int[count];
            for (int i = 0; i < count; i++)
            {
                carriages[i] = arr[i];
            }
        }
        else {
            carriages = nullptr;
        }
    }

    const int* get_carriages() const {
        return carriages;
    }

    int get_carriage_count() const {
        return carriage_count;
    }

    void print_info() const {
        cout << "Train №" << train_number << " («" << train_name << "»)\n";
        cout << "Total passengers: " << sum_passengers() << "\n";
        cout << "Carriage count: " << carriage_count << "\n";
        if (carriage_count > 0) {
            cout << "Carriage with MIN passengers: №" << min_carriage_index() + 1
                 << " (" << carriages[min_carriage_index()] << " pas.)\n";
            cout << "Carriage with MAX passengers: №" << max_carriage_index() + 1
                << " (" << carriages[max_carriage_index()] << " pas.)\n";
            cout << "Passengers in the carriages: ";
            for (int i = 0; i < carriage_count; i++)
            {
                cout << "[Carriage " << i + 1 << ": " << carriages[i] << " pas.] ";
            }
            cout << "\n";
        }
    }

    int sum_passengers() const {
        int sum = 0;
        for (int i = 0; i < carriage_count; i++)
        {
            sum += carriages[i];
        }
        return sum;
    }

    int max_carriage_index() const {
        if (carriage_count == 0) return -1;
        int max_idx = 0;
        for (int i = 1; i < carriage_count; i++)
        {
            if (carriages[i] > carriages[max_idx]) {
                max_idx = i;
            }
        }
        return max_idx;
    }

    int min_carriage_index() const {
        if (carriage_count == 0) return -1;
        int min_idx = 0;
        for (int i = 1; i < carriage_count; i++)
        {
            if (carriages[i] < carriages[min_idx]) {
                min_idx = i;
            }
        }
        return min_idx;
    }
};

train get_max_passengers_train(train* trains, int count) {
    if (count == 0) return train();
    int max_idx = 0;
    for (int i = 0; i < count; i++)
    {
        if (trains[i].sum_passengers() > trains[max_idx].sum_passengers()) {
            max_idx = i;
        }
    }
    return trains[max_idx];
}

train get_min_passengers_train(train* trains, int count) {
    if (count == 0) return train();
    int min_idx = 0;
    for (int i = 0; i < count; i++)
    {
        if (trains[i].sum_passengers() < trains[min_idx].sum_passengers()) {
            min_idx = i;
        }
    }
    return trains[min_idx];
}

int main()
{
    int train_count;
    do{
    cout << "Enter trains count: ";
    cin >> train_count;
    } while (train_count <= 0);

    train* trains = new train[train_count];

    for (int i = 0; i < train_count; i++)
    {
        cout << "\n Train data input №" << i + 1 << "\n";

        char number[100];
        char name[100];
        int carriage_count;

        cout << "Enter train number: ";
        cin >> number;

        cout << "Enter train name: ";
        cin.ignore();
        gets_s(name, 100);

        cout << "Enter number of carriages: ";
        cin >> carriage_count;

        int* temp_carriages = nullptr;
        if (carriage_count > 0) {
            temp_carriages = new int[carriage_count];
            for (int j = 0; j < carriage_count; j++)
            {
                cout << "Number of passengers in carriage №" << j + 1 << ": ";
                cin >> temp_carriages[j];
            }
        }
        trains[i].set_train_number(number);
        trains[i].set_train_name(name);
        trains[i].set_carriages(temp_carriages, carriage_count);
        if (temp_carriages != nullptr) {
            delete[] temp_carriages;
        }
    }

    for (int i = 0; i < train_count; i++) {
        trains[i].print_info();
        cout << "----------------------------------------------\n";
    }

    train max_train = get_max_passengers_train(trains, train_count);
    cout << "1. Train with the largest number of passengers №" << max_train.get_train_number() << "\n";
    train min_train = get_min_passengers_train(trains, train_count);
    cout << "2. Train with the smallest number of passengers №" << min_train.get_train_number() << "\n";

    delete[] trains;
    cout << "\n\n";
    return 0;
}
