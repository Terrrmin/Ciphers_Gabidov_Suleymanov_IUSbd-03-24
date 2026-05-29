#include <iostream>     // Библиотека ввода и вывода
#include <vector>       // Библиотека для vector
#include <string>       // Библиотека для строк
#include <algorithm>    // Библиотека для transform

using namespace std;    // Используем пространство имен std

// Алфавит без буквы J
string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

// Функция создания таблицы Плейфера
vector<vector<char>> createTable(string key)
{
    string s = ""; // Строка для символов таблицы

    // Перевод ключа в верхний регистр
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    // Замена J на I
    for (char &c : key)
        if (c == 'J')
            c = 'I';

    // Добавление букв ключа без повторений
    for (char c : key)
        if (s.find(c) == string::npos && alphabet.find(c) != string::npos)
            s += c;

    // Добавление остальных букв алфавита
    for (char c : alphabet)
        if (s.find(c) == string::npos)
            s += c;

    // Создание таблицы 5x5
    vector<vector<char>> table(5, vector<char>(5));

    int k = 0; // Индекс символа

    // Заполнение таблицы
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            table[i][j] = s[k++];

    return table; // Возврат таблицы
}

// Функция поиска координат буквы
pair<int, int> findPos(vector<vector<char>> &t, char c)
{
    // Проход по таблице
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            // Если буква найдена
            if (t[i][j] == c)
                return {i, j};

    return {-1, -1}; // Если символ не найден
}

// Подготовка текста
string prepare(string text)
{
    string r = ""; // Подготовленный текст

    // Перевод текста в верхний регистр
    transform(text.begin(), text.end(), text.begin(), ::toupper);

    // Обработка текста
    for (char c : text)
    {
        // Замена J на I
        if (c == 'J')
            c = 'I';

        // Добавление только букв алфавита
        if (alphabet.find(c) != string::npos)
            r += c;
    }

    // Если длина нечетная
    if (r.length() % 2 != 0)
        r += 'X'; // Добавляем X

    return r; // Возврат текста
}

// Функция шифрования
string encrypt(string text, vector<vector<char>> &t)
{
    string res = ""; // Результат шифрования

    // Обработка текста парами
    for (int i = 0; i < text.length(); i += 2)
    {
        // Поиск координат первой буквы
        auto p1 = findPos(t, text[i]);

        // Поиск координат второй буквы
        auto p2 = findPos(t, text[i + 1]);

        int r1 = p1.first;   // Строка первой буквы
        int c1 = p1.second;  // Столбец первой буквы

        int r2 = p2.first;   // Строка второй буквы
        int c2 = p2.second;  // Столбец второй буквы

        // Если буквы в одной строке
        if (r1 == r2)
        {
            // Берем символ справа
            res += t[r1][(c1 + 1) % 5];
            res += t[r2][(c2 + 1) % 5];
        }

        // Если буквы в одном столбце
        else if (c1 == c2)
        {
            // Берем символ снизу
            res += t[(r1 + 1) % 5][c1];
            res += t[(r2 + 1) % 5][c2];
        }

        // Если буквы образуют прямоугольник
        else
        {
            // Меняем столбцы
            res += t[r1][c2];
            res += t[r2][c1];
        }
    }

    return res; // Возврат шифра
}

// Главная функция
int main()
{
    string key;   // Ключ
    string text;  // Исходный текст

    // Ввод ключа
    cout << "Key: ";
    cin >> key;

    cin.ignore(); // Очистка буфера

    // Ввод текста
    cout << "Text: ";
    getline(cin, text);

    // Создание таблицы
    auto table = createTable(key);

    // Подготовка текста
    string prepared = prepare(text);

    // Вывод шифра
    cout << "\nEncrypted text: " << encrypt(prepared, table);

    return 0; // Завершение программы
}
