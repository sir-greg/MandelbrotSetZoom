#include "specializedpainter.h"

SpecializedPainter::SpecializedPainter(FractalPainter* _painterClass, QWidget* _parent)
    : QOpenGLWidget(_parent), painterClass(_painterClass)
{
    setFixedSize(WindowWidth, WindowHeight);
    setAutoFillBackground(false);
    connect(this, &SpecializedPainter::changedPainterClass,
            this, [this]()
    {
        update();
    });
}

void SpecializedPainter::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painterClass->paint(&painter, event);
    painter.end();
}

void SpecializedPainter::setPainterClass(FractalPainter *newPainterClass)
{
    painterClass = newPainterClass;
    emit changedPainterClass();
}
