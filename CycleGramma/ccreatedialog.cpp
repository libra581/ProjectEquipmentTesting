#include "ccreatedialog.h"

cCreateDialog::cCreateDialog(QWidget *pwgt):
    QWizard(pwgt)
{
    lwg_left = new QListWidget(this);
    lwg_right = new QListWidget(this);

    addPage(createPageChooseMode(lwg_left,lwg_right, "One"));
    addPage(createPageSetTime(new QLabel("<H1>Label 1</H1>"), "Two"));
}


QWizardPage* cCreateDialog::createPageChooseMode(QListWidget *lwg_left, QListWidget *lwg_right, QString strTitle)
{
    QWizardPage* ppage = new QWizardPage;
    ppage->setTitle(strTitle);

    QLabel *pAvailibleMode = new QLabel(this);
    QLabel *pChooseMode    = new QLabel(this);

    pAvailibleMode->setText("Доступные режимы");
    pChooseMode->setText("Выбранные режимы");

    QStringList lst, lst_choose;
    QListWidgetItem* pitem = NULL;

    lst << "ДР-ЗИ" << "ДР-ВИ(КП)";

    foreach(QString str,lst)
    {
        pitem = new QListWidgetItem(str, lwg_left);
    }

    lwg_left->resize(125, 175);
    lwg_left->show();


    lwg_right->resize(125, 175);
    lwg_right->show();

    QPushButton* onTheRight = new QPushButton(this);
    QPushButton* onTheLeft  = new QPushButton(this);

    onTheRight->setIcon(QCommonStyle().standardIcon(QStyle::SP_ArrowRight));
    onTheLeft ->setIcon(QCommonStyle().standardIcon(QStyle::SP_ArrowLeft));

    connect(onTheRight,SIGNAL(clicked()),SLOT(slotCreateChooseMode()));
    connect(onTheLeft, SIGNAL(clicked()),SLOT(slotClearChooseMode( )));

    QGridLayout* playout = new QGridLayout;
    playout->addWidget(pAvailibleMode,0,0);
    playout->addWidget(pChooseMode,0,2);
    playout->addWidget(lwg_left,1,0,4,1);
    playout->addWidget(onTheRight,2,1);
    playout->addWidget(onTheLeft,3,1);
    playout->addWidget(lwg_right,1,2,4,1);
    ppage->setLayout(playout);

    return ppage;
}

QWizardPage* cCreateDialog::createPageSetTime(QWidget *pwgt, QString strTitle)
{
    QWizardPage* ppage = new QWizardPage;
    ppage->setTitle(strTitle);

    QVBoxLayout* playout = new QVBoxLayout;
    playout->addWidget(pwgt);
    ppage->setLayout(playout);

    return ppage;
}


cCreateDialog::~cCreateDialog()
{

}

void cCreateDialog::slotCreateChooseMode()
{
   lwg_right->addItem(lwg_left->currentItem()->text());
}

void cCreateDialog::slotClearChooseMode()
{
   lwg_right->takeItem(lwg_right->currentRow());
}
