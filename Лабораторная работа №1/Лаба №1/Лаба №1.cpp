#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Функция, которая принимает символ шестнадцатеричного числа и возвращает его десятичное значение
int hex_to_decimal(char hex_digit) {
    if (hex_digit >= '0' && hex_digit <= '9') {
        return hex_digit - '0';
    }
    else if (hex_digit >= 'A' && hex_digit <= 'F') {
        return hex_digit - 'A' + 10;
    }
    else if (hex_digit >= 'a' && hex_digit <= 'f') {
        return hex_digit - 'a' + 10;
    }
    else {
        return -1; // Если символ не является шестнадцатеричным числом, вернуть -1
    }
}

// Функция, которая принимает шестнадцатеричное число в виде строки и возвращает его десятичное значение
double hex_to_decimal(string hex_number) {
    int decimal_integer_part = 0;
    for (int i = hex_number.length() - 1, power = 0; i >= 0; i--, power++) {
        int decimal_digit = hex_to_decimal(hex_number[i]);
        if (decimal_digit == -1) {
            return -1; // Если символ не является шестнадцатеричным числом, вернуть -1
        }
        decimal_integer_part += decimal_digit * pow(16, power);
    }
    return decimal_integer_part;
}

// Функция, которая принимает шестнадцатеричную дробь в виде строки и возвращает её десятичное значение
double hex_fraction_to_decimal(string hex_fraction) {
    double decimal_fraction = 0;
    double base = 1;
    for (int i = 0; i < hex_fraction.length(); i++) {
        int decimal_digit = hex_to_decimal(hex_fraction[i]);
        if (decimal_digit == -1) {
            return -1; // Если символ не является шестнадцатеричным числом, вернуть -1
        }
        decimal_fraction += decimal_digit * (1.0 / (16 * base));
        base *= 16;
    }
    return decimal_fraction;
}
//Эта функция принимает шестнадцатеричную дробь в виде строки hex_fraction и возвращает ее десятичное значение
//Переменная decimal_fraction инициализируется нулем.Затем происходит цикл, который проходит по всем символам в строке hex_fraction.
//Для каждого символа функция вызывает функцию hex_to_decimal(), которая преобразует символ шестнадцатеричного числа в его десятичное значение.
//Полученное десятичное значение умножается на соответствующую степень 16 в знаменателе дроби 
//(это реализуется переменной base, которая в начале равна 1, а затем умножается на 16 на каждом шаге цикла).
//Затем десятичное значение дробной части шестнадцатеричного числа складывается с новым значением, полученным на текущем шаге цикла. 
//После окончания цикла, переменная decimal_fraction содержит десятичное значение дробной части шестнадцатеричного числа.


int main() {
    setlocale(LC_ALL, "Russian");
    string hex_number;
    cout << "Введите шестнадцатеричное число: ";
    cin >> hex_number;

    // Найти индекс точки в шестнадцатеричном числе
    int decimal_point_index = hex_number.find('.');
    if (decimal_point_index == string::npos) {
        // Если точка не найдена в введенном числе, значит это целое число
        double decimal_number = hex_to_decimal(hex_number);
        if (decimal_number == -1) {
            cout << "Ошибка: введено некорректное число!" << endl;
        }
        else {
            cout << "Десятичное число: " << decimal_number << endl;
        }
    }
    else {
        // Если точка найдена, значит это дробное число   
        // Разделить шестнадцатеричное число на целую и дробную части
        string hex_integer_part = hex_number.substr(0, decimal_point_index);
        string hex_fraction_part = hex_number.substr(decimal_point_index + 1);

        // Конвертировать целую и дробную части в десятичные числа
        double decimal_integer_part = hex_to_decimal(hex_integer_part);
        double decimal_fraction_part = hex_fraction_to_decimal(hex_fraction_part);

        if (decimal_integer_part == -1 || decimal_fraction_part == -1) {
            cout << "Ошибка: введено некорректное число!" << endl;
        }
        else {
            cout << "Десятичное число: " << decimal_integer_part + decimal_fraction_part << endl;
        }
    }

    return 0;
}

