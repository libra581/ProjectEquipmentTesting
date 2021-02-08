#ifndef CCREATEDIALOG_H
#define CCREATEDIALOG_H

#include <QWizard>
#include <QLabel>
#include <QListWidget>
#include <qDebug>
#include <QCommonStyle>
#include <QPushButton>
#include <QGridLayout>

class cCreateDialog : public QWizard
{
    Q_OBJECT
private:
     QListWidget* lwg_left,* lwg_right;

     QWizardPage* createPageChooseMode(QListWidget *lwg_left, QListWidget *lwg_right, QString strTitle);
     QWizardPage* createPageSetTime(QWidget* pwgt, QString strTitle);

public:
    cCreateDialog(QWidget* pwgt = 0);
    ~cCreateDialog();

public slots:
    void slotCreateChooseMode();
    void slotClearChooseMode();
};

#endif // CCREATEDIALOG_H
