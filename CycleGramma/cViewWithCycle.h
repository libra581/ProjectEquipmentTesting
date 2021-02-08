#ifndef CVIEWWITHCYCLE_H
#define CVIEWWITHCYCLE_H

#include <QGraphicsView>

class cViewWithCycle : public QGraphicsView
{
    Q_OBJECT
public:
    cViewWithCycle(QWidget *parent = Q_NULLPTR);
    cViewWithCycle(QGraphicsScene* pScene, QWidget* pwgt = 0);
};

#endif // CVIEWWITHCYCLE_H
