#include <iostream>
using namespace std;
int main()
{
    int num, n1, n2, n3, n4, n5, n6, s1_2, s3_4, s5_6;
    cout << "Enter a six-digit number: ";
    cin >> num;
    
    n1 = num / 100000;
    n2 = (num / 10000) % 10;  
    s1_2 = n1 + n2;
    n3 = (num / 1000) % 10;    
    n4 = (num / 100) % 10;
    s3_4 = n3 + n4;
    n5 = (num / 10) % 10;  
    n6 = num % 10;
    s5_6 = n5 + n6;
    if(n1 <= 9 && n1 > 0){
        if (s1_2 == s3_4 && s3_4 == s5_6) {
            cout << "\nThis number is lucky!\n";
        }
        else {
            cout << "\nThis number is not lucky!\n";
        }
    }
    else {
        cout << "\nIt must be a SIX-DIGIT number!\n";
    }

    return 0;
}