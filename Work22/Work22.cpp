#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleCP(65001);//1251
    SetConsoleOutputCP(65001);//1251
    int choice, sum = 0, money;
    char choice_y_n;
    do{
    cout << "\n------------------------------\n       МЕНЮ\n1 - Сніданок\n2 - Обід\n3 - Вечеря\n4 - Десерт\n------------------------------\nЗробіть ваш вибір: ";
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "\n------------------------------\n       СНІДАНОК\n1 - Чай           35 грн.\n2 - Канапка       65 грн.\n3 - Суп           85 грн.\n4 - Фрукти        70 грн.\n-----------------------------\nЗробіть ваш вибір: ";
        cin >> choice;
        if (choice == 1)
            sum = sum + 35;
        else if (choice == 2)
            sum = sum + 65;
        else if (choice == 3)
            sum = sum + 85;
        else if (choice == 4)
            sum = sum + 70;
        break;

    case 2:
        cout << "\n------------------------------\n       ОБІД\n1 - Борщ              110 грн.\n2 - Котлета з пюре    165 грн.\n3 - Салат             90 грн.\n4 - Компот            35 грн.\n-----------------------------\nЗробіть ваш вибір: ";
        cin >> choice;
        if (choice == 1)
            sum = sum + 110;
        else if (choice == 2)
            sum = sum + 165;
        else if (choice == 3)
            sum = sum + 90;
        else if (choice == 4)
            sum = sum + 35;
       break;

    case 3:
        cout << "\n-----------------------------\n       ВЕЧЕРЯ\n1 - Рис з куркою     150 грн.\n2 - Омлет            85 грн.\n3 - Вареники         130 грн.\n4 - Кефір            45 грн.\n-----------------------------\nЗробіть ваш вибір: ";
        cin >> choice;
        if (choice == 1)
            sum = sum + 150;
        else if (choice == 2)
            sum = sum + 85;
        else if (choice == 3)
            sum = sum + 130;
        else if (choice == 4)
            sum = sum + 45;
        break;

    case 4:
        cout << "\n------------------------------\n       ДЕСЕРТ\n1 - Морозиво        60 грн.\n2 - Печиво          45 грн.\n3 - Цукерки         55 грн.\n4 - Торт            120 грн.\n------------------------------\nЗробіть ваш вибір: ";
        cin >> choice;
        if (choice == 1)
            sum = sum + 60;
        else if (choice == 2)
            sum = sum + 45;
        else if (choice == 3)
            sum = sum + 55;
        else if (choice == 4)
            sum = sum + 120;
        break;

    default:
        cout << "\nТакого пункту меню немає! Спробуйте ще раз.\n";
        break;
    }
    cout << "\nВи бажаєте ще щось купити?(y/n) ";
    cin >> choice_y_n;
    } while (choice_y_n != 'n');
    
    do{
    cout << "\n------------------------------\nДо оплати:         " << sum << " грн.\nВнесіть гроші:     ";
    cin >> money;
    if (money > sum){
        cout << "Ваша решта:        " << money - sum << " грн.\n";
        sum = 0;
    }
    else if (money < sum) {
        cout << "Потрібно доплатити: " << sum - money << " грн.";
        sum = sum - money;
    }
    else {
        sum = 0;
    }
    } while (sum != 0);
    cout << "Дякуємо за покупку!\n-----------------------------";

    cout << "\n\n";
    return 0;
}