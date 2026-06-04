#include <iostream>
using namespace std;
int main()
{
    int n1 = 1, n2 = 1000, i = n1;
    double sum = 0, res;

    while (i <= n2) {
        sum += i;
        i++;
    }
    int count = n2 - n1 + 1; // 1000 - 1 + 1 (між 1 і 1000 включно є 1000 чисел)
    res = sum / count;

    cout << "\nSum of all numbers from one to one thousand inclusive: " << sum << ", count of numbers: " << count << ". Arithmetic mean: " << res << "\n";
    
    return 0;
}