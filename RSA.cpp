#include <iostream> 
#include <cmath>    

using namespace std; // что бы не писать std везде 

// эта функция ищет наибольший общий делитель 
int gcd(int a, int b) {
    while (b != 0) {       // пока второе число не ноль
        int temp = b;      // сохраняем второе
        b = a % b;         // заменяем b на остаток от деления
        a = temp;          // а на место а ставим старое b
    }
    return a; // возвращаем наибольший делитель
}

// быстрое возведение в степень по модулю
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;          // тут будет ответ
    base = base % mod;             // сразу уменьшаем чтоб не переполнить

    while (exp > 0) {              
        if (exp % 2 == 1)          // если бит единичка
            result = (result * base) % mod;
        base = (base * base) % mod; // возводим в квадрат
        exp /= 2;                   // сдвигаем биты вправо
    }
    return result;
}

int main() {
    int p, q; // два простых числа

    cout << "Enter p : "; cin >> p;
    cout << "Enter q : "; cin >> q;

    // вычисляем модуль - это часть открытого ключа
    int n = p * q;

    // функция эйлера - сколько чисел взаимно простых с n
    int phi = (p - 1) * (q - 1);

    cout << "n = " << n << endl;
    cout << "phi = " << phi << endl;

    // теперь выбираем открытую экспоненту e
    int e;
    cout << "Enter e: ";
    cin >> e;

    // проверяем что e подходит по правилам RSA
    if (e <= 1 || e >= phi || gcd(e, phi) != 1) {
        cout << "e is not valid! It must be coprime with phi." << endl;
        return 1;
    }

    // теперь находим закрытый ключ d (обратный к e по модулю phi)
    int d = 1;
    // перебираем пока не найдём подходящий
    while ((d * e) % phi != 1) {
        d++;
        if (d > 1000000) { // защита от бесконечного цикла
            cout << "Can't find d! Try other e." << endl;
            return 1;
        }
    }

    cout << "Public key: (n=" << n << ", e=" << e << ")" << endl;
    cout << "Private key: (n=" << n << ", d=" << d << ")" << endl;

    // теперь само сообщение
    int message;
    cout << "Enter message (0 to " << n - 1 << "): ";
    cin >> message;

    // проверка что сообщение не больше модуля
    if (message < 0 || message >= n) {
        cout << "Message must be less than n!" << endl;
        return 1;
    }

    // ШИФРОВАНИЕ: c = m^e mod n
    int encrypted = modPow(message, e, n);
    cout << "Encrypted: " << encrypted << endl;

    // РАСШИФРОВАНИЕ: m = c^d mod n
    int decrypted = modPow(encrypted, d, n);
    cout << "Decrypted: " << decrypted << endl;

    // проверяем что всё работает
    if (message == decrypted) {
        cout << "RSA works correctly!" << endl;
    }
    else {
        cout << "Something went wrong!" << endl;
    }

    return 0; // конец программы
}
