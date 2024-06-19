#ifndef SPECIALIZEDPAINTER_H
#define SPECIALIZEDPAINTER_H

#include <QOpenGLWidget>
#include "fractalpainter.h"
#include <QTimer>

class SpecializedPainter : public QOpenGLWidget
{
    Q_OBJECT
public:
    SpecializedPainter(FractalPainter* _painterClass, QWidget* _parent);

    void setPainterClass(FractalPainter *newPainterClass);

signals:

    void changedPainterClass();

protected:

    void paintEvent(QPaintEvent* event) override;

private:

    FractalPainter* painterClass;
};

#endif // SPECIALIZEDPAINTER_H
