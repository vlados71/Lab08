// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку (ітераційний спосіб)
// Варіант 5

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Підраховує кількість груп ",-" у рядку str
int Count(const char* str)
{
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ',' && str[i + 1] == '-')
            k++;
    return k;
}

// Замінює кожну групу ",-" на "*".
// Результат повертається і як значення функції, і через параметр str.
// Рядок лише скорочується, тому розміру str завжди достатньо.
char* Change(char* str)
{
    char* tmp = new char[strlen(str) + 1];
    size_t i = 0,  // поточна позиція у str
        n = 0;  // поточна позиція у tmp

    while (str[i] != '\0')
    {
        if (str[i] == ',' && str[i + 1] == '-')
        {
            tmp[n++] = '*';
            i += 2;
        }
        else
            tmp[n++] = str[i++];
    }
    tmp[n] = '\0';

    strcpy(str, tmp);
    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 101);

    int k = Count(str);
    if (k > 0)
        cout << "Groups ',-' found: yes" << endl;
    else
        cout << "Groups ',-' found: no" << endl;
    cout << "String contained " << k << " groups of ',-'" << endl;

    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}