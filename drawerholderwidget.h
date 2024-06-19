#ifndef DRAWERHOLDERWIDGET_H
#define DRAWERHOLDERWIDGET_H

#include <QRubberBand>
#include <QWidget>
#include <QMouseEvent>
#include <QGridLayout>
#include "GlobalVariables.h"
#include "specializedpainter.h"

class DrawerHolderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawerHolderWidget(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

    void changedCoords();

private:
    QPoint origin;
    QRubberBand* rubberBand = nullptr;

    QPair<double, double> TopLeftAngle = {-3, 3};
    QPair<double, double> RectSize = {0.8 * 8, 0.6 * 8};

    FractalPainter painterClass = FractalPainter({-3, 3}, {0.8 * 8, 0.6 * 8});

    QGridLayout* layout = nullptr;
    SpecializedPainter* SpecFractalPainter = nullptr;
};

#endif // DRAWERHOLDERWIDGET_H
