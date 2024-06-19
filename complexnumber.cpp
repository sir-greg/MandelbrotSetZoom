#include "complexnumber.h"


ComplexNumber::ComplexNumber() : _real(0), _imaginary(0) {}

ComplexNumber::ComplexNumber(double real, double imaginary) : _real(real), _imaginary(imaginary) {}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &other) const
{
    return ComplexNumber(real() + other.real(), imaginary() + other.imaginary());
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &other) const
{
    return ComplexNumber(real() * other.real() - imaginary() * other.imaginary(),
                         real() * other.imaginary() + imaginary() * other.real());
}

double ComplexNumber::imaginary() const
{
    return _imaginary;
}

void ComplexNumber::setImaginary(double newImaginary)
{
    _imaginary = newImaginary;
}

double ComplexNumber::real() const
{
    return _real;
}

void ComplexNumber::setReal(double newReal)
{
    _real = newReal;
}

double abs(const ComplexNumber &other)
{
    return (other.real() * other.real() + other.imaginary() * other.imaginary());
}

double getIteration(const ComplexNumber point, quint32 iterations, double INF)
{
    if (iterations == 0)
        return 0;
    quint32 times;
    ComplexNumber current = 0;
    for (times = 0; times < iterations; ++times)
    {
        if (abs(current) < INF * INF)
        {
            current = current * current + point;
        }
        else
        {
            if (current.imaginary() == 0 && current.real() == 0)
                return times;
            else
                return times + 1 - qLn(qLn(abs(current)));
        }
    }
    return times;
}
