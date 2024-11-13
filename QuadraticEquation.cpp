#include "QuadraticEquation.h"
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// ����������� �� ���������
QuadraticEquation::QuadraticEquation() : a(1), b(0), c(0) {}

// ����������� � �����������
QuadraticEquation::QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

// ����������� �����������
QuadraticEquation::QuadraticEquation(const QuadraticEquation& other) : a(other.a), b(other.b), c(other.c) {}

// �������
double QuadraticEquation::getA() const { return a; }
double QuadraticEquation::getB() const { return b; }
double QuadraticEquation::getC() const { return c; }

// �������
void QuadraticEquation::setA(double value) { a = value; }
void QuadraticEquation::setB(double value) { b = value; }
void QuadraticEquation::setC(double value) { c = value; }

// ����� ��� ���������� ������ ����������� ���������
vector<double> QuadraticEquation::solve() const {
    vector<double> roots;

    if (a == 0) {
        cout << "������: ����������� a �� ����� ���� ����� 0 ��� ����������� ���������." << endl;
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
        cout << "��������� �� ����� �������������� ������." << endl;
    }

    return roots;
}

// ���������� ��������� ������
ostream& operator<<(ostream& os, const QuadraticEquation& equation) {
    os << "Quadratic Equation: " << equation.a << "x^2 + " << equation.b << "x + " << equation.c << " = 0";
    return os;
}

// ���������� �������� ��������� ++ (����������)
QuadraticEquation& QuadraticEquation::operator++() {
    // ������ ����� ������ � ������������ ��������������
    QuadraticEquation temp(a + 1, b + 1, c + 1);
    // ���������� ����� ������ � ������������ ��������������
    *this = temp;
    return *this;
}

// ���������� �������� ��������� ++ (�����������)
QuadraticEquation QuadraticEquation::operator++(int) {
    QuadraticEquation temp = *this;  // ��������� ������ ������
    *this = QuadraticEquation(a + 1, b + 1, c + 1);  // ������ ����� ������ � ������������ ��������������
    return temp;  // ���������� ������ ��������� �������
}

// ���������� �������� ��������� -- (����������)
QuadraticEquation& QuadraticEquation::operator--() {
    // ������ ����� ������ � ������������ ��������������
    QuadraticEquation temp(a - 1, b - 1, c - 1);
    // ���������� ����� ������ � ������������ ��������������
    *this = temp;
    return *this;
}

// ���������� �������� ��������� -- (�����������)
QuadraticEquation QuadraticEquation::operator--(int) {
    QuadraticEquation temp = *this;  // ��������� ������ ������
    *this = QuadraticEquation(a - 1, b - 1, c - 1);  // ������ ����� ������ � ������������ ��������������
    return temp;  // ���������� ������ ��������� �������
}

// ���������� � ���� double (������������)
QuadraticEquation::operator double() const {
    return b * b - 4 * a * c;
}

// ���������� � ���� bool (������� ������)
QuadraticEquation::operator bool() const {
    double discriminant = b * b - 4 * a * c;
    if (discriminant >= 0)
        return true;
    else
        return false;

}

// ���������� ��������� ==
bool QuadraticEquation::operator==(const QuadraticEquation& other) const {
    return a == other.a && b == other.b && c == other.c;
}

// ���������� ��������� !=
bool QuadraticEquation::operator!=(const QuadraticEquation& other) const {
    return !(*this == other);
}

