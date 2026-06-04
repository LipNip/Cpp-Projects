#include <iostream>
using namespace std;
int main()
{
    double price;
    cout << "Enter the price of the product: ";
    cin >> price;

    double discount;
    cout << "Enter the discount: ";
    cin >> discount;

    cout <<"\n \n" << "----------------------------------\n" <<"Price without discount: " << price << "\n" << "Price with discount: " << price - (price * discount / 100) << "\n----------------------------------\n";
}