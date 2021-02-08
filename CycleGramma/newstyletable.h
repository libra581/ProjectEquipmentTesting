#ifndef NEWSTYLETABLE_H
#define NEWSTYLETABLE_H

#include <QCommonStyle>
#include <QtGui>

class myStyle : public QCommonStyle
{
    Q_OBJECT
public:
    explicit myStyle();

    void drawControl(ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const;
    void drawItemText(QPainter *painter, const QRect &rect, int flags, const QPalette &pal, bool enabled, const QString &text, QPalette::ColorRole textRole) const;
    void drawPrimitive(PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const;

signals:

public slots:

};

#endif // NEWSTYLETABLE_H
