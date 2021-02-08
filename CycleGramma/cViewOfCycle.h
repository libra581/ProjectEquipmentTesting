#ifndef CVIEWOFCYCLE_H
#define CVIEWOFCYCLE_H

#include <QGraphicsView>

class cViewOfCycle : public QGraphicsView
{
    Q_OBJECT

public:
    cViewOfCycle(QGraphicsScene* pScene, QWidget* pwgt = 0);
};

#endif // CVIEWOFCYCLE_H
