#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <QtGlobal>
#include <QtMath>

class ComplexNumber
{
private:

    double _real, _imaginary;

public:
    ComplexNumber();

    ComplexNumber(double real, double imaginary = 0);

    ComplexNumber operator+(const ComplexNumber& other) const;

    ComplexNumber operator*(const ComplexNumber& other) const;

    double real() const;
    void setReal(double newReal);
    double imaginary() const;
    void setImaginary(double newImaginary);
};

double abs(const ComplexNumber& other);

double getIteration(const ComplexNumber point, quint32 iterations, double INF = 1e18);

#endif // COMPLEXNUMBER_H
