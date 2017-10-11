/********************************************************************************
** Form generated from reading UI file 'gui.ui'
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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *confidence;
    QTableWidget *table;
    QLineEdit *res;
    QLineEdit *res_n;

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
        label_3 = new QLabel(GUIClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        font.setPointSize(12);
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        confidence = new QComboBox(GUIClass);
        confidence->setObjectName(QStringLiteral("confidence"));

        horizontalLayout->addWidget(confidence);

        horizontalLayout->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout);

        table = new QTableWidget(GUIClass);
        if (table->columnCount() < 4)
            table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (table->rowCount() < 3)
            table->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        table->setVerticalHeaderItem(2, __qtablewidgetitem6);
        table->setObjectName(QStringLiteral("table"));
        QFont font1;
        font1.setFamily(QStringLiteral("Verdana"));
        font1.setPointSize(14);
        table->setFont(font1);
        table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
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

        res = new QLineEdit(GUIClass);
        res->setObjectName(QStringLiteral("res"));
        res->setFont(font1);
        res->setReadOnly(true);

        verticalLayout->addWidget(res);

        res_n = new QLineEdit(GUIClass);
        res_n->setObjectName(QStringLiteral("res_n"));
        res_n->setFont(font1);

        verticalLayout->addWidget(res_n);


        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QWidget *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", Q_NULLPTR));
        label_3->setText(QApplication::translate("GUIClass", "Confidence:", Q_NULLPTR));
        confidence->clear();
        confidence->insertItems(0, QStringList()
         << QApplication::translate("GUIClass", "0.90", Q_NULLPTR)
         << QApplication::translate("GUIClass", "0.95", Q_NULLPTR)
         << QApplication::translate("GUIClass", "0.98", Q_NULLPTR)
         << QApplication::translate("GUIClass", "0.99", Q_NULLPTR)
        );
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GUIClass", "x\341\264\264\342\202\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GUIClass", "x\341\264\264\342\202\202", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GUIClass", "x\342\202\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("GUIClass", "x\342\202\202", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = table->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("GUIClass", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = table->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("GUIClass", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = table->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("GUIClass", "3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
