#include <iostream>
#include <windows.h>
using namespace std;

void print_for_arr(int num, const char* str[]) {
    cout << str[num];
}

const char* true_ansver(int answer, const char* str[]) {
    answer = answer + 1;
    return str[answer];
}

bool isTrue(char version, int answer, const char* str[]) {
    answer = answer + 1;
    const char* correct_answer = str[answer];
    if (correct_answer[0] == version) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);          // для укр мови
    
    const char* questions[] = {
    "Яка компанія розробила операційну систему Android?",
    "Що означає абревіатура CPU?",
    "Яка компанія створила процесори Ryzen?",
    "Який роз'єм найчастіше використовується для сучасних дротових підключень?",
    "Що означає абревіатура SSD?",
    "Яка операційна система є відкритою та базується на ядрі Linux?",
    "Яка компанія розробила відеокарти GeForce RTX?",
    "Що використовується для зберігання даних у комп'ютері?",
    "Яка мова програмування часто використовується для створення вебсторінок?",
    "Що таке Wi-Fi?"
    };

    const char* answers[] = {
    "A: Google   B: Microsoft   C: Apple   D: Samsung", "A",
    "A: Computer Personal Unit   B: Central Processing Unit   C: Central Program Utility   D: Computer Processing Unit", "B",
    "A: Intel   B: AMD   C: NVIDIA   D: Qualcomm", "B",
    "A: VGA   B: PS/2   C: DVI   D: USB-C", "D",
    "A: System Storage Device   B: Secure Storage Disk   C: Solid State Drive   D: Solid System Drive", "C",
    "A: Linux   B: Windows   C: macOS   D: DOS", "A",
    "A: AMD   B: Intel   C: Apple   D: NVIDIA", "D",
    "A: RAM   B: SSD   C: CPU   D: GPU", "B",
    "A: C++   B: Python   C: HTML   D: Java", "C",
    "A: Відеокарта   B: Операційна система   C: Процесор   D: Бездротова мережа", "D"
    };

    srand(time(NULL));

    int random_question = rand() % 9; //[0;8]
    int answer = random_question * 2;
    
    const char* correct_answer = true_ansver(answer, answers);

    print_for_arr(random_question, questions);
    cout << "\n\n";
    print_for_arr(answer, answers);

    char version;
    cout << "\n\nВиберіть варіант: ";
    cin >> version;

    cout << isTrue(version, answer, questions);

    cout << "\n\n";
    return 0;
}