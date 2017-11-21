#pragma once

#include <QWidget>
#include "ui_gui2.h"

class gui2 : public QWidget
{
	Q_OBJECT

public:
	gui2(QWidget *parent = Q_NULLPTR);
	~gui2();

private:
	Ui::gui2Class ui;
};