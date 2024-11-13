#include <iostream>
#include "QuadraticEquation.h"
using namespace std;

void Menu() {
    cout << "\nВыберите действие:\n";
    cout << "1. Вывести уравнение\n";
    cout << "2. Увеличить коэффициенты (++ префикс)\n";
    cout << "3. Увеличить коэффициенты (++ постфикс)\n";
    cout << "4. Уменьшить коэффициенты (-- префикс)\n";
    cout << "5. Уменьшить коэффициенты (-- постфикс)\n";
    cout << "6. Вычислить дискриминант (приведение к double)\n";
    cout << "7. Проверить наличие действительных корней (приведение к bool)\n";
    cout << "8. Сравнить с другим уравнением (оператор ==)\n";
    cout << "9. Проверить неравенство с другим уравнением (оператор !=)\n";
    cout << "10. Демонстрация конструкторов\n";
    cout << "0. Выход\n";
    cout << "Ваш выбор: ";
}

bool isValidInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка ввода! Коэффициенты должны быть числами.\n";
        return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, c;

    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    cin >> a >> b >> c;

    if (!isValidInput()) {
        return 1;
    }

    if (a == 0) {
        cout << "Ошибка: коэффициент a не может быть равен 0 для квадратного уравнения." << endl;
        return 1;
    }

    // Создаем объект уравнения
    QuadraticEquation equation(a, b, c);
    int choice;

    do {
        Menu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка! Введите корректное число для выбора действия.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Уравнение: " << equation << endl;
            break;

        case 2:
            ++equation;
            cout << "После префиксного ++: " << equation << endl;
            break;

        case 3:
            equation++;
            cout << "После постфиксного ++: " << equation << endl;
            break;

        case 4:
            --equation;
            cout << "После префиксного --: " << equation << endl;
            break;

        case 5:
            equation--;
            cout << "После постфиксного --: " << equation << endl;
            break;

        case 6: {
            double discriminant = equation;
            cout << "Дискриминант уравнения (приведение к double): " << discriminant << endl;
            break;
        }

        case 7:
            if (static_cast<bool>(equation)) {
                std::cout << "Уравнение имеет действительные корни: true" << std::endl;
            }
            else {
                std::cout << "Уравнение не имеет действительных корней: false" << std::endl;
            }
            break;

        case 8: {
            double a2, b2, c2;
            cout << "Введите коэффициенты для второго уравнения (a2, b2, c2): ";
            cin >> a2 >> b2 >> c2;

            if (!isValidInput()) {
                return 1;
            }

            if (a2 == 0) {
                cout << "Ошибка: коэффициент a не может быть равен 0 для квадратного уравнения." << endl;
                return 1;
            }

            QuadraticEquation equation2(a2, b2, c2);

            if (equation == equation2) {
                cout << "Уравнения равны." << endl;
            }
            else {
                cout << "Уравнения не равны." << endl;
            }
            break;
        }

        case 9: {
            double a2, b2, c2;
            cout << "Введите коэффициенты для второго уравнения (a2, b2, c2): ";
            cin >> a2 >> b2 >> c2;

            if (!isValidInput()) {
                return 1;
            }

            if (a2 == 0) {
                cout << "Ошибка: коэффициент a не может быть равен 0 для квадратного уравнения." << endl;
                return 1;
            }

            QuadraticEquation equation2(a2, b2, c2);

            if (equation != equation2) {
                cout << "Уравнения не равны." << endl;
            }
            else {
                cout << "Уравнения равны." << endl;
            }
            break;
        }

        case 10: {
            // Демонстрация конструкторов
            cout << "Демонстрация конструкторов:\n";

            // Конструктор по умолчанию
            QuadraticEquation defaultEq;
            cout << "Конструктор по умолчанию: " << defaultEq << endl;

            // Конструктор с параметрами
            QuadraticEquation paramEq(1, -2, 1);
            cout << "Конструктор с параметрами (1, -2, 1): " << paramEq << endl;

            // Конструктор копирования
            QuadraticEquation copyEq(paramEq);
            cout << "Конструктор копирования: " << copyEq << endl;

            break;
        }

        case 0:
            cout << "Выход из программы." << endl;
            break;

        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
