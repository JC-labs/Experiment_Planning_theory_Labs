#include "gui.h"
#include <QComboBox>
#include <vector>
#include <random>
#include <sstream>

template <typename T>
struct AbstractThree {
	T value[3];
	AbstractThree(T const& a = 0.f, T const& b = 0.f, T const& c = 0.f) : value{a,b,c} {}
	T& operator[](size_t i) { return value[i]; }
	T const& operator[](size_t i) const { return value[i]; }
	T* operator*() { return value; }
	T const* operator*() const { return value; }
};

using Three = AbstractThree<float>;
using Matrix = AbstractThree<Three>;

size_t decode(size_t& i) {
	switch (i) {
		case 2: return 0;
		case 6: return 1;
		case 8: return 2;
		case 10: return 3;
		case 12: return 4;
		case 15: return 5;
		case 20: return 6;
		default: return -1;
	}
}
size_t increment(size_t& i) {
	switch (i) {
		case 2: return i = 6;
		case 6: return i = 8;
		case 8: return i = 10;
		case 10: return i = 12;
		case 12: return i = 15;
		case 15: return i = 20;
		default: return i = 2;
	}
}

float confidence_table[4][7] {
	{1.73, 2.16, 2.43, 2.62, 2.75, 2.90, 3.08},
	{1.72, 2.13, 2.37, 2.54, 2.66, 2.80, 2.96},
	{1.71, 2.10, 2.27, 2.41, 2.52, 2.64, 2.78},
	{1.69, 2.00, 2.17, 2.29, 2.39, 2.49, 2.62}
};

float confidence(size_t i, size_t m) {
	return confidence_table[i][decode(m)];
}

float determinant(Matrix m) {
	float ret = 0;
	ret += m[0][0] * m[1][1] * m[2][2];
	ret += m[1][0] * m[2][1] * m[0][2];
	ret += m[0][1] * m[1][2] * m[2][0];

	ret -= m[0][2] * m[1][1] * m[2][0];
	ret -= m[0][1] * m[1][0] * m[2][2];
	ret -= m[2][1] * m[1][2] * m[0][0];

	return ret;
}

gui::gui(QWidget *parent) : QWidget(parent) {
	auto confidence_action_lambda = [this](int index) {
		std::random_device device;
		std::mt19937_64 g(device());
		std::uniform_real_distribution<float> d(140, 240);

		Three x[2] = {{10, 10, 40}, {25, 45, 45}};
		Three xn[2] = {{-1, -1, +1}, {-1, +1, +1}};
		for (size_t i = 0; i < 2; i++)
			for (size_t j = 0; j < 3; j++) {
				ui.table->setItem(j, i, new QTableWidgetItem(QString::number(xn[i][j])));
				ui.table->item(j, i)->setTextAlignment(Qt::AlignHCenter);
				ui.table->setItem(j, i + 2, new QTableWidgetItem(QString::number(x[i][j])));
				ui.table->item(j, i + 2)->setTextAlignment(Qt::AlignHCenter);
			}

		std::vector<Three> y;
		size_t m = 2;

		bool one_more_time;
		Matrix f, theta, r;
		do {
			increment(m);
			ui.table->setColumnCount(m + 4);
			for (size_t j = y.size(); j < m; j++) {
				y.push_back({d(g), d(g), d(g)});
				for (size_t i = 0; i < 3; i++) {
					ui.table->setItem(i, j + 4, new QTableWidgetItem(QString::number(y[j][i])));
					ui.table->item(i, j + 4)->setTextAlignment(Qt::AlignHCenter);
				}
			}

			Three sigma(0.f);
			for (size_t i = 0; i < 3; i++) {
				float y_av = 0;
				for (size_t j = 0; j < m; j++)
					y_av += y[j][i];
				y_av /= m;

				for (size_t j = 0; j < m; j++)
					sigma[i] += (y[j][i] - y_av) * (y[j][i] - y_av);
				sigma[i] /= m;
			}
			float sigma_theta = sqrtf(fabs(2.f * (float(m) * 2.f - 2.f) / m / (float(m) - 4.f)));
			float r_c = confidence(ui.confidence->currentIndex(), m);
			one_more_time = false;
			for (size_t i = 0; i < 3; i++)
				for (size_t j = 0; j < 3; j++) {
					auto si = sigma[i] * sigma[i];
					auto sj = sigma[j] * sigma[j];
					f[i][j] = (si >= sj) ? si / sj : sj / si;
					theta[i][j] = f[i][j] * (float(m) - 1.f) / m;
					r[i][j] = fabs(theta[i][j] - 1.f) / sigma_theta;
					if (r[i][j] > r_c)
						one_more_time = true;
				}
		} while (one_more_time);

		Three sy;
		for (size_t i = 0; i < 3; i++) {
			for (size_t j = 0; j < m; j++)
				sy[i] += y[j][i];
			sy[i] /= m;
		}

		float m1 = 0.f, m2 = 0.f;
		float a1 = 0.f, a2 = 0.f, a3 = 0.f, a11 = 0.f, a22 = 0.f;
		float my = 0.f;
		for (size_t i = 0; i < 3; i++) {
			m1 += x[1][i];
			m2 += x[2][i];
			a1 += x[1][i] * x[1][i];
			a2 += x[1][i] * x[2][i];
			a3 += x[2][i] * x[2][i];
			a11 += x[1][i] * sy[i];
			a22 += x[2][i] * sy[i];
			my += sy[i];
		}
		m1 /= 3;
		m2 /= 3;
		a1 /= 3;
		a2 /= 3;
		a3 /= 3;
		a11	/= 3;
		a22	/= 3;
		my /= 3;

		float def_det = determinant({{1, m1, m2,}, {m1, a1, a2}, {m2, a2, a3}});

		float b0 = determinant({{my, m1, m2},{a11, a1, a2},{a22, a2, a3}}) / def_det;
		float b1 = determinant({{1, my, m2}, {m1, a11, a2}, {m2, a22, a3}}) / def_det;
		float b2 = determinant({{1, m1, my}, {m1, a1, a11}, {m2, a2, a22}}) / def_det;

		float dx1 = (40 - 10) / 2;
		float dx2 = (45 - 25) / 2;
		float x10 = (40 + 10) / 2;
		float x20 = (45 + 25) / 2;

		float b0_ = b0 - b1 * x10 / dx1 - b2 * x20 / dx2;
		float b1_ = b1 / dx1;
		float b2_ = b2 / dx2;

		std::stringstream s1, s2;
		s1 << "y = (" << b0 << ") + (" << b1 << ") * x1 + (" << b2 << ") * x2;\n";
		s2 << "y = (" << b0_ << ") + (" << b1_ << ") * x1 + (" << b2_ << ") * x2;\n";
		ui.res->setText(QString::fromStdString(s1.str()));
		ui.res_n->setText(QString::fromStdString(s2.str()));
	};

	ui.setupUi(this);
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 4; j++) {
			ui.table->setItem(i, j, new QTableWidgetItem());
			ui.table->item(i, j)->setTextAlignment(Qt::AlignHCenter);
		}

	connect(ui.confidence, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), confidence_action_lambda);

	confidence_action_lambda(0);
}