#include <iostream>
using namespace std;
int main()
{
    double size;
    cout << "The size of one movie (MB): ";
    cin >> size;

    double all_size = 3 * size;
    double count = all_size / 1.44; //// Точна кількість дискет
    int disksNeeded = count; // Відкидаємо дробову частину
    disksNeeded = disksNeeded + (count > disksNeeded); //Вираз (count > disksNeeded) поверне 1 якщо є дробовий залишок і 0 якщо немає

    cout << "\n" << "To record three movies (the size of one movie: " << size << " MB, three: " << all_size << " MB) you need: " << disksNeeded << " floppy disks. Capacity of one is 1.44 MB." << "\n";
    return 0;
}