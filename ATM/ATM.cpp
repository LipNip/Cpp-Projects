#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleCP(65001);//1251
    SetConsoleOutputCP(65001);//1251

    int login1 = 1, login2 = 2, login3 = 3;
    int password1 = 1111, password2 = 2222, password3 = 3333;
    int login, password, sum, remained_money = 1000;
    int m50 = 0, m20 = 0, m10 = 0, m5 = 0;
    cout << "--------------------------\n    ВАС ВІТАЄ БАНКОМАТ\n--------------------------\n";
    while(remained_money > 0){
    cout << "\n\n--------------------------";
    do {
        cout << "\nВведіть логін: ";
        cin >> login;
        if (login != login1 && login != login2 && login != login3) {
            cout << "Неправильний логін\n";
        }
    } while (login != login1 && login != login2 && login != login3);

    do {
        cout << "Введіть пароль: ";
        cin >> password;
        if ((login == login1 && password != password1) ||
            (login == login2 && password != password2) ||
            (login == login3 && password != password3)) {
            cout << "Неправильний пароль\n\n";
        }

    } while ((login == login1 && password != password1) ||
        (login == login2 && password != password2) ||
        (login == login3 && password != password3)
        );
    
    cout << "\nВітаємо користувач " << login;

    do{
    cout << "\nВведіть суму: ";
    cin >> sum;
    if (sum % 5 != 0) {
        cout << "Сума має бути кратна 5\n";
    }
    else if (sum > remained_money) {
        cout << "В банкоматі залишилося тільки " << remained_money << " грн.";
    }
    } while (sum % 5 != 0 || sum > remained_money);
    remained_money = remained_money - sum;
    int temp_sum = sum;

    m50 = temp_sum / 50;       
    temp_sum = temp_sum % 50;
    if (m50 > 0) {
        if (m50 % 100 >= 11 && m50 % 100 <= 14) {
            cout << m50 << " купюр по 50 грн.\n";
        }
        else if (m50 % 10 == 1) {
            cout << m50 << " купюра по 50 грн.\n";
        }
        else if (m50 % 10 == 2 || m50 % 10 == 3 || m50 % 10 == 4) {
            cout << m50 << " купюри по 50 грн.\n";
        }
        else {
            cout << m50 << " купюр по 50 грн.\n";
        }
    }

    m20 = temp_sum / 20;
    temp_sum = temp_sum % 20;
    if (m20 > 0) {
        if (m20 % 100 >= 11 && m20 % 100 <= 14) {
            cout << m20 << " купюр по 20 грн.\n";
        }
        else if (m20 % 10 == 1) {
            cout << m20 << " купюра по 20 грн.\n";
        }
        else if (m20 % 10 == 2 || m20 % 10 == 3 || m20 % 10 == 4) {
            cout << m20 << " купюри по 20 грн.\n";
        }
        else {
            cout << m20 << " купюр по 20 грн.\n";
        }
    }

    m10 = temp_sum / 10;
    temp_sum = temp_sum % 10;
    if (m10 > 0) {
        if (m10 % 100 >= 11 && m10 % 100 <= 14) {
            cout << m10 << " купюр по 10 грн.\n";
        }
        else if (m10 % 10 == 1) {
            cout << m10 << " купюра по 10 грн.\n";
        }
        else if (m10 % 10 == 2 || m10 % 10 == 3 || m10 % 10 == 4) {
            cout << m10 << " купюри по 10 грн.\n";
        }
        else {
            cout << m10 << " купюр по 10 грн.\n";
        }
    }

    m5 = temp_sum / 5;
    temp_sum = temp_sum % 5;
    if (m5 > 0){
        if (m5 % 100 >= 11 && m5 % 100 <= 14) {
            cout << m5 << " купюр по 5 грн.\n";
        }
        else if (m5 % 10 == 1) {
            cout << m5 << " купюра по 5 грн.\n";
        }
        else if (m5 % 10 == 2 || m5 % 10 == 3 || m5 % 10 == 4) {
            cout << m5 << " купюри по 5 грн.\n";
        }
        else {
            cout << m5 << " купюр по 5 грн.\n";
        }
        }
    }
    cout << "\nВибачте, в банкоматі закінчилися гроші";
    return 0;
}