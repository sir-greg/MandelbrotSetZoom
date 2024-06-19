#ifndef FRACTALPAINTER_H
#define FRACTALPAINTER_H

#include <QWidget>
#include <QPainter>
#include <QtMath>
#include "complexnumber.h"
#include "GlobalVariables.h"

class FractalPainter
{
public:
    FractalPainter(QPair<double, double> _TopLeftAngle, QPair<double, double> _RectSize);

    void paint(QPainter* painter, QPaintEvent* event);

    QPair<double, double> getTopLeftAngle() const;
    void setTopLeftAngle(const QPair<double, double> &newTopLeftAngle);

    QPair<double, double> getRectSize() const;
    void setRectSize(const QPair<double, double> &newRectSize);

private:

    QPair<double, double> TopLeftAngle, RectSize;
    quint32 iterations = 160;
    double INF = 2;

};

#endif // FRACTALPAINTER_H
