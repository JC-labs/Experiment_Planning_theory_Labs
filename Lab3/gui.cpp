#include "gui.h"
#include <array>
#include <random>
const size_t Array_Size = 4;
using Number = float;
using Array = std::array<Number, Array_Size>;
using Matrix = std::array<Array, Array_Size>;

size_t decode(size_t& i) {
	switch (i) {
	case 2: return 0;
	case 3: return 1;
	case 4: return 2;
	case 5: return 3;
	case 6: return 4;
	case 7: return 5;
	case 8: return 6;
	case 9: return 7;
	case 10: return 8;
	case 16: return 9;
	case 36: return 10;
	case 144: return 11;
	case 10000: return 12;
	default: return -1;
	}
}
size_t increment(size_t& i) {
	switch (i) {
	case 2: return 3;
	case 3: return 4;
	case 4: return 5;
	case 5: return 6;
	case 6: return 7;
	case 7: return 8;
	case 8: return 9;
	case 9: return 10;
	case 10: return 16;
	case 16: return 36;
	case 36: return 144;
	case 144: return 10000;
	case 10000: return 2;
	default: return -1;
	}
}

Number q_table[] = { 9.065, 7.679, 6.841, 6.287, 5.892, 5.598, 5.365, 
					 5.175, 5.017, 4.884, 4.366, 3.720, 3.093, 2.500 };
Number q_test(size_t m) { return q_table[decode(m)]; }

Number t_table[31] = { 12.71, 4.303, 3.182, 2.776, 2.571, 2.447, 2.365, 2.306, 2.228, 2.201, 2.179, 2.160, 
					 2.145, 2.131, 2.120, 2.110, 2.101, 2.093, 2.086, 2.080, 2.074, 2.069, 2.064, 2.060, 
					 2.056, 2.052, 2.048, 2.045, 2.042, 1.96 };
Number t_test(size_t m) { 
	if (m >= 1 && m <= 30)
		return t_table[m - 1];
	else
		return t_table[30];
}

gui::gui(QWidget *parent) : QWidget(parent) {
	auto lambda = [this]() {
		Matrix x{ Array{ +1,-1,-1,-1 }, Array{ +1,-1,-1,+1 }, Array{ +1,-1,+1,+1 }, Array{ +1,+1,+1,+1 } };
		for (size_t i = 0; i < Array_Size; i++)
			for (size_t j = 0; j < Array_Size; j++) {
				ui.table->setItem(i, j, new QTableWidgetItem(QString::number(x[i][j])));
				ui.table->item(i, j)->setTextAlignment(Qt::AlignHCenter);
			}

		const Number y_max = 200 + Number(40 + 45 + 45) / 3;
		const Number y_min = 200 + Number(10 + 25 + 40) / 3;

		std::mt19937_64 g((std::random_device())());
		std::uniform_real_distribution<float> d(y_min, y_max);

		size_t m = 2;
		std::vector<Array> y;
		bool one_more_time;
		do {
			increment(m);
			ui.table->setColumnCount(m + Array_Size);
			for (size_t j = y.size(); j < m; j++) {
				y.push_back({ d(g), d(g), d(g), d(g) });
				for (size_t i = 0; i < Array_Size; i++) {
					ui.table->setItem(i, j + Array_Size, new QTableWidgetItem(QString::number(y[j][i])));
					ui.table->item(i, j + Array_Size)->setTextAlignment(Qt::AlignHCenter);
				}
			}

			float y_av = 0;
			Array sigma{ 0.f, 0.f, 0.f, 0.f };
			Number sigma_max = 0.f, sigma_sum = 0.f;
			for (size_t i = 0; i < Array_Size; i++) {
				y_av = 0;
				for (size_t j = 0; j < m; j++)
					y_av += y[j][i];
				y_av /= m;

				for (size_t j = 0; j < m; j++)
					sigma[i] += (y[j][i] - y_av) * (y[j][i] - y_av);
				sigma[i] /= m;
				if (sigma[i] > sigma_max)
					sigma_max = sigma[i];
				sigma_sum += sigma[i];
			}
			Number g = sigma_max / sigma_sum;
			one_more_time = g < q_test(m);

			Number sigma_av = sigma_sum / Array_Size;
			sigma_av /= m * Array_Size;

			Array beta = { 0, 0, 0, 0 };
			for (size_t i = 0; i < Array_Size; i++)
				for (size_t j = 0; j < Array_Size && j < m; j++)
					beta[j] += y_av * x[i][j];
			Array t = { 0, 0, 0, 0 };
			for (size_t j = 0; j < Array_Size && j < m; j++) {
				t[j] = beta[j] / sigma_av;
				if (t[j] > 0 && t[j] < t_test((m - 1) * Array_Size))
 					break;
			}

		} while (one_more_time);
	};
	ui.setupUi(this);
	connect(ui.calculate, &QPushButton::clicked, lambda);
	lambda();
}
