/********************************************************************************
** Form generated from reading UI file 'cformwithtable.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFORMWITHTABLE_H
#define UI_CFORMWITHTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cFormWithTable
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QTableWidget *tableParameter_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QComboBox *comPNA_M_10;
    QComboBox *comRange_13;
    QLabel *label_DKI_2;
    QComboBox *comDKI_2;
    QComboBox *comTZI_1;
    QComboBox *comDZU_11;
    QComboBox *comGL_BL_6;
    QComboBox *comFSCH_7;
    QLabel *label_ZKI_5;
    QLabel *label_NFI_4;
    QLabel *label_TZI_1;
    QComboBox *comCompisition_15;
    QLabel *label_VI_3;
    QComboBox *comNFI_4;
    QComboBox *comPPK_MC_8;
    QComboBox *comChange_12;
    QComboBox *comFCH_14;
    QComboBox *comZKI_5;
    QComboBox *comPKR_GMM_9;
    QComboBox *comVI_3;
    QLabel *label_Change_12;
    QLabel *label_DZU_11;
    QLabel *label_PNA_10;
    QLabel *label_PKR_GMM_9;
    QLabel *label_PPK_MC_8;
    QLabel *label_FSCH_V_7;
    QLabel *label_GL_BL_6;
    QLabel *label_Compisition_15;
    QLabel *label_FCH_14;
    QLabel *label_Range_13;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *cFormWithTable)
    {
        if (cFormWithTable->objectName().isEmpty())
            cFormWithTable->setObjectName(QStringLiteral("cFormWithTable"));
        cFormWithTable->resize(1137, 729);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cFormWithTable->sizePolicy().hasHeightForWidth());
        cFormWithTable->setSizePolicy(sizePolicy);
        cFormWithTable->setMinimumSize(QSize(0, 0));
        cFormWithTable->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(cFormWithTable);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(cFormWithTable);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setLayoutDirection(Qt::LeftToRight);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1137, 729));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableParameter_2 = new QTableWidget(scrollAreaWidgetContents);
        if (tableParameter_2->columnCount() < 8)
            tableParameter_2->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableParameter_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableParameter_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableParameter_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableParameter_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableParameter_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableParameter_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableParameter_2->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableParameter_2->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableParameter_2->setObjectName(QStringLiteral("tableParameter_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableParameter_2->sizePolicy().hasHeightForWidth());
        tableParameter_2->setSizePolicy(sizePolicy2);
        tableParameter_2->setMinimumSize(QSize(900, 190));
        tableParameter_2->setMaximumSize(QSize(16777215, 190));
        tableParameter_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        tableParameter_2->setLayoutDirection(Qt::LeftToRight);
        tableParameter_2->setFrameShape(QFrame::StyledPanel);
        tableParameter_2->setFrameShadow(QFrame::Sunken);
        tableParameter_2->setLineWidth(1);
        tableParameter_2->setAutoScroll(true);
        tableParameter_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableParameter_2->setDragEnabled(false);
        tableParameter_2->setAlternatingRowColors(false);
        tableParameter_2->setSelectionMode(QAbstractItemView::SingleSelection);
        tableParameter_2->setTextElideMode(Qt::ElideRight);
        tableParameter_2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableParameter_2->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableParameter_2->setShowGrid(true);
        tableParameter_2->setGridStyle(Qt::SolidLine);
        tableParameter_2->setSortingEnabled(true);
        tableParameter_2->setWordWrap(true);
        tableParameter_2->setCornerButtonEnabled(true);
        tableParameter_2->horizontalHeader()->setCascadingSectionResizes(false);
        tableParameter_2->horizontalHeader()->setDefaultSectionSize(104);
        tableParameter_2->horizontalHeader()->setMinimumSectionSize(31);
        tableParameter_2->verticalHeader()->setDefaultSectionSize(25);
        tableParameter_2->verticalHeader()->setStretchLastSection(false);

        gridLayout_2->addWidget(tableParameter_2, 0, 0, 1, 3);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comPNA_M_10 = new QComboBox(groupBox_2);
        comPNA_M_10->addItem(QString());
        comPNA_M_10->setObjectName(QStringLiteral("comPNA_M_10"));

        gridLayout->addWidget(comPNA_M_10, 9, 1, 1, 1);

        comRange_13 = new QComboBox(groupBox_2);
        comRange_13->addItem(QString());
        comRange_13->setObjectName(QStringLiteral("comRange_13"));

        gridLayout->addWidget(comRange_13, 12, 1, 1, 1);

        label_DKI_2 = new QLabel(groupBox_2);
        label_DKI_2->setObjectName(QStringLiteral("label_DKI_2"));
        label_DKI_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_DKI_2, 1, 0, 1, 1);

        comDKI_2 = new QComboBox(groupBox_2);
        comDKI_2->addItem(QString());
        comDKI_2->setObjectName(QStringLiteral("comDKI_2"));

        gridLayout->addWidget(comDKI_2, 1, 1, 1, 1);

        comTZI_1 = new QComboBox(groupBox_2);
        comTZI_1->addItem(QString());
        comTZI_1->addItem(QString());
        comTZI_1->setObjectName(QStringLiteral("comTZI_1"));

        gridLayout->addWidget(comTZI_1, 0, 1, 1, 1);

        comDZU_11 = new QComboBox(groupBox_2);
        comDZU_11->addItem(QString());
        comDZU_11->addItem(QString());
        comDZU_11->setObjectName(QStringLiteral("comDZU_11"));

        gridLayout->addWidget(comDZU_11, 10, 1, 1, 1);

        comGL_BL_6 = new QComboBox(groupBox_2);
        comGL_BL_6->addItem(QString());
        comGL_BL_6->addItem(QString());
        comGL_BL_6->addItem(QString());
        comGL_BL_6->setObjectName(QStringLiteral("comGL_BL_6"));

        gridLayout->addWidget(comGL_BL_6, 5, 1, 1, 1);

        comFSCH_7 = new QComboBox(groupBox_2);
        comFSCH_7->addItem(QString());
        comFSCH_7->setObjectName(QStringLiteral("comFSCH_7"));

        gridLayout->addWidget(comFSCH_7, 6, 1, 1, 1);

        label_ZKI_5 = new QLabel(groupBox_2);
        label_ZKI_5->setObjectName(QStringLiteral("label_ZKI_5"));
        label_ZKI_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_ZKI_5, 4, 0, 1, 1);

        label_NFI_4 = new QLabel(groupBox_2);
        label_NFI_4->setObjectName(QStringLiteral("label_NFI_4"));
        label_NFI_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_NFI_4, 3, 0, 1, 1);

        label_TZI_1 = new QLabel(groupBox_2);
        label_TZI_1->setObjectName(QStringLiteral("label_TZI_1"));
        label_TZI_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_TZI_1, 0, 0, 1, 1);

        comCompisition_15 = new QComboBox(groupBox_2);
        comCompisition_15->addItem(QString());
        comCompisition_15->addItem(QString());
        comCompisition_15->addItem(QString());
        comCompisition_15->addItem(QString());
        comCompisition_15->addItem(QString());
        comCompisition_15->addItem(QString());
        comCompisition_15->setObjectName(QStringLiteral("comCompisition_15"));

        gridLayout->addWidget(comCompisition_15, 14, 1, 1, 1);

        label_VI_3 = new QLabel(groupBox_2);
        label_VI_3->setObjectName(QStringLiteral("label_VI_3"));
        label_VI_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_VI_3, 2, 0, 1, 1);

        comNFI_4 = new QComboBox(groupBox_2);
        comNFI_4->addItem(QString());
        comNFI_4->addItem(QString());
        comNFI_4->addItem(QString());
        comNFI_4->setObjectName(QStringLiteral("comNFI_4"));

        gridLayout->addWidget(comNFI_4, 3, 1, 1, 1);

        comPPK_MC_8 = new QComboBox(groupBox_2);
        comPPK_MC_8->addItem(QString());
        comPPK_MC_8->addItem(QString());
        comPPK_MC_8->addItem(QString());
        comPPK_MC_8->setObjectName(QStringLiteral("comPPK_MC_8"));
        comPPK_MC_8->setMinimumSize(QSize(190, 0));

        gridLayout->addWidget(comPPK_MC_8, 7, 1, 1, 1);

        comChange_12 = new QComboBox(groupBox_2);
        comChange_12->addItem(QString());
        comChange_12->addItem(QString());
        comChange_12->addItem(QString());
        comChange_12->addItem(QString());
        comChange_12->addItem(QString());
        comChange_12->addItem(QString());
        comChange_12->addItem(QString());
        comChange_12->addItem(QString());
        comChange_12->addItem(QString());
        comChange_12->addItem(QString());
        comChange_12->addItem(QString());
        comChange_12->addItem(QString());
        comChange_12->setObjectName(QStringLiteral("comChange_12"));

        gridLayout->addWidget(comChange_12, 11, 1, 1, 1);

        comFCH_14 = new QComboBox(groupBox_2);
        comFCH_14->addItem(QString());
        comFCH_14->setObjectName(QStringLiteral("comFCH_14"));

        gridLayout->addWidget(comFCH_14, 13, 1, 1, 1);

        comZKI_5 = new QComboBox(groupBox_2);
        comZKI_5->addItem(QString());
        comZKI_5->addItem(QString());
        comZKI_5->addItem(QString());
        comZKI_5->setObjectName(QStringLiteral("comZKI_5"));

        gridLayout->addWidget(comZKI_5, 4, 1, 1, 1);

        comPKR_GMM_9 = new QComboBox(groupBox_2);
        comPKR_GMM_9->addItem(QString());
        comPKR_GMM_9->setObjectName(QStringLiteral("comPKR_GMM_9"));

        gridLayout->addWidget(comPKR_GMM_9, 8, 1, 1, 1);

        comVI_3 = new QComboBox(groupBox_2);
        comVI_3->addItem(QString());
        comVI_3->addItem(QString());
        comVI_3->addItem(QString());
        comVI_3->addItem(QString());
        comVI_3->setObjectName(QStringLiteral("comVI_3"));

        gridLayout->addWidget(comVI_3, 2, 1, 1, 1);

        label_Change_12 = new QLabel(groupBox_2);
        label_Change_12->setObjectName(QStringLiteral("label_Change_12"));
        label_Change_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Change_12, 11, 0, 1, 1);

        label_DZU_11 = new QLabel(groupBox_2);
        label_DZU_11->setObjectName(QStringLiteral("label_DZU_11"));
        label_DZU_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_DZU_11, 10, 0, 1, 1);

        label_PNA_10 = new QLabel(groupBox_2);
        label_PNA_10->setObjectName(QStringLiteral("label_PNA_10"));
        label_PNA_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_PNA_10, 9, 0, 1, 1);

        label_PKR_GMM_9 = new QLabel(groupBox_2);
        label_PKR_GMM_9->setObjectName(QStringLiteral("label_PKR_GMM_9"));
        label_PKR_GMM_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_PKR_GMM_9, 8, 0, 1, 1);

        label_PPK_MC_8 = new QLabel(groupBox_2);
        label_PPK_MC_8->setObjectName(QStringLiteral("label_PPK_MC_8"));
        label_PPK_MC_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_PPK_MC_8, 7, 0, 1, 1);

        label_FSCH_V_7 = new QLabel(groupBox_2);
        label_FSCH_V_7->setObjectName(QStringLiteral("label_FSCH_V_7"));
        label_FSCH_V_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_FSCH_V_7, 6, 0, 1, 1);

        label_GL_BL_6 = new QLabel(groupBox_2);
        label_GL_BL_6->setObjectName(QStringLiteral("label_GL_BL_6"));
        label_GL_BL_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_GL_BL_6, 5, 0, 1, 1);

        label_Compisition_15 = new QLabel(groupBox_2);
        label_Compisition_15->setObjectName(QStringLiteral("label_Compisition_15"));
        label_Compisition_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Compisition_15, 14, 0, 1, 1);

        label_FCH_14 = new QLabel(groupBox_2);
        label_FCH_14->setObjectName(QStringLiteral("label_FCH_14"));
        label_FCH_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_FCH_14, 13, 0, 1, 1);

        label_Range_13 = new QLabel(groupBox_2);
        label_Range_13->setObjectName(QStringLiteral("label_Range_13"));
        label_Range_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Range_13, 12, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_2);

        horizontalSpacer = new QSpacerItem(224, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        if (tableWidget->rowCount() < 12)
            tableWidget->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(5, 1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(6, 1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(7, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(7, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(8, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setItem(8, 1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(9, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setItem(9, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setItem(10, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setItem(10, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setItem(11, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setItem(11, 1, __qtablewidgetitem45);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(226, 400));
        tableWidget->setMaximumSize(QSize(243, 16777215));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        horizontalLayout_2->addWidget(tableWidget);

        tableWidget_2 = new QTableWidget(groupBox);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem47);
        if (tableWidget_2->rowCount() < 2)
            tableWidget_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 0, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 1, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 0, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 1, __qtablewidgetitem53);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(218, 0));
        tableWidget_2->setMaximumSize(QSize(219, 87));
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout_2->addWidget(tableWidget_2);

        horizontalSpacer_2 = new QSpacerItem(212, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(cFormWithTable);

        QMetaObject::connectSlotsByName(cFormWithTable);
    } // setupUi

    void retranslateUi(QWidget *cFormWithTable)
    {
        cFormWithTable->setWindowTitle(QApplication::translate("cFormWithTable", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableParameter_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("cFormWithTable", "\342\204\226 \320\277/\320\277", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableParameter_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("cFormWithTable", "\342\204\226 \321\200\320\265\320\266\320\270\320\274\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableParameter_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("cFormWithTable", "\320\242\320\270\320\277", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableParameter_2->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("cFormWithTable", "\320\222\321\200\320\265\320\274\321\217 \320\275\320\260\321\207\320\260\320\273\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableParameter_2->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QApplication::translate("cFormWithTable", "\320\222\321\200\320\265\320\274\321\217 \320\272\320\276\320\275\321\206\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableParameter_2->horizontalHeaderItem(6);
        ___qtablewidgetitem5->setText(QApplication::translate("cFormWithTable", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableParameter_2->horizontalHeaderItem(7);
        ___qtablewidgetitem6->setText(QApplication::translate("cFormWithTable", "\320\232\320\276\320\274\320\260\320\275\320\264\320\275\320\276\320\265 \321\201\320\273\320\276\320\262\320\276", nullptr));
        groupBox->setTitle(QApplication::translate("cFormWithTable", "\320\224\320\276\320\277. \320\242\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        groupBox_2->setTitle(QApplication::translate("cFormWithTable", "\320\240\320\265\320\266\320\270\320\274 1", nullptr));
        comPNA_M_10->setItemText(0, QApplication::translate("cFormWithTable", "00 - \320\236\321\202\320\272\320\273 \320\237\320\235\320\220-\320\234", nullptr));

        comRange_13->setItemText(0, QApplication::translate("cFormWithTable", "00 - \320\275\320\265 \320\267\320\260\320\264\320\260\320\275", nullptr));

        label_DKI_2->setText(QApplication::translate("cFormWithTable", "\320\224\320\232\320\230:", nullptr));
        comDKI_2->setItemText(0, QApplication::translate("cFormWithTable", "0 - \320\221\320\265\320\267 \320\224\320\232\320\230", nullptr));

        comTZI_1->setItemText(0, QApplication::translate("cFormWithTable", "1 - \320\241 \320\270\320\267\320\273\321\203\321\207\320\265\320\275\320\270\320\265\320\274", nullptr));
        comTZI_1->setItemText(1, QApplication::translate("cFormWithTable", "0 - \320\221\320\265\320\267 \320\270\320\267\320\273\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));

        comDZU_11->setItemText(0, QApplication::translate("cFormWithTable", "11 - \320\272\320\276\320\273\321\214\321\206\320\265\320\262\320\260\321\217 \320\260\320\264\321\200\320\265\321\201\320\260\321\206\320\270\321\217 (\320\232\320\220\320\237) ", nullptr));
        comDZU_11->setItemText(1, QApplication::translate("cFormWithTable", "00", nullptr));

        comGL_BL_6->setItemText(0, QApplication::translate("cFormWithTable", "00 - \320\236\321\202\320\272\320\273 1\320\223\320\233-\320\221\320\233", nullptr));
        comGL_BL_6->setItemText(1, QApplication::translate("cFormWithTable", "01", nullptr));
        comGL_BL_6->setItemText(2, QApplication::translate("cFormWithTable", "10", nullptr));

        comFSCH_7->setItemText(0, QApplication::translate("cFormWithTable", "00 - \320\236\321\202\320\272\320\273 \320\244\320\241\320\247-\320\221", nullptr));

        label_ZKI_5->setText(QApplication::translate("cFormWithTable", "\320\227\320\232\320\230:", nullptr));
        label_NFI_4->setText(QApplication::translate("cFormWithTable", "\320\235\320\244\320\230:", nullptr));
        label_TZI_1->setText(QApplication::translate("cFormWithTable", "\320\242\320\227\320\230:", nullptr));
        comCompisition_15->setItemText(0, QApplication::translate("cFormWithTable", "000 - \320\275\320\265\321\202 \321\201\320\265\320\273\320\265\320\272\321\206\320\270\320\270", nullptr));
        comCompisition_15->setItemText(1, QApplication::translate("cFormWithTable", "001", nullptr));
        comCompisition_15->setItemText(2, QApplication::translate("cFormWithTable", "010", nullptr));
        comCompisition_15->setItemText(3, QApplication::translate("cFormWithTable", "011", nullptr));
        comCompisition_15->setItemText(4, QApplication::translate("cFormWithTable", "100", nullptr));
        comCompisition_15->setItemText(5, QApplication::translate("cFormWithTable", "101", nullptr));

        label_VI_3->setText(QApplication::translate("cFormWithTable", "\320\222\320\270\320\264 \320\222\320\230 1 \321\200\320\265\320\266\320\270\320\274\320\260:", nullptr));
        comNFI_4->setItemText(0, QApplication::translate("cFormWithTable", "00 - \320\236\321\202\320\272\320\273 \320\235\320\244\320\230 ", nullptr));
        comNFI_4->setItemText(1, QApplication::translate("cFormWithTable", "01", nullptr));
        comNFI_4->setItemText(2, QApplication::translate("cFormWithTable", "10", nullptr));

        comPPK_MC_8->setItemText(0, QApplication::translate("cFormWithTable", "00 - \320\236\321\202\320\272\320\273 \320\237\320\237\320\232-\320\234\320\246", nullptr));
        comPPK_MC_8->setItemText(1, QApplication::translate("cFormWithTable", "01", nullptr));
        comPPK_MC_8->setItemText(2, QApplication::translate("cFormWithTable", "10", nullptr));

        comChange_12->setItemText(0, QApplication::translate("cFormWithTable", "0000 - \320\275\320\265 \320\267\320\260\320\264\320\260\320\275", nullptr));
        comChange_12->setItemText(1, QApplication::translate("cFormWithTable", "0001", nullptr));
        comChange_12->setItemText(2, QApplication::translate("cFormWithTable", "0010", nullptr));
        comChange_12->setItemText(3, QApplication::translate("cFormWithTable", "0011", nullptr));
        comChange_12->setItemText(4, QApplication::translate("cFormWithTable", "0100", nullptr));
        comChange_12->setItemText(5, QApplication::translate("cFormWithTable", "0101", nullptr));
        comChange_12->setItemText(6, QApplication::translate("cFormWithTable", "1001", nullptr));
        comChange_12->setItemText(7, QApplication::translate("cFormWithTable", "1010", nullptr));
        comChange_12->setItemText(8, QApplication::translate("cFormWithTable", "1011", nullptr));
        comChange_12->setItemText(9, QApplication::translate("cFormWithTable", "1100", nullptr));
        comChange_12->setItemText(10, QApplication::translate("cFormWithTable", "1101", nullptr));
        comChange_12->setItemText(11, QApplication::translate("cFormWithTable", "1111", nullptr));

        comFCH_14->setItemText(0, QApplication::translate("cFormWithTable", "0000000 - \320\275\320\265 \320\267\320\260\320\264\320\260\320\275", nullptr));

        comZKI_5->setItemText(0, QApplication::translate("cFormWithTable", "00 - \320\236\321\202\320\272\320\273 \320\227\320\232\320\230", nullptr));
        comZKI_5->setItemText(1, QApplication::translate("cFormWithTable", "01", nullptr));
        comZKI_5->setItemText(2, QApplication::translate("cFormWithTable", "10", nullptr));

        comPKR_GMM_9->setItemText(0, QApplication::translate("cFormWithTable", "00 - \320\236\321\202\320\272\320\273 \320\237\320\232\320\240-\320\223\320\234\320\234", nullptr));

        comVI_3->setItemText(0, QApplication::translate("cFormWithTable", "00 - \320\275\320\265\321\202 \321\200\320\265\320\266\320\270\320\274\320\260 \320\222\320\230", nullptr));
        comVI_3->setItemText(1, QApplication::translate("cFormWithTable", "01", nullptr));
        comVI_3->setItemText(2, QApplication::translate("cFormWithTable", "10", nullptr));
        comVI_3->setItemText(3, QApplication::translate("cFormWithTable", "11", nullptr));

        label_Change_12->setText(QApplication::translate("cFormWithTable", "\320\227\320\260\320\272\320\276\320\275 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217:", nullptr));
        label_DZU_11->setText(QApplication::translate("cFormWithTable", "\320\220\320\264\321\200\320\265\321\201\320\260\321\206\320\270\321\217 \320\224\320\227\320\243:", nullptr));
        label_PNA_10->setText(QApplication::translate("cFormWithTable", "\320\237\320\235\320\220-\320\234:", nullptr));
        label_PKR_GMM_9->setText(QApplication::translate("cFormWithTable", "\320\237\320\232\320\240-\320\223\320\234\320\234:", nullptr));
        label_PPK_MC_8->setText(QApplication::translate("cFormWithTable", "\320\237\320\237\320\232-\320\234\320\246:", nullptr));
        label_FSCH_V_7->setText(QApplication::translate("cFormWithTable", "\320\244\320\241\320\247-\320\221:", nullptr));
        label_GL_BL_6->setText(QApplication::translate("cFormWithTable", "\320\223\320\233-\320\221\320\233:", nullptr));
        label_Compisition_15->setText(QApplication::translate("cFormWithTable", "\320\241\320\276\321\201\321\202\320\260\320\262 \320\277\320\265\321\200\320\265\320\264\320\260\320\262\320\260\320\265\320\274\320\276\320\271 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270:", nullptr));
        label_FCH_14->setText(QApplication::translate("cFormWithTable", "\320\235\320\276\320\274\320\265\321\200 \320\244\320\247:", nullptr));
        label_Range_13->setText(QApplication::translate("cFormWithTable", "\320\237\320\276\320\264\320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275:", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("cFormWithTable", "\320\224\320\260\320\275\320\275\321\213\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("cFormWithTable", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("cFormWithTable", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("cFormWithTable", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("cFormWithTable", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("cFormWithTable", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem13->setText(QApplication::translate("cFormWithTable", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem14->setText(QApplication::translate("cFormWithTable", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem15->setText(QApplication::translate("cFormWithTable", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem16->setText(QApplication::translate("cFormWithTable", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem17->setText(QApplication::translate("cFormWithTable", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem18->setText(QApplication::translate("cFormWithTable", "11", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem19->setText(QApplication::translate("cFormWithTable", "12", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem20->setText(QApplication::translate("cFormWithTable", "13", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(0, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("cFormWithTable", "\320\235\320\243\320\2201", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(0, 1);
        ___qtablewidgetitem22->setText(QApplication::translate("cFormWithTable", "00000000000", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(1, 0);
        ___qtablewidgetitem23->setText(QApplication::translate("cFormWithTable", "1\320\237\320\241\320\2201 - \320\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(1, 1);
        ___qtablewidgetitem24->setText(QApplication::translate("cFormWithTable", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(2, 0);
        ___qtablewidgetitem25->setText(QApplication::translate("cFormWithTable", "1\320\237\320\241\320\2201", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(2, 1);
        ___qtablewidgetitem26->setText(QApplication::translate("cFormWithTable", "0000000", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(3, 0);
        ___qtablewidgetitem27->setText(QApplication::translate("cFormWithTable", "2\320\237\320\241\320\2201 - \320\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(3, 1);
        ___qtablewidgetitem28->setText(QApplication::translate("cFormWithTable", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(4, 0);
        ___qtablewidgetitem29->setText(QApplication::translate("cFormWithTable", "2\320\237\320\241\320\2201", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(4, 1);
        ___qtablewidgetitem30->setText(QApplication::translate("cFormWithTable", "0000000", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(5, 0);
        ___qtablewidgetitem31->setText(QApplication::translate("cFormWithTable", "\320\232\320\222", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(5, 1);
        ___qtablewidgetitem32->setText(QApplication::translate("cFormWithTable", "00000000", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(6, 0);
        ___qtablewidgetitem33->setText(QApplication::translate("cFormWithTable", "\320\235\320\243\320\2202", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(6, 1);
        ___qtablewidgetitem34->setText(QApplication::translate("cFormWithTable", "000000000", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(7, 0);
        ___qtablewidgetitem35->setText(QApplication::translate("cFormWithTable", "1\320\237\320\241\320\2202 - \320\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(7, 1);
        ___qtablewidgetitem36->setText(QApplication::translate("cFormWithTable", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(8, 0);
        ___qtablewidgetitem37->setText(QApplication::translate("cFormWithTable", "1\320\237\320\241\320\2202", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->item(8, 1);
        ___qtablewidgetitem38->setText(QApplication::translate("cFormWithTable", "0000000", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->item(9, 0);
        ___qtablewidgetitem39->setText(QApplication::translate("cFormWithTable", "2\320\237\320\241\320\2202 - \320\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->item(9, 1);
        ___qtablewidgetitem40->setText(QApplication::translate("cFormWithTable", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->item(10, 0);
        ___qtablewidgetitem41->setText(QApplication::translate("cFormWithTable", "2\320\237\320\241\320\2202", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->item(10, 1);
        ___qtablewidgetitem42->setText(QApplication::translate("cFormWithTable", "0000000", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->item(11, 0);
        ___qtablewidgetitem43->setText(QApplication::translate("cFormWithTable", "\320\243\320\233\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->item(11, 1);
        ___qtablewidgetitem44->setText(QApplication::translate("cFormWithTable", "0", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem45->setText(QApplication::translate("cFormWithTable", "\320\224\320\260\320\275\320\275\321\213\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem46->setText(QApplication::translate("cFormWithTable", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem47->setText(QApplication::translate("cFormWithTable", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem48->setText(QApplication::translate("cFormWithTable", "2", nullptr));

        const bool __sortingEnabled1 = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_2->item(0, 0);
        ___qtablewidgetitem49->setText(QApplication::translate("cFormWithTable", "\320\232\320\232\320\223 - 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_2->item(0, 1);
        ___qtablewidgetitem50->setText(QApplication::translate("cFormWithTable", "00000000", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget_2->item(1, 0);
        ___qtablewidgetitem51->setText(QApplication::translate("cFormWithTable", "\320\240\320\265\320\267\320\265\321\200\320\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget_2->item(1, 1);
        ___qtablewidgetitem52->setText(QApplication::translate("cFormWithTable", "00000000", nullptr));
        tableWidget_2->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class cFormWithTable: public Ui_cFormWithTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFORMWITHTABLE_H
