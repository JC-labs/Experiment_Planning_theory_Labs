/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *a0;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QDoubleSpinBox *a1;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QDoubleSpinBox *a2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QDoubleSpinBox *a3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *calculate;
    QPushButton *new_seed;
    QTableWidget *table;

    void setupUi(QWidget *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QStringLiteral("GUIClass"));
        GUIClass->resize(694, 414);
        GUIClass->setMinimumSize(QSize(691, 384));
        verticalLayout = new QVBoxLayout(GUIClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(GUIClass);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        a0 = new QDoubleSpinBox(GUIClass);
        a0->setObjectName(QStringLiteral("a0"));
        QFont font1;
        font1.setFamily(QStringLiteral("Verdana"));
        font1.setPointSize(10);
        a0->setFont(font1);
        a0->setDecimals(3);
        a0->setMinimum(-1000);
        a0->setMaximum(1000);
        a0->setValue(1);

        horizontalLayout->addWidget(a0);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_4 = new QLabel(GUIClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        a1 = new QDoubleSpinBox(GUIClass);
        a1->setObjectName(QStringLiteral("a1"));
        a1->setFont(font1);
        a1->setDecimals(3);
        a1->setMinimum(-1000);
        a1->setMaximum(1000);
        a1->setValue(1);

        horizontalLayout->addWidget(a1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(GUIClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        a2 = new QDoubleSpinBox(GUIClass);
        a2->setObjectName(QStringLiteral("a2"));
        a2->setFont(font1);
        a2->setDecimals(3);
        a2->setMinimum(-1000);
        a2->setMaximum(1000);
        a2->setValue(1);

        horizontalLayout->addWidget(a2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_3 = new QLabel(GUIClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        a3 = new QDoubleSpinBox(GUIClass);
        a3->setObjectName(QStringLiteral("a3"));
        a3->setFont(font1);
        a3->setDecimals(3);
        a3->setMinimum(-1000);
        a3->setMaximum(1000);
        a3->setValue(1);

        horizontalLayout->addWidget(a3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        calculate = new QPushButton(GUIClass);
        calculate->setObjectName(QStringLiteral("calculate"));

        verticalLayout_2->addWidget(calculate);

        new_seed = new QPushButton(GUIClass);
        new_seed->setObjectName(QStringLiteral("new_seed"));

        verticalLayout_2->addWidget(new_seed);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(4, 3);
        horizontalLayout->setStretch(7, 3);
        horizontalLayout->setStretch(10, 3);

        verticalLayout->addLayout(horizontalLayout);

        table = new QTableWidget(GUIClass);
        if (table->columnCount() < 8)
            table->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (table->rowCount() < 10)
            table->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(8, __qtablewidgetitem16);
        QFont font2;
        font2.setItalic(true);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem17->setFont(font2);
        table->setVerticalHeaderItem(9, __qtablewidgetitem17);
        table->setObjectName(QStringLiteral("table"));
        QFont font3;
        font3.setFamily(QStringLiteral("Verdana"));
        font3.setPointSize(14);
        table->setFont(font3);
        table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->setAlternatingRowColors(true);
        table->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        table->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        table->setShowGrid(true);
        table->setCornerButtonEnabled(false);
        table->horizontalHeader()->setDefaultSectionSize(80);
        table->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        table->verticalHeader()->setVisible(true);
        table->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(table);


        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QWidget *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", Q_NULLPTR));
        label->setText(QApplication::translate("GUIClass", "a\342\202\200 = ", Q_NULLPTR));
        label_4->setText(QApplication::translate("GUIClass", "a\342\202\201 = ", Q_NULLPTR));
        label_2->setText(QApplication::translate("GUIClass", "a\342\202\202 = ", Q_NULLPTR));
        label_3->setText(QApplication::translate("GUIClass", "a\342\202\203 = ", Q_NULLPTR));
        calculate->setText(QApplication::translate("GUIClass", "Calculate", Q_NULLPTR));
        new_seed->setText(QApplication::translate("GUIClass", "New seed", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GUIClass", "x\342\202\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GUIClass", "x\342\202\202", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GUIClass", "x\342\202\203", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("GUIClass", "y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("GUIClass", "x\341\264\264\342\202\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("GUIClass", "x\341\264\264\342\202\202", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("GUIClass", "x\341\264\264\342\202\203", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = table->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("GUIClass", "y\341\264\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = table->verticalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("GUIClass", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = table->verticalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("GUIClass", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = table->verticalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("GUIClass", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = table->verticalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("GUIClass", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = table->verticalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("GUIClass", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = table->verticalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("GUIClass", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = table->verticalHeaderItem(6);
        ___qtablewidgetitem14->setText(QApplication::translate("GUIClass", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = table->verticalHeaderItem(7);
        ___qtablewidgetitem15->setText(QApplication::translate("GUIClass", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = table->verticalHeaderItem(8);
        ___qtablewidgetitem16->setText(QApplication::translate("GUIClass", "x\342\202\200", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = table->verticalHeaderItem(9);
        ___qtablewidgetitem17->setText(QApplication::translate("GUIClass", "dx", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
