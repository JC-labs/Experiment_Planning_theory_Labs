#include "gui.h"
#include "Functions.hpp"
#include "Tests.hpp"
using namespace shared;

#include "qtablewidget.h"
void draw(QTableWidget *table, size_t i, size_t j, Number value) {
	table->setItem(i, j, new QTableWidgetItem(QString::number(value)));
	table->item(i, j)->setTextAlignment(Qt::AlignHCenter);
}

constexpr size_t Var = 3u;
constexpr Array<Var> x_min = {-30, +15, +20};
constexpr Array<Var> x_max = {+20, +50, +35};
constexpr Number y_max = 200 + Number(x_max[0] + x_max[1] + x_max[2]) / 3;
constexpr Number y_min = 200 + Number(x_min[0] + x_min[1] + x_min[2]) / 3;
constexpr Array<Var> dx = {(x_max[0] - x_min[0]) / 2, (x_max[1] - x_min[1]) / 2, (x_max[2] - x_min[2]) / 2};
constexpr Array<Var> x0 = {(x_max[0] + x_min[0]) / 2, (x_max[1] + x_min[1]) / 2, (x_max[2] + x_min[2]) / 2};
constexpr size_t Y_Shift = Var * 4 + 1;
constexpr size_t p = 0;
constexpr size_t n0 = 1;
constexpr size_t Exp = ipow(2, Var - p) + Var * 2 + n0;
const Number L = sqrt(sqrt(ipow(2, Var - p - 2) * (ipow(2, Var - p) + Var * 2 + 1)) - ipow(2, Var - p - 1));
std::uniform_real_distribution<float> d(y_min, y_max);

