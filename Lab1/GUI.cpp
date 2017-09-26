#include "GUI.h"
#include "qpushbutton.h"

GUI::GUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.calculate, &QPushButton::clicked, this, &GUI::calculate);

	ui.table-
}

void GUI::calculate() {
	auto a0 = ui.a0->value();
	auto a1 = ui.a1->value();
	auto a2 = ui.a2->value();
	auto a3 = ui.a3->value();


}