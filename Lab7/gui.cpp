#include "gui.h"
#include "Canvas.h"
gui::gui(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	ui.clean->hide();

	auto c = new Canvas(this);
	ui.opengl->addWidget(c);
	connect(ui.step, &QPushButton::clicked, c, &Canvas::step);
}