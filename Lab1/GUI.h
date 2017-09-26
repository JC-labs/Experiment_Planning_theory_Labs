#pragma once

#include <QtWidgets/QWidget>
#include "ui_GUI.h"

class GUI : public QWidget
{
	Q_OBJECT

public:
	GUI(QWidget *parent = Q_NULLPTR);
	~GUI();

private:
	Ui::GUIClass ui;
	size_t m_seed;

private slots:
	void calculate();
	void new_seed();
};
