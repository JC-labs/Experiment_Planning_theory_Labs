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
    QPushButton *calculate;
    QTableWidget *tableWidget;

    void setupUi(QWidget *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QStringLiteral("GUIClass"));
        GUIClass->resize(746, 344);
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

        horizontalLayout->addWidget(a3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        calculate = new QPushButton(GUIClass);
        calculate->setObjectName(QStringLiteral("calculate"));

        horizontalLayout->addWidget(calculate);

        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(4, 3);
        horizontalLayout->setStretch(7, 3);
        horizontalLayout->setStretch(10, 3);
        horizontalLayout->setStretch(12, 2);

        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(GUIClass);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


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
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
