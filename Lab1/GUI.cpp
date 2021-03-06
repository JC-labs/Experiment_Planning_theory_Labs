#include "GUI.h"
#include "qpushbutton.h"
#include <random>
#include <limits>

GUI::GUI(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	connect(ui.calculate, &QPushButton::clicked, this, &GUI::calculate);
	connect(ui.new_seed, &QPushButton::clicked, this, &GUI::new_seed);

	m_seed = std::random_device()();
}

GUI::~GUI() {
}

void GUI::calculate() {
	const double minimum_value = 0.0;
	const double maximum_value = 20.0;
	using Matrix = double[3][8];
	std::mt19937_64 g(m_seed);
	std::uniform_real_distribution<double> d(minimum_value,
											 maximum_value);
	double a[4];
	a[0] = ui.a0->value();
	a[1] = ui.a1->value();
	a[2] = ui.a2->value();
	a[3] = ui.a3->value();

	for (size_t i = 0; i < 8; i++)
		for (size_t j = 0; j < 10; j++) {
			if (ui.table->item(j, i)) delete ui.table->item(j, i);
			ui.table->setItem(j, i, new QTableWidgetItem());
		}

	Matrix m, m0;
	double min[3]{
		std::numeric_limits<double>::max(), 
		std::numeric_limits<double>::max(), 
		std::numeric_limits<double>::max()
	};
	double max[3]{
		std::numeric_limits<double>::min(), 
		std::numeric_limits<double>::min(), 
		std::numeric_limits<double>::min()
	};
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 8; j++) {
			m[i][j] = d(g);
			ui.table->item(j, i)->setText(QString::number(m[i][j]));
			m0[i][j] = m[i][j] / (maximum_value - minimum_value) * 2.0 - 1.0;	
			ui.table->item(j, i + 4)->setText(QString::number(m0[i][j]));
		}
		for (size_t j = 0; j < 8; j++) {
			if (m[i][j] > max[i])
				max[i] = m[i][j];
			if (m[i][j] < min[i])
				min[i] = m[i][j];
		}

		auto x0 = (max[i] + min[i]) / 2.0;
		ui.table->item(8, i)->setText(QString::number(x0));
		ui.table->item(9, i)->setText(QString::number((max[i] - x0) / 2.0));
	}

	double y[8];
	double std_y[8];
	for (size_t j = 0; j < 8; j++) {
		y[j] = a[0];
		for (size_t i = 0; i < 3; i++) {
			y[j] += m[i][j] * a[i + 1];
			std_y[j] += m0[i][j] * a[i + 1];
		}
		ui.table->item(j, 3)->setText(QString::number(y[j]));
		ui.table->item(j, 7)->setText(QString::number(std_y[j]));
	}

	double res_y[8];
	size_t res = 0;
	double min_res = std::numeric_limits<double>::max();
	for (size_t i = 0; i < 8; i++) {
		res_y[i] = y[i] - std_y[i];
		res_y[i] *= res_y[i];
		if (res_y[i] < min_res) {
			min_res = res_y[i];
			res = i;
		}
	}
	auto br = ui.table->item(res, 3)->foreground();
	br.setColor(QColor(255, 0, 255));
	ui.table->item(res, 3)->setForeground(br);
}

void GUI::new_seed() {
	m_seed = std::random_device()();
	calculate();
}