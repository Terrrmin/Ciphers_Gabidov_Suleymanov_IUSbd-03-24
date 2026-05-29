#include <iostream> // Подключение библиотеки для ввода и вывода
#include <string>   // Подключение библиотеки для работы со строками

using namespace std; // Использование стандартного пространства имён

// Функция шифрования
string encrypt(string text, int key) {

    // Проходим по каждому символу строки
    for (int i = 0; i < text.length(); i++) {

        // Проверяем, является ли буква строчной
        if (text[i] >= 'a' && text[i] <= 'z') {

            // Сдвигаем букву по алфавиту
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        }

        // Проверяем, является ли буква заглавной
        else if (text[i] >= 'A' && text[i] <= 'Z') {

            // Сдвигаем заглавную букву
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
    }

    // Возвращаем зашифрованный текст
    return text;
}

// Функция расшифровки
string decrypt(string text, int key) {

    // Расшифровка выполняется обратным сдвигом
    return encrypt(text, 26 - key);
}

// Главная функция программы
int main() {

    string text; // Переменная для хранения текста
    int key;   // Переменная для хранения сдвига

    // Просим ввести текст
    cout << "Text: ";

    // Считываем строку
    getline(cin, text);

    // Просим ввести ключ
    cout << "Key: ";

    // Считываем число
    cin >> key;

    // Шифруем текст
    string encrypted = encrypt(text, key);

    // Выводим зашифрованный текст
    cout << "Encrypted: " << encrypted << endl;

    // Выводим расшифрованный текст
    cout << "Decrypted: " << decrypt(encrypted, key) << endl;

    // Завершаем программу
    return 0;
}
