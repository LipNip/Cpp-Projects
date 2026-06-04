#include <iostream>
using namespace std;
int main()
{
    double price;
    cout << "Enter the price for one minute: ";
    cin >> price;

    int time;
    cout << "Enter the call duration in seconds: ";
    cin >> time;


    int minutes = time / 60;
    int seconds = time % 60;
    double exactMinutes = (double)time / 60; // Робимо тимчасове перетворення time на double для точних грошей. Або я міг написати не 60 а 60.0. Чому я зразу не написав double time? бо тоді б не працював %. 
    
    double total_price = exactMinutes * price;

    cout << "\n \n---------------------------------------------------------------------------------------------------\nYou talked: " << minutes << " minutes, " << seconds << " seconds. Price for one minute: " << price <<". Total cost of the call: " << total_price << ". \n---------------------------------------------------------------------------------------------------\n \n ";
    
    return 0;
}