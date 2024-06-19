#include "fractalpainter.h"

FractalPainter::FractalPainter(QPair<double, double> _TopLeftAngle, QPair<double, double> _RectSize)
    : TopLeftAngle(_TopLeftAngle), RectSize(_RectSize)
{}

void FractalPainter::paint(QPainter *painter, QPaintEvent *event)
{
    double single_segment_x = RectSize.first / WindowWidth;
    double single_segment_y = RectSize.second / WindowHeight;

    QPen pen;

    for (quint32 x = 0; x < WindowWidth; ++x)
    {
        for (quint32 y = 0; y < WindowHeight; ++y)
        {
            double cartesian_x, cartesian_y;
            cartesian_x = TopLeftAngle.first + x * single_segment_x;
            cartesian_y = TopLeftAngle.second - y * single_segment_y;

            quint32 it_number = getIteration(ComplexNumber(cartesian_x, cartesian_y), iterations, INF);

            quint32 hue = int(255 * it_number / iterations);
            quint32 saturation = 255;
            quint32 value = (it_number < iterations) ? 255 : 0;
            pen.setColor(QColor::fromHsv(hue, saturation, value));
            painter->setPen(pen);
            painter->drawRect(x, y, 1, 1);
        }
    }
}

QPair<double, double> FractalPainter::getTopLeftAngle() const
{
    return TopLeftAngle;
}

void FractalPainter::setTopLeftAngle(const QPair<double, double> &newTopLeftAngle)
{
    TopLeftAngle = newTopLeftAngle;
}

QPair<double, double> FractalPainter::getRectSize() const
{
    return RectSize;
}

void FractalPainter::setRectSize(const QPair<double, double> &newRectSize)
{
    RectSize = newRectSize;
}
