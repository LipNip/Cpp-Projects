#include <iostream>
#include <cmath> // sqrt()
using namespace std;

template <class T>
class Point3D {
    T x, y, z;
public:
    Point3D() : x(0), y(0), z(0) {}
    Point3D(T x, T y, T z) : x(x), y(y), z(z) {}

    void print() const {
        cout << "(" << x << ", " << y << ", " << z << ")\n";
    }

    friend double calculateDistance(const Point3D<T>& p1, const Point3D<T>& p2) {
        return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z));
    }
};

int main()
{
    Point3D<int> p1(1, 2, 3);
    Point3D<int> p2(4, 5, 6);
    cout << "Point 1: ";
    p1.print();
    cout << "Point 2: ";
    p2.print();

    cout << "Distance (p1, p2): " << calculateDistance(p1, p2);

    Point3D<double> p3(1.1, 2.2, 3.3);
    Point3D<double> p4(4.4, 5.5, 6.6);
    cout << "\n\nPoint 3: ";
    p3.print();
    cout << "Point 4: ";
    p4.print();

    cout << "Distance (p3, p4): " << calculateDistance(p3, p4);

    cout << "\n\n";
    return 0;
}