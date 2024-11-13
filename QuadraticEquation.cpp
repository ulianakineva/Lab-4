#include "QuadraticEquation.h"
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Конструктор по умолчанию
QuadraticEquation::QuadraticEquation() : a(1), b(0), c(0) {}

// Конструктор с параметрами
QuadraticEquation::QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

// Конструктор копирования
QuadraticEquation::QuadraticEquation(const QuadraticEquation& other) : a(other.a), b(other.b), c(other.c) {}

// Геттеры
double QuadraticEquation::getA() const { return a; }
double QuadraticEquation::getB() const { return b; }
double QuadraticEquation::getC() const { return c; }

// Сеттеры
void QuadraticEquation::setA(double value) { a = value; }
void QuadraticEquation::setB(double value) { b = value; }
void QuadraticEquation::setC(double value) { c = value; }

// Метод для вычисления корней квадратного уравнения
vector<double> QuadraticEquation::solve() const {
    vector<double> roots;

    if (a == 0) {
        cout << "Ошибка: коэффициент a не может быть равен 0 для квадратного уравнения." << endl;
        return roots;
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        roots.push_back(root1);
        roots.push_back(root2);
    }
    else if (discriminant == 0) {
        double root = -b / (2 * a);
        roots.push_back(root);
    }
    else {
        cout << "Уравнение не имеет действительных корней." << endl;
    }

    return roots;
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& os, const QuadraticEquation& equation) {
    os << "Quadratic Equation: " << equation.a << "x^2 + " << equation.b << "x + " << equation.c << " = 0";
    return os;
}

// Перегрузка унарного оператора ++ (префиксный)
QuadraticEquation& QuadraticEquation::operator++() {
    // Создаём новый объект с увеличенными коэффициентами
    QuadraticEquation temp(a + 1, b + 1, c + 1);
    // Возвращаем новый объект с увеличенными коэффициентами
    *this = temp;
    return *this;
}

// Перегрузка унарного оператора ++ (постфиксный)
QuadraticEquation QuadraticEquation::operator++(int) {
    QuadraticEquation temp = *this;  // Сохраняем старый объект
    *this = QuadraticEquation(a + 1, b + 1, c + 1);  // Создаём новый объект с увеличенными коэффициентами
    return temp;  // Возвращаем старое состояние объекта
}

// Перегрузка унарного оператора -- (префиксный)
QuadraticEquation& QuadraticEquation::operator--() {
    // Создаём новый объект с уменьшенными коэффициентами
    QuadraticEquation temp(a - 1, b - 1, c - 1);
    // Возвращаем новый объект с уменьшенными коэффициентами
    *this = temp;
    return *this;
}

// Перегрузка унарного оператора -- (постфиксный)
QuadraticEquation QuadraticEquation::operator--(int) {
    QuadraticEquation temp = *this;  // Сохраняем старый объект
    *this = QuadraticEquation(a - 1, b - 1, c - 1);  // Создаём новый объект с уменьшенными коэффициентами
    return temp;  // Возвращаем старое состояние объекта
}

// Приведение к типу double (дискриминант)
QuadraticEquation::operator double() const {
    return b * b - 4 * a * c;
}

// Приведение к типу bool (наличие корней)
QuadraticEquation::operator bool() const {
    double discriminant = b * b - 4 * a * c;
    if (discriminant >= 0)
        return true;
    else
        return false;

}

// Перегрузка оператора ==
bool QuadraticEquation::operator==(const QuadraticEquation& other) const {
    return a == other.a && b == other.b && c == other.c;
}

// Перегрузка оператора !=
bool QuadraticEquation::operator!=(const QuadraticEquation& other) const {
    return !(*this == other);
}

