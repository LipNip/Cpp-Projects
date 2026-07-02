#include <iostream>
#include <cmath>    //sqrt() і pow()
using namespace std;

struct Point {
    double x, y;
};

void set_Point(Point& p) {
    cout << "Enter x: ";
    cin >> p.x;
    cout << "Enter y: ";
    cin >> p.y;
}

double distance(Point a, Point b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

int main()
{
    Point a, b;
    cout << "Point A\n";
    set_Point(a);
    cout << "Point B\n";
    set_Point(b);
    cout << "\nDistance: " << distance(a, b);
    
    cout << "\n\n";
    return 0;
}