#include <sstream>
gui::gui(QWidget *parent) : QWidget(parent) {
	auto lambda = [this]() {
		Matrix<Exp, Var> x {
			Experiment<Var>{x_min[0], x_min[1], x_min[2]}, Experiment<Var>{x_min[0], x_min[1], x_max[2]},
			Experiment<Var>{x_min[0], x_max[1], x_min[2]}, Experiment<Var>{x_min[0], x_max[1], x_max[2]},
			Experiment<Var>{x_max[0], x_min[1], x_min[2]}, Experiment<Var>{x_max[0], x_min[1], x_max[2]},
			Experiment<Var>{x_max[0], x_max[1], x_min[2]}, Experiment<Var>{x_max[0], x_max[1], x_max[2]},
			Experiment<Var>{-L * dx[0] + x0[0], x0[1], x0[2]}, Experiment<Var>{+L * dx[0] + x0[0], x0[1], x0[2]},
			Experiment<Var>{x0[0], -L * dx[1] + x0[1], x0[2]}, Experiment<Var>{x0[0], +L * dx[1] + x0[1], x0[2]},
			Experiment<Var>{x0[0], x0[1], -L * dx[2] + x0[2]}, Experiment<Var>{x0[0], x0[1], +L * dx[2] + x0[2]},
			Experiment<Var>{x0[0], x0[1], x0[2]}
		};
		Matrix<Exp, Var> xn{
			Experiment<Var>{-1, -1, -1}, Experiment<Var>{-1, -1, +1},
			Experiment<Var>{-1, +1, -1}, Experiment<Var>{-1, +1, +1},
			Experiment<Var>{+1, -1, -1}, Experiment<Var>{+1, -1, +1},
			Experiment<Var>{+1, +1, -1}, Experiment<Var>{+1, +1, +1},
			Experiment<Var>{-L, 0, 0}, Experiment<Var>{+L, 0, 0},
			Experiment<Var>{0, -L, 0}, Experiment<Var>{0, +L, 0},
			Experiment<Var>{0, 0, -L}, Experiment<Var>{0, 0, +L},
			Experiment<Var>{0, 0, 0}
		};
		Matrix<Exp, Var> xxn = xn;
		Array<Exp> xxxn;
		Matrix<Exp, Var> x2n = xn;
		for (size_t j = 0; j < Exp; j++) {
			for (size_t i = 0; i < Var; i++) {
				draw(ui.table, j, i, x[j][i]);
				draw(ui.table, j, i + Var, xn[j][i]);
			}
			xxn[j][0] = xn[j][0] * xn[j][1];
			xxn[j][1] = xn[j][1] * xn[j][2];
			xxn[j][2] = xn[j][0] * xn[j][2];
			draw(ui.table, j, 0 + Var * 2, xxn[j][0]);
			draw(ui.table, j, 1 + Var * 2, xxn[j][1]);
			draw(ui.table, j, 2 + Var * 2, xxn[j][2]);
			xxxn[j] = xn[j][0] * xn[j][1] * xn[j][2];
			draw(ui.table, j, 2 + Var * 2 + 1, xxxn[j]);
			for (size_t i = 0; i < Var; i++) {
				x2n[j][i] = xn[j][i] * xn[j][i];
				draw(ui.table, j, i + Var * 3 + 1, x2n[j][i]);
			}
		}

		size_t m = 2;
		std::vector<Array<Exp>> y;
		bool one_more_time = false;
		float y_av = 0;
		Number sigma_max = 0.f, sigma_sum = 0.f;
		non_adequate: do {
		increment(m);
		ui.table->setColumnCount(m + Y_Shift);
		for (size_t i = y.size(); i < m; i++) {
			ui.table->setHorizontalHeaderItem(i + Y_Shift, new QTableWidgetItem("y" + QString::number(i)));
			y.push_back(randomizeExperiment<Exp>(d));
			for (size_t j = 0; j < Exp; j++)
				draw(ui.table, j, i + Y_Shift, y[i][j]);
		}
		Array<Exp> sigma = fillExperiment<Exp>(0.f);
		for (size_t j = 0; j < Exp; j++) {
			y_av = 0;
			for (size_t i = 0; i < m; i++)
				y_av += y[i][j];
			y_av /= m;

			for (size_t i = 0; i < m; i++)
				sigma[j] += (y[i][j] - y_av) * (y[i][j] - y_av);
			sigma[j] /= m;
			if (sigma[j] > sigma_max)
				sigma_max = sigma[j];
			sigma_sum += sigma[j];
		}
		Number g = sigma_max / sigma_sum;
		one_more_time = g * 50 > q_test(m);
		} while (one_more_time);

		Number sigma_av = sigma_sum / Var;
		sigma_av /= m * Var;

		size_t d_c = Var * 3 + 1;

		Experiment<Var> beta_x = fillExperiment<Var>(0.f);
		Experiment<Var> beta_xx = fillExperiment<Var>(0.f);
		Number beta_xxx = 0.f;
		Experiment<Var> beta_x2 = fillExperiment<Var>(0.f);
		for (size_t j = 0; j < Exp; j++) {
			for (size_t i = 0; i < Var && i < m; i++) {
				beta_x[i] += y_av * xn[j][i];
				beta_x2[i] += y_av * xn[j][i] * xn[j][i];
			}
			beta_xx[0] += y_av * xn[j][0] * xn[j][1];
			beta_xx[1] += y_av * xn[j][1] * xn[j][2];
			beta_xx[2] += y_av * xn[j][0] * xn[j][2];
			beta_xxx += y_av * xn[j][0] * xn[j][1] * xn[j][2];
		}
		Experiment<Var> tx = fillExperiment<Var>(0.f);
		Experiment<Var> txx = fillExperiment<Var>(0.f);
		Number txxx = 0.f;
		Experiment<Var> tx2 = fillExperiment<Var>(0.f);
		for (size_t i = 0; i < Var && i < m; i++) {
			tx[i] = beta_x[i] / sigma_av;
			if (tx[i] > 0 && tx[i] < t_test((m - 1) * Var)) {
				tx[i] = -1.f;
				d_c--;
			}
			txx[i] = beta_xx[i] / sigma_av;
			if (txx[i] > 0 && txx[i] < t_test((m - 1) * Var)) {
				txx[i] = -1.f;
				d_c--;
			}
			txxx = beta_xxx / sigma_av;
			if (txxx > 0 && txxx < t_test((m - 1) * Var)) {
				txxx = -1.f;
				d_c--;
			}
			tx2[i] = beta_x2[i] / sigma_av;
			if (tx2[i] > 0 && tx2[i] < t_test((m - 1) * Var)) {
				tx2[i] = -1.f;
				d_c--;
			}
		}

		Array<Exp> sy = fillExperiment<Exp>(0.f);
		for (size_t j = 0; j < Exp; j++) {
			for (size_t i = 0; i < m; i++)
				sy[j] += y[i][j];
			sy[j] /= m;
		}

		Experiment<Var> bi = fillExperiment<Var>(0.f);
		Experiment<Var> bi2 = fillExperiment<Var>(0.f);
		for (size_t i = 0; i < Var && i < m; i++) {
			for (size_t j = 0; j < Exp; j++) {
				bi[i] += sy[j] * xn[j][i];
				bi2[i] += sy[j] * xn[j][i] * xn[j][i];
			}
			bi[i] /= Exp;
			bi2[i] /= Exp;
			bi2[i] /= dx[i];
		}
		Number b0 = 0.f;
		Experiment<Var> bii = fillExperiment<Var>(0.f);
		Number biii = 0.f;
		for (size_t j = 0; j < Exp; j++) {
			b0 += sy[j];
			bii[0] += sy[j] * xn[j][0] * xn[j][1];
			bii[1] += sy[j] * xn[j][1] * xn[j][2];
			bii[2] += sy[j] * xn[j][0] * xn[j][2];
			biii += sy[j] * xn[j][0] * xn[j][1] * xn[j][2];
		}
		b0 /= Exp;
		bii[0] /= Exp;
		bii[1] /= Exp;
		bii[2] /= Exp;
		biii /= Exp;
		Number sigma_ad = 0.f, sigma_s = 0.f;
		for (size_t j = 0; j < Var; j++)
			sigma_ad += (b0 + bi[0] * xn[j][0] + bi[1] * xn[j][1] + bi[2] * xn[j][2]
						 + bii[0] * xn[j][0] * xn[j][1] + bii[1] * xn[j][1] * xn[j][2]
						 + bii[2] * xn[j][0] * xn[j][2] + biii * xn[j][0] * xn[j][1] * xn[j][2]
						 + bi2[0] * xn[j][0] * xn[j][0] + bi2[1] * xn[j][1] * xn[j][1]
						 + bi2[2] * xn[j][2] * xn[j][2]) - y_av;
		sigma_ad *= m / d_c;

		Number f = sigma_ad / sigma_av;
		if (f > f_test((m - 1) * Var, d_c))
			goto non_adequate;

		Number b0_ = b0
			- bi[0] * x0[0] / dx[0]
			- bi[1] * x0[1] / dx[1]
			- bi[2] * x0[2] / dx[2]
			- bii[0] * x0[0] / dx[0] * x0[1] / dx[1]
			- bii[1] * x0[1] / dx[1] * x0[2] / dx[2]
			- bii[2] * x0[0] / dx[0] * x0[2] / dx[2]
			- biii * x0[0] / dx[0] * x0[1] / dx[1] * x0[2] / dx[2]
			- bi[0] * x0[0] / dx[0] * x0[0] / dx[0]
			- bi[1] * x0[1] / dx[1] * x0[1] / dx[1]
			- bi[2] * x0[2] / dx[2] * x0[2] / dx[2];

		Experiment<Var> bi_ = fillExperiment<Var>(0.f);
		Experiment<Var> bi2_ = fillExperiment<Var>(0.f);
		for (size_t i = 0; i < Var; i++) {
			bi_[i] = bi[i] / dx[i];
			bi2_[i] = bi2[i] / dx[i];
		}

		Experiment<Var> bii_ = fillExperiment<Var>(0.f);
		bii_[0] = bii[0] / dx[0] / dx[1];
		bii_[1] = bii[1] / dx[1] / dx[2];
		bii_[2] = bii[2] / dx[0] / dx[2];

		Number biii_ = biii_ / dx[0] / dx[1] / dx[2];

		std::stringstream s1, s2;
		s1 << "y = (" << b0 << ") + (" << bi[0] << ") * x0 + (" << bi[1] << ") * x1 + (" << bi[2] << ") * x2 + ("
			<< bii[0] << ") * x0 * x1 + (" << bii[1] << ") * x1 * x2 + (" << bii[2] << ") * x0 * x2 + ("
			<< biii << ") * x0 * x1 * x2 + (" << bi2[0] << ") * x0 * x0 + (" << bi2[1] << ") * x1 * x1 + (" 
			<< bi2[2] << ") * x2 * x2" << ";";
		s2 << "y = (" << b0_ << ") + (" << bi_[0] << ") * x0 + (" << bi_[1] << ") * x1 + (" << bi_[2] << ") * x2 + ("
			<< bii_[0] << ") * x0 * x1 + (" << bii_[1] << ") * x1 * x2 + (" << bii_[2] << ") * x0 * x2 + ("
			<< biii_ << ") * x0 * x1 * x2 + (" << bi2_[0] << ") * x0 * x0 + (" << bi2_[1] << ") * x1 * x1 + ("
			<< bi2_[2] << ") * x2 * x2" << ";";
		ui.res->setText(QString::fromStdString(s1.str()));
		ui.res_2->setText(QString::fromStdString(s2.str()));//*/
	};
	ui.setupUi(this);
	connect(ui.calculate, &QPushButton::clicked, lambda);
	lambda();
}