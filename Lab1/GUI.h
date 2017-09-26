#pragma once

#include <QtWidgets/QWidget>
#include "ui_GUI.h"

class QTableWidgetItem;
class GUI : public QWidget
{
	Q_OBJECT

public:
	GUI(QWidget *parent = Q_NULLPTR);
	~GUI();

private:
	Ui::GUIClass ui;
	QTableWidgetItem *m_last_selected;

private slots:
	void calculate();
};
