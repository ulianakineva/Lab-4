#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H

#include <iostream>
#include <vector>
using namespace std;
class QuadraticEquation {
private:
    double a, b, c;

public:
    // Конструкторы
    QuadraticEquation();
    QuadraticEquation(double a, double b, double c);
    QuadraticEquation(const QuadraticEquation& other);

    // Геттеры и сеттеры
    double getA() const;
    double getB() const;
    double getC() const;
    void setA(double value);
    void setB(double value);
    void setC(double value);

    // Метод для вычисления корней квадратного уравнения
    vector<double> solve() const;

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const QuadraticEquation& equation);

    // Перегрузка унарных операторов ++ и --
    QuadraticEquation& operator++(); 
    QuadraticEquation operator++(int);
    QuadraticEquation& operator--();
    QuadraticEquation operator--(int);

    // Перегрузка операций приведения типов
    operator double() const; 
    explicit operator bool() const; 

    // Перегрузка бинарных операторов == и !=
    bool operator==(const QuadraticEquation& other) const;
    bool operator!=(const QuadraticEquation& other) const;
};

#endif // QUADRATICEQUATION_H

