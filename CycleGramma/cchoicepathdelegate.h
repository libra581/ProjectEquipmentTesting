#ifndef CCHOICEPATHDELEGATE_H
#define CCHOICEPATHDELEGATE_H

#include <QStyledItemDelegate>
#include <QLineEdit>
#include <QPainter>

class cChoicePathDelegate : public QStyledItemDelegate
{

public:
    cChoicePathDelegate (QObject *parent = 0);

    //Создаем виджет редактора значений
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    //Передает значения от модели в редактор
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    //Передает значение от редактора в модель
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    //Задает геометрию редактора
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    //Отрисовывает ячейку элемента
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

#endif // CCHOICEPATHDELEGATE_H
