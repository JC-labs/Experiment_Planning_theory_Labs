#include "gui.h"
const size_t Array_Size = 3;
const size_t Experiments_Number = 8;
using Number = float;
#include <array>
using Array = std::array<Number, Array_Size>;
using Experiment = std::array<Number, Experiments_Number>;
using Matrix = std::array<Array, Experiments_Number>;
#include "qtablewidget.h"
void draw(QTableWidget *table, size_t i, size_t j, Number value) {
	table->setItem(i, j, new QTableWidgetItem(QString::number(value)));
	table->item(i, j)->setTextAlignment(Qt::AlignHCenter);
}

gui::gui(QWidget *parent) : QWidget(parent) {
	auto lambda = [this]() {
		Matrix x{Array{-30, +15, +20}, Array{-30, +15, +35}, Array{-30, +50, +20}, Array{-30, +50, +35},
				 Array{+20, +15, +20}, Array{+20, +15, +35}, Array{+20, +50, +20}, Array{+20, +50, +35}};
		Matrix xn{Array{-1, -1, -1}, Array{-1, -1, +1}, Array{-1, +1, -1}, Array{-1, +1, +1},
				  Array{+1, -1, -1}, Array{+1, -1, +1}, Array{+1, +1, -1}, Array{+1, +1, +1}};
		Matrix xxn = xn;
		Experiment xxxn;
		for (size_t j = 0; j < Experiments_Number; j++) {
			for (size_t i = 0; i < Array_Size; i++) {
				draw(ui.table, j, i, x[j][i]);
				draw(ui.table, j, i + 3, xn[j][i]);
			}
			xxn[j][0] = xn[j][0] * xn[j][1];
			xxn[j][1] = xn[j][1] * xn[j][2];
			xxn[j][2] = xn[j][0] * xn[j][2];
			draw(ui.table, j, 0 + 6, xxn[j][0]);
			draw(ui.table, j, 1 + 6, xxn[j][1]);
			draw(ui.table, j, 2 + 6, xxn[j][2]);
			xxxn[j] = xn[j][0] * xn[j][1] * xn[j][2];
			draw(ui.table, j, 2 + 7, xxxn[j]);
		}
	};
	ui.setupUi(this);
	connect(ui.calculate, &QPushButton::clicked, lambda);
	lambda();
}