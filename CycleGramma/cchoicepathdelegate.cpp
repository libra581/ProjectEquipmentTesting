#include "cChoicePathDelegate.h"

cChoicePathDelegate::cChoicePathDelegate (QObject *parent)
 :QStyledItemDelegate(parent)
{

}

QWidget *cChoicePathDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                           const QModelIndex &index) const
{
}

void cChoicePathDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
}

void cChoicePathDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                       const QModelIndex &index) const
{
}

void cChoicePathDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);

}

void cChoicePathDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
   // painter->begin(option);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setBrush(QBrush(QColor("#cc91a8")));
    painter->setPen(QColor("#cc91a8"));
    painter->drawRect(option.rect);
  //  painter->end();


    QStyledItemDelegate::paint(painter, option, index);
}
