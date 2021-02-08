#include "cViewWithCycle.h"

cViewWithCycle::cViewWithCycle(QWidget *parent):QGraphicsView(parent)
{
    setStyleSheet("background:  #413d51;");

}

cViewWithCycle::cViewWithCycle(QGraphicsScene *pScene, QWidget *pwgt):QGraphicsView(pScene,pwgt)
{

}

