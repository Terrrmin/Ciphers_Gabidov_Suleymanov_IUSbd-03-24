#include <iostream> // Библиотека ввода и вывода
#include <string>   // Библиотека для работы со строками

using namespace std; // Пространство имен std

int main() // Главная функция программы
{
    string text;       // Переменная для хранения исходного текста
    string key;        // Переменная для хранения ключевого слова
    string encrypted;  // Переменная для хранения зашифрованного текста

    cout << "Text: "; // вводим текст
    cin >> text;               // Считываем текст

    cout << "Key: "; // вводим ключ
    cin >> key;               // Считываем ключ

    for (int i = 0; i < text.length(); i++) // Цикл по каждому символу текста
    {
        if (isupper(text[i])) // Проверяем, является ли буква заглавной
        {
            int textValue = text[i] - 'A'; // Преобразуем букву текста в число (A=0)

            int keyValue = toupper(key[i % key.length()]) - 'A'; // Берём букву ключа и тоже делаем число

            char encryptedChar =
                (textValue + keyValue) % 26 + 'A'; // Шифруем по формуле Виженера

            encrypted += encryptedChar; // Добавляем зашифрованный символ в результат
        }
        else if (islower(text[i])) // Проверяем, является ли буква строчной
        {
            int textValue = text[i] - 'a'; // Преобразуем строчную букву в число (a=0)

            int keyValue = tolower(key[i % key.length()]) - 'a'; // Берём букву ключа в нижнем регистре

            char encryptedChar =
                (textValue + keyValue) % 26 + 'a'; // Шифруем строчную букву

            encrypted += encryptedChar; // Добавляем результат в строку
        }
        else // Если символ не буква
        {
            encrypted += text[i]; // Добавляем этот символ
        }
    }

    cout << "Encrypted text: "; // Выводим сообщение
    cout << encrypted << endl;       // Выводим результат

    return 0; // Завершаем программу
}
