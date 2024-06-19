#include "drawerholderwidget.h"

DrawerHolderWidget::DrawerHolderWidget(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("FRACTALS");
    this->resize(WindowWidth, WindowHeight);
    SpecFractalPainter = new SpecializedPainter(&painterClass, this);
    SpecFractalPainter->setGeometry(0, 0, WindowWidth, WindowHeight);
}


void DrawerHolderWidget::mousePressEvent(QMouseEvent *event)
{
    origin = event->pos();
    if (!rubberBand)
        rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    rubberBand->setGeometry(QRect(origin, QSize()));
    rubberBand->show();
}

void DrawerHolderWidget::mouseMoveEvent(QMouseEvent *event)
{
    rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
}

void DrawerHolderWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QPair<double, double> newTopLeftAngle, newRectSize;
    newRectSize = {RectSize.first * rubberBand->width() / WindowWidth,
                   RectSize.second * rubberBand->height() / WindowHeight};
    newTopLeftAngle = {TopLeftAngle.first + (rubberBand->x()) * RectSize.first / WindowWidth,
                       TopLeftAngle.second - (rubberBand->y()) * RectSize.second / WindowHeight};
    if (newRectSize.second * WindowWidth / WindowHeight > newRectSize.first)
        newRectSize.first = newRectSize.second * WindowWidth / WindowHeight;
    else
        newRectSize.second = newRectSize.first * WindowHeight / WindowWidth;
    //qDebug() << newTopLeftAngle.first << " " << newTopLeftAngle.second << " " << newRectSize.first << " " << newRectSize.second << "\n";
    TopLeftAngle = newTopLeftAngle;
    RectSize = newRectSize;
    painterClass.setRectSize(RectSize);
    painterClass.setTopLeftAngle(TopLeftAngle);
    SpecFractalPainter->setPainterClass(&painterClass);
    rubberBand->hide();
}
