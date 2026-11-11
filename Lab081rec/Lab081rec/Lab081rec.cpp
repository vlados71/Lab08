// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку (рекурсивний спосіб)
// Варіант 5

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Рекурсивна функція для підрахунку груп ",-"
int Count(const char* str, int i)
{
    // Базовий випадок: якщо рядок занадто короткий або ми дійшли до кінця
    if (strlen(str) < 2 || str[i] == '\0' || str[i + 1] == '\0')
        return 0;

    // Рекурсивний крок
    if (str[i] == ',' && str[i + 1] == '-')
        return 1 + Count(str, i + 2); // пропускаємо знайдену пару
    else
        return Count(str, i + 1);     // перевіряємо з наступного символу
}

// Рекурсивна функція для заміни ",-" на "*"
// dest - вказівник на початок результуючого рядка
// str - вказівник на початковий рядок
// t - вказівник на поточну позицію запису в dest
// i - індекс поточного символу в str для читання
char* Change(char* dest, const char* str, char* t, int i)
{
    // Якщо є хоча б два символи для перевірки
    if (str[i] != '\0' && str[i + 1] != '\0')
    {
        if (str[i] == ',' && str[i + 1] == '-')
        {
            *t++ = '*';
            *t = '\0';
            return Change(dest, str, t, i + 2); // пропускаємо знайдену пару
        }
        else
        {
            *t++ = str[i];
            *t = '\0';
            return Change(dest, str, t, i + 1); // переходимо до наступного символу
        }
    }
    else
    {
        // Якщо залишився один останній символ (не пара), просто копіюємо його
        if (str[i] != '\0')
        {
            *t++ = str[i];
        }
        *t = '\0'; // Завершуємо рядок нуль-символом
        return dest;
    }
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 101);

    int k = Count(str, 0);
    if (k > 0)
        cout << "Groups ',-' found: yes" << endl;
    else
        cout << "Groups ',-' found: no" << endl;

    cout << "String contained " << k << " groups of ',-'" << endl;

    // Виділяємо пам'ять для результуючого рядка з запасом
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2;

    // Виклик рекурсивної функції. Передаємо dest1 і як початок, і як поточну позицію t.
    dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1; // Звільняємо пам'ять
    return 0;
}