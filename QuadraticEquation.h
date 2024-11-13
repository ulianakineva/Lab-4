#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H

#include <iostream>
#include <vector>
using namespace std;
class QuadraticEquation {
private:
    double a, b, c;

public:
    // ������������
    QuadraticEquation();
    QuadraticEquation(double a, double b, double c);
    QuadraticEquation(const QuadraticEquation& other);

    // ������� � �������
    double getA() const;
    double getB() const;
    double getC() const;
    void setA(double value);
    void setB(double value);
    void setC(double value);

    // ����� ��� ���������� ������ ����������� ���������
    vector<double> solve() const;

    // ���������� ��������� ������
    friend ostream& operator<<(ostream& os, const QuadraticEquation& equation);

    // ���������� ������� ���������� ++ � --
    QuadraticEquation& operator++(); 
    QuadraticEquation operator++(int);
    QuadraticEquation& operator--();
    QuadraticEquation operator--(int);

    // ���������� �������� ���������� �����
    operator double() const; 
    explicit operator bool() const; 

    // ���������� �������� ���������� == � !=
    bool operator==(const QuadraticEquation& other) const;
    bool operator!=(const QuadraticEquation& other) const;
};

#endif // QUADRATICEQUATION_H

