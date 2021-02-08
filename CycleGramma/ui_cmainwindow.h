/********************************************************************************
** Form generated from reading UI file 'cmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINWINDOW_H
#define UI_CMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cMainWindow
{
public:
    QAction *action_open;
    QAction *action_save;
    QAction *action_exit;
    QAction *action_about;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *pView;
    QStackedWidget *stackedMenu;
    QWidget *pageSelectionMode;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *onTheLeftButton;
    QListWidget *listRight;
    QLabel *chooseMode;
    QPushButton *onTheRightButton;
    QLabel *availibleMode;
    QPushButton *buttonNext;
    QListWidget *listLeft;
    QWidget *mainMenu;
    QGridLayout *gridLayout_4;
    QGroupBox *groupParameter;
    QGridLayout *gridLayout_3;
    QLabel *label_15;
    QSpinBox *spinBoxUprezh_4;
    QPushButton *pushData;
    QLabel *label_16;
    QSpinBox *spinBoxIOK_1;
    QLabel *label_18;
    QSpinBox *spinBoxOnceMode_2;
    QLabel *label_17;
    QSpinBox *spinBoxIP_3;
    QGroupBox *groupDateAndTime;
    QFormLayout *formLayout;
    QLabel *label_13;
    QSpinBox *spinBoxNum_3;
    QLabel *label_14;
    QSpinBox *spinBoxDay_3;
    QLabel *label_2;
    QTimeEdit *timeEditData;
    QPushButton *pushButSetTime;
    QGroupBox *groupTimeSet;
    QGridLayout *gridLayout_2;
    QPushButton *buttonTimeEdit;
    QLabel *dateTimeEnd;
    QLabel *dateTimeBegin;
    QGroupBox *groupComands;
    QGridLayout *gridLayout_5;
    QCheckBox *chBoxUSFOn_2;
    QCheckBox *chBoxUSFOn_1;
    QRadioButton *radBoxUHPOn_1;
    QRadioButton *radBoxUHPOn_2;
    QCheckBox *chBoxDisabBAPI;
    QPushButton *pushButComands;
    QTabWidget *tabModes;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *cMainWindow)
    {
        if (cMainWindow->objectName().isEmpty())
            cMainWindow->setObjectName(QStringLiteral("cMainWindow"));
        cMainWindow->resize(1155, 670);
        cMainWindow->setMinimumSize(QSize(1, 1));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        cMainWindow->setWindowIcon(icon);
        action_open = new QAction(cMainWindow);
        action_open->setObjectName(QStringLiteral("action_open"));
        action_save = new QAction(cMainWindow);
        action_save->setObjectName(QStringLiteral("action_save"));
        action_save->setEnabled(true);
        action_exit = new QAction(cMainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_exit->setCheckable(false);
        action_about = new QAction(cMainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_about->setEnabled(true);
        centralWidget = new QWidget(cMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pView = new QGraphicsView(centralWidget);
        pView->setObjectName(QStringLiteral("pView"));
        pView->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pView->sizePolicy().hasHeightForWidth());
        pView->setSizePolicy(sizePolicy);
        pView->setMinimumSize(QSize(0, 250));
        pView->setMaximumSize(QSize(16777215, 250));
        pView->setInteractive(false);

        verticalLayout->addWidget(pView);

        stackedMenu = new QStackedWidget(centralWidget);
        stackedMenu->setObjectName(QStringLiteral("stackedMenu"));
        sizePolicy.setHeightForWidth(stackedMenu->sizePolicy().hasHeightForWidth());
        stackedMenu->setSizePolicy(sizePolicy);
        stackedMenu->setMaximumSize(QSize(16777215, 450));
        pageSelectionMode = new QWidget();
        pageSelectionMode->setObjectName(QStringLiteral("pageSelectionMode"));
        pageSelectionMode->setMaximumSize(QSize(16777215, 400));
        pageSelectionMode->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(pageSelectionMode);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(200, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        onTheLeftButton = new QPushButton(pageSelectionMode);
        onTheLeftButton->setObjectName(QStringLiteral("onTheLeftButton"));

        gridLayout->addWidget(onTheLeftButton, 3, 2, 1, 1);

        listRight = new QListWidget(pageSelectionMode);
        listRight->setObjectName(QStringLiteral("listRight"));
        listRight->setMaximumSize(QSize(16777215, 420));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(14);
        listRight->setFont(font);
        listRight->viewport()->setProperty("cursor", QVariant(QCursor(Qt::OpenHandCursor)));
        listRight->setFocusPolicy(Qt::ClickFocus);
        listRight->setAcceptDrops(false);
        listRight->setAutoFillBackground(false);
        listRight->setStyleSheet(QStringLiteral(""));
        listRight->setInputMethodHints(Qt::ImhNone);
        listRight->setDragDropMode(QAbstractItemView::DragDrop);
        listRight->setAlternatingRowColors(false);
        listRight->setMovement(QListView::Snap);
        listRight->setFlow(QListView::TopToBottom);
        listRight->setProperty("isWrapping", QVariant(false));
        listRight->setViewMode(QListView::ListMode);

        gridLayout->addWidget(listRight, 1, 3, 4, 1);

        chooseMode = new QLabel(pageSelectionMode);
        chooseMode->setObjectName(QStringLiteral("chooseMode"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(chooseMode->sizePolicy().hasHeightForWidth());
        chooseMode->setSizePolicy(sizePolicy1);
        chooseMode->setMaximumSize(QSize(16777215, 45));
        chooseMode->setFont(font);

        gridLayout->addWidget(chooseMode, 0, 3, 1, 1);

        onTheRightButton = new QPushButton(pageSelectionMode);
        onTheRightButton->setObjectName(QStringLiteral("onTheRightButton"));

        gridLayout->addWidget(onTheRightButton, 2, 2, 1, 1);

        availibleMode = new QLabel(pageSelectionMode);
        availibleMode->setObjectName(QStringLiteral("availibleMode"));
        sizePolicy1.setHeightForWidth(availibleMode->sizePolicy().hasHeightForWidth());
        availibleMode->setSizePolicy(sizePolicy1);
        availibleMode->setMaximumSize(QSize(16777215, 45));
        availibleMode->setFont(font);

        gridLayout->addWidget(availibleMode, 0, 1, 1, 1);

        buttonNext = new QPushButton(pageSelectionMode);
        buttonNext->setObjectName(QStringLiteral("buttonNext"));
        buttonNext->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonNext->sizePolicy().hasHeightForWidth());
        buttonNext->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(buttonNext, 5, 4, 1, 1);

        listLeft = new QListWidget(pageSelectionMode);
        new QListWidgetItem(listLeft);
        new QListWidgetItem(listLeft);
        listLeft->setObjectName(QStringLiteral("listLeft"));
        listLeft->setMaximumSize(QSize(16777215, 420));
        listLeft->setFont(font);
        listLeft->viewport()->setProperty("cursor", QVariant(QCursor(Qt::OpenHandCursor)));
        listLeft->setFrameShape(QFrame::StyledPanel);
        listLeft->setFrameShadow(QFrame::Sunken);
        listLeft->setLineWidth(1);
        listLeft->setMidLineWidth(0);
        listLeft->setAutoScrollMargin(16);
        listLeft->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listLeft->setDragEnabled(false);
        listLeft->setDragDropMode(QAbstractItemView::InternalMove);
        listLeft->setDefaultDropAction(Qt::CopyAction);
        listLeft->setIconSize(QSize(0, 0));
        listLeft->setTextElideMode(Qt::ElideLeft);
        listLeft->setMovement(QListView::Snap);
        listLeft->setUniformItemSizes(false);

        gridLayout->addWidget(listLeft, 1, 1, 4, 1);

        stackedMenu->addWidget(pageSelectionMode);
        onTheRightButton->raise();
        listLeft->raise();
        onTheLeftButton->raise();
        listRight->raise();
        chooseMode->raise();
        availibleMode->raise();
        buttonNext->raise();
        mainMenu = new QWidget();
        mainMenu->setObjectName(QStringLiteral("mainMenu"));
        gridLayout_4 = new QGridLayout(mainMenu);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(6);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        groupParameter = new QGroupBox(mainMenu);
        groupParameter->setObjectName(QStringLiteral("groupParameter"));
        sizePolicy.setHeightForWidth(groupParameter->sizePolicy().hasHeightForWidth());
        groupParameter->setSizePolicy(sizePolicy);
        groupParameter->setMinimumSize(QSize(0, 134));
        groupParameter->setMaximumSize(QSize(263, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        groupParameter->setFont(font1);
        gridLayout_3 = new QGridLayout(groupParameter);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_15 = new QLabel(groupParameter);
        label_15->setObjectName(QStringLiteral("label_15"));
        QFont font2;
        font2.setPointSize(12);
        label_15->setFont(font2);
        label_15->setLayoutDirection(Qt::LeftToRight);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_15, 0, 0, 1, 1);

        spinBoxUprezh_4 = new QSpinBox(groupParameter);
        spinBoxUprezh_4->setObjectName(QStringLiteral("spinBoxUprezh_4"));
        spinBoxUprezh_4->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBoxUprezh_4->sizePolicy().hasHeightForWidth());
        spinBoxUprezh_4->setSizePolicy(sizePolicy3);
        spinBoxUprezh_4->setMaximumSize(QSize(100, 16777215));
        spinBoxUprezh_4->setFont(font2);
        spinBoxUprezh_4->setMaximum(1000);

        gridLayout_3->addWidget(spinBoxUprezh_4, 6, 1, 1, 1);

        pushData = new QPushButton(groupParameter);
        pushData->setObjectName(QStringLiteral("pushData"));
        pushData->setEnabled(false);

        gridLayout_3->addWidget(pushData, 7, 1, 1, 1);

        label_16 = new QLabel(groupParameter);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font2);
        label_16->setLayoutDirection(Qt::LeftToRight);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_16, 6, 0, 1, 1);

        spinBoxIOK_1 = new QSpinBox(groupParameter);
        spinBoxIOK_1->setObjectName(QStringLiteral("spinBoxIOK_1"));
        spinBoxIOK_1->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(spinBoxIOK_1->sizePolicy().hasHeightForWidth());
        spinBoxIOK_1->setSizePolicy(sizePolicy4);
        spinBoxIOK_1->setMaximumSize(QSize(100, 16777215));
        spinBoxIOK_1->setFont(font2);
        spinBoxIOK_1->setMinimum(1);
        spinBoxIOK_1->setMaximum(200);
        spinBoxIOK_1->setValue(100);

        gridLayout_3->addWidget(spinBoxIOK_1, 0, 1, 1, 1);

        label_18 = new QLabel(groupParameter);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font2);
        label_18->setLayoutDirection(Qt::LeftToRight);
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_18, 2, 0, 1, 1);

        spinBoxOnceMode_2 = new QSpinBox(groupParameter);
        spinBoxOnceMode_2->setObjectName(QStringLiteral("spinBoxOnceMode_2"));
        spinBoxOnceMode_2->setEnabled(true);
        sizePolicy4.setHeightForWidth(spinBoxOnceMode_2->sizePolicy().hasHeightForWidth());
        spinBoxOnceMode_2->setSizePolicy(sizePolicy4);
        spinBoxOnceMode_2->setMaximumSize(QSize(100, 16777215));
        spinBoxOnceMode_2->setFont(font2);
        spinBoxOnceMode_2->setMinimum(120);
        spinBoxOnceMode_2->setMaximum(300);
        spinBoxOnceMode_2->setValue(120);

        gridLayout_3->addWidget(spinBoxOnceMode_2, 2, 1, 1, 1);

        label_17 = new QLabel(groupParameter);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font2);
        label_17->setLayoutDirection(Qt::LeftToRight);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_17, 4, 0, 1, 1);

        spinBoxIP_3 = new QSpinBox(groupParameter);
        spinBoxIP_3->setObjectName(QStringLiteral("spinBoxIP_3"));
        spinBoxIP_3->setEnabled(false);
        sizePolicy4.setHeightForWidth(spinBoxIP_3->sizePolicy().hasHeightForWidth());
        spinBoxIP_3->setSizePolicy(sizePolicy4);
        spinBoxIP_3->setMaximumSize(QSize(100, 16777215));
        spinBoxIP_3->setFont(font2);
        spinBoxIP_3->setMaximum(1000);
        spinBoxIP_3->setValue(0);

        gridLayout_3->addWidget(spinBoxIP_3, 4, 1, 1, 1);


        gridLayout_4->addWidget(groupParameter, 0, 0, 1, 1);

        groupDateAndTime = new QGroupBox(mainMenu);
        groupDateAndTime->setObjectName(QStringLiteral("groupDateAndTime"));
        groupDateAndTime->setEnabled(true);
        sizePolicy.setHeightForWidth(groupDateAndTime->sizePolicy().hasHeightForWidth());
        groupDateAndTime->setSizePolicy(sizePolicy);
        groupDateAndTime->setMinimumSize(QSize(0, 0));
        groupDateAndTime->setMaximumSize(QSize(263, 16777215));
        QFont font3;
        font3.setFamily(QStringLiteral("Times New Roman"));
        font3.setPointSize(10);
        groupDateAndTime->setFont(font3);
        formLayout = new QFormLayout(groupDateAndTime);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_13 = new QLabel(groupDateAndTime);
        label_13->setObjectName(QStringLiteral("label_13"));
        QFont font4;
        font4.setPointSize(11);
        label_13->setFont(font4);
        label_13->setLayoutDirection(Qt::LeftToRight);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_13);

        spinBoxNum_3 = new QSpinBox(groupDateAndTime);
        spinBoxNum_3->setObjectName(QStringLiteral("spinBoxNum_3"));
        spinBoxNum_3->setEnabled(true);
        sizePolicy3.setHeightForWidth(spinBoxNum_3->sizePolicy().hasHeightForWidth());
        spinBoxNum_3->setSizePolicy(sizePolicy3);
        spinBoxNum_3->setMaximumSize(QSize(100, 16777215));
        spinBoxNum_3->setFont(font2);
        spinBoxNum_3->setMaximum(15);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxNum_3);

        label_14 = new QLabel(groupDateAndTime);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font4);
        label_14->setLayoutDirection(Qt::LeftToRight);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_14);

        spinBoxDay_3 = new QSpinBox(groupDateAndTime);
        spinBoxDay_3->setObjectName(QStringLiteral("spinBoxDay_3"));
        spinBoxDay_3->setEnabled(true);
        sizePolicy3.setHeightForWidth(spinBoxDay_3->sizePolicy().hasHeightForWidth());
        spinBoxDay_3->setSizePolicy(sizePolicy3);
        spinBoxDay_3->setMaximumSize(QSize(100, 16777215));
        spinBoxDay_3->setFont(font2);
        spinBoxDay_3->setMaximum(1460);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxDay_3);

        label_2 = new QLabel(groupDateAndTime);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font4);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        timeEditData = new QTimeEdit(groupDateAndTime);
        timeEditData->setObjectName(QStringLiteral("timeEditData"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(timeEditData->sizePolicy().hasHeightForWidth());
        timeEditData->setSizePolicy(sizePolicy5);
        timeEditData->setFont(font2);

        formLayout->setWidget(2, QFormLayout::FieldRole, timeEditData);

        pushButSetTime = new QPushButton(groupDateAndTime);
        pushButSetTime->setObjectName(QStringLiteral("pushButSetTime"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, pushButSetTime);


        gridLayout_4->addWidget(groupDateAndTime, 1, 0, 1, 1);

        groupTimeSet = new QGroupBox(mainMenu);
        groupTimeSet->setObjectName(QStringLiteral("groupTimeSet"));
        sizePolicy.setHeightForWidth(groupTimeSet->sizePolicy().hasHeightForWidth());
        groupTimeSet->setSizePolicy(sizePolicy);
        groupTimeSet->setMaximumSize(QSize(263, 16777215));
        groupTimeSet->setFont(font3);
        groupTimeSet->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(groupTimeSet);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        buttonTimeEdit = new QPushButton(groupTimeSet);
        buttonTimeEdit->setObjectName(QStringLiteral("buttonTimeEdit"));
        buttonTimeEdit->setEnabled(false);
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(buttonTimeEdit->sizePolicy().hasHeightForWidth());
        buttonTimeEdit->setSizePolicy(sizePolicy6);
        buttonTimeEdit->setMinimumSize(QSize(0, 19));

        gridLayout_2->addWidget(buttonTimeEdit, 2, 0, 1, 1);

        dateTimeEnd = new QLabel(groupTimeSet);
        dateTimeEnd->setObjectName(QStringLiteral("dateTimeEnd"));
        QFont font5;
        font5.setPointSize(10);
        dateTimeEnd->setFont(font5);
        dateTimeEnd->setStyleSheet(QStringLiteral("QLabel{ color:rgb(255, 53, 35)}"));
        dateTimeEnd->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(dateTimeEnd, 1, 0, 1, 1);

        dateTimeBegin = new QLabel(groupTimeSet);
        dateTimeBegin->setObjectName(QStringLiteral("dateTimeBegin"));
        dateTimeBegin->setFont(font5);
        dateTimeBegin->setStyleSheet(QStringLiteral("QLabel{ color: rgb(0, 181, 21) }"));
        dateTimeBegin->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(dateTimeBegin, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupTimeSet, 2, 0, 1, 1);

        groupComands = new QGroupBox(mainMenu);
        groupComands->setObjectName(QStringLiteral("groupComands"));
        groupComands->setEnabled(false);
        sizePolicy.setHeightForWidth(groupComands->sizePolicy().hasHeightForWidth());
        groupComands->setSizePolicy(sizePolicy);
        groupComands->setMinimumSize(QSize(0, 99));
        groupComands->setMaximumSize(QSize(263, 16777215));
        gridLayout_5 = new QGridLayout(groupComands);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        chBoxUSFOn_2 = new QCheckBox(groupComands);
        chBoxUSFOn_2->setObjectName(QStringLiteral("chBoxUSFOn_2"));
        chBoxUSFOn_2->setEnabled(false);

        gridLayout_5->addWidget(chBoxUSFOn_2, 3, 0, 1, 1);

        chBoxUSFOn_1 = new QCheckBox(groupComands);
        chBoxUSFOn_1->setObjectName(QStringLiteral("chBoxUSFOn_1"));
        chBoxUSFOn_1->setEnabled(false);

        gridLayout_5->addWidget(chBoxUSFOn_1, 2, 0, 1, 1);

        radBoxUHPOn_1 = new QRadioButton(groupComands);
        radBoxUHPOn_1->setObjectName(QStringLiteral("radBoxUHPOn_1"));
        radBoxUHPOn_1->setChecked(true);

        gridLayout_5->addWidget(radBoxUHPOn_1, 2, 1, 1, 1);

        radBoxUHPOn_2 = new QRadioButton(groupComands);
        radBoxUHPOn_2->setObjectName(QStringLiteral("radBoxUHPOn_2"));

        gridLayout_5->addWidget(radBoxUHPOn_2, 3, 1, 1, 1);

        chBoxDisabBAPI = new QCheckBox(groupComands);
        chBoxDisabBAPI->setObjectName(QStringLiteral("chBoxDisabBAPI"));
        chBoxDisabBAPI->setEnabled(false);
        chBoxDisabBAPI->setCheckable(true);
        chBoxDisabBAPI->setChecked(true);

        gridLayout_5->addWidget(chBoxDisabBAPI, 4, 0, 1, 1);

        pushButComands = new QPushButton(groupComands);
        pushButComands->setObjectName(QStringLiteral("pushButComands"));

        gridLayout_5->addWidget(pushButComands, 4, 1, 1, 1);


        gridLayout_4->addWidget(groupComands, 3, 0, 1, 1);

        tabModes = new QTabWidget(mainMenu);
        tabModes->setObjectName(QStringLiteral("tabModes"));
        tabModes->setEnabled(false);
        sizePolicy.setHeightForWidth(tabModes->sizePolicy().hasHeightForWidth());
        tabModes->setSizePolicy(sizePolicy);
        tabModes->setMinimumSize(QSize(0, 0));
        tabModes->setMaximumSize(QSize(16777215, 16777215));
        tabModes->setTabShape(QTabWidget::Rounded);
        tabModes->setElideMode(Qt::ElideLeft);
        tabModes->setDocumentMode(false);
        tabModes->setTabsClosable(true);
        tabModes->setMovable(false);
        tabModes->setTabBarAutoHide(false);

        gridLayout_4->addWidget(tabModes, 0, 1, 5, 1);

        stackedMenu->addWidget(mainMenu);

        verticalLayout->addWidget(stackedMenu);

        cMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(cMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1155, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        cMainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(cMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        cMainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(action_open);
        menu->addSeparator();
        menu->addAction(action_save);
        menu->addSeparator();
        menu->addAction(action_exit);
        menu_3->addAction(action_about);

        retranslateUi(cMainWindow);

        stackedMenu->setCurrentIndex(0);
        tabModes->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(cMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *cMainWindow)
    {
        cMainWindow->setWindowTitle(QApplication::translate("cMainWindow", "\320\246\320\270\320\272\320\273\320\276\320\263\321\200\320\260\320\274\320\274\320\260", nullptr));
        action_open->setText(QApplication::translate("cMainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        action_open->setShortcut(QApplication::translate("cMainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        action_save->setText(QApplication::translate("cMainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        action_save->setShortcut(QApplication::translate("cMainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_exit->setText(QApplication::translate("cMainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#ifndef QT_NO_SHORTCUT
        action_exit->setShortcut(QApplication::translate("cMainWindow", "F10", nullptr));
#endif // QT_NO_SHORTCUT
        action_about->setText(QApplication::translate("cMainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
#ifndef QT_NO_SHORTCUT
        action_about->setShortcut(QApplication::translate("cMainWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        onTheLeftButton->setToolTip(QApplication::translate("cMainWindow", "<html><head/><body><p>\320\243\320\264\320\260\320\273\320\270\321\202\321\214</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        onTheLeftButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        listRight->setToolTip(QApplication::translate("cMainWindow", "<html><head/><body><p>\320\222\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265 \321\200\320\265\320\266\320\270\320\274\321\213</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        chooseMode->setText(QApplication::translate("cMainWindow", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265 \321\200\320\265\320\266\320\270\320\274\321\213:", nullptr));
#ifndef QT_NO_TOOLTIP
        onTheRightButton->setToolTip(QApplication::translate("cMainWindow", "<html><head/><body><p>\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        onTheRightButton->setText(QString());
        availibleMode->setText(QApplication::translate("cMainWindow", "\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213\320\265 \321\200\320\265\320\266\320\270\320\274\321\213:", nullptr));
        buttonNext->setText(QApplication::translate("cMainWindow", "\320\224&\320\260\320\273\320\265\320\265", nullptr));

        const bool __sortingEnabled = listLeft->isSortingEnabled();
        listLeft->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listLeft->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("cMainWindow", "\320\224\320\240 - \320\227\320\230", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listLeft->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("cMainWindow", "\320\224\320\240 - \320\222\320\230 (\320\232\320\237)", nullptr));
        listLeft->setSortingEnabled(__sortingEnabled);

#ifndef QT_NO_TOOLTIP
        listLeft->setToolTip(QApplication::translate("cMainWindow", "<html><head/><body><p>\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213\320\265 \321\200\320\265\320\266\320\270\320\274\321\213</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        groupParameter->setTitle(QApplication::translate("cMainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \321\206\320\270\320\272\320\273\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
        label_15->setText(QApplication::translate("cMainWindow", "\320\242 \320\270\320\276\320\272: ", nullptr));
        pushData->setText(QApplication::translate("cMainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        label_16->setText(QApplication::translate("cMainWindow", "\320\242 \321\203\320\277\321\200\320\265\320\266\320\264.:  5 + ", nullptr));
        label_18->setText(QApplication::translate("cMainWindow", "\320\242 1-\320\263\320\276 \321\200\320\265\320\266\320\270\320\274\320\260: ", nullptr));
        label_17->setText(QApplication::translate("cMainWindow", "\320\242 \320\277\320\276\320\264\320\260\321\207\320\270 \320\230\320\237:  5 + ", nullptr));
        groupDateAndTime->setTitle(QApplication::translate("cMainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\264\320\260\321\202\321\213 \320\270 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        label_13->setText(QApplication::translate("cMainWindow", "\342\204\226 4-\321\205 \321\201\321\202\320\276\320\273\320\265\321\202\320\270\321\217:", nullptr));
        label_14->setText(QApplication::translate("cMainWindow", "\342\204\226 \321\201\321\203\321\202\320\276\320\272:", nullptr));
        label_2->setText(QApplication::translate("cMainWindow", "HH : MM : SS", nullptr));
        timeEditData->setDisplayFormat(QApplication::translate("cMainWindow", "H:mm :ss", nullptr));
        pushButSetTime->setText(QApplication::translate("cMainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\262\321\200\320\265\320\274\321\217", nullptr));
        groupTimeSet->setTitle(QApplication::translate("cMainWindow", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        buttonTimeEdit->setText(QApplication::translate("cMainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        dateTimeEnd->setText(QApplication::translate("cMainWindow", "#####", nullptr));
        dateTimeBegin->setText(QApplication::translate("cMainWindow", "#####", nullptr));
        groupComands->setTitle(QApplication::translate("cMainWindow", "\320\240\320\265\320\273\320\265\320\271\320\275\321\213\320\265 \320\272\320\276\320\274\320\260\320\275\320\264\321\213", nullptr));
        chBoxUSFOn_2->setText(QApplication::translate("cMainWindow", "\320\222\320\232\320\233. \320\243\320\241\320\244 - 2", nullptr));
        chBoxUSFOn_1->setText(QApplication::translate("cMainWindow", "\320\222\320\232\320\233. \320\243\320\241\320\244 - 1", nullptr));
        radBoxUHPOn_1->setText(QApplication::translate("cMainWindow", "\320\222\320\232\320\233. \320\243\320\245\320\237 - 1", nullptr));
        radBoxUHPOn_2->setText(QApplication::translate("cMainWindow", "\320\222\320\232\320\233. \320\243\320\245\320\237 - 2", nullptr));
        chBoxDisabBAPI->setText(QApplication::translate("cMainWindow", "\320\236\320\242\320\232\320\233. \320\221\320\220\320\237\320\230", nullptr));
        pushButComands->setText(QApplication::translate("cMainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\272\320\276\320\274\320\260\320\275\320\264\321\213", nullptr));
        menu->setTitle(QApplication::translate("cMainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_3->setTitle(QApplication::translate("cMainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cMainWindow: public Ui_cMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWINDOW_H
