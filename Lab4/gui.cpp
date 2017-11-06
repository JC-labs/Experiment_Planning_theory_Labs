#include "gui.h"
#include "Types.hpp"
using namespace shared;

#include "qtablewidget.h"
void draw(QTableWidget *table, size_t i, size_t j, DefaultNumberType value) {
	table->setItem(i, j, new QTableWidgetItem(QString::number(value)));
	table->item(i, j)->setTextAlignment(Qt::AlignHCenter);
}
#include <random>
//#include <boost\qvm\mat.hpp>
//#include <boost\qvm\mat_operations.hpp>
//
//size_t decode(size_t& i) {
//	switch (i) {
//		case 2: return 0;
//		case 3: return 1;
//		case 4: return 2;
//		case 5: return 3;
//		case 6: return 4;
//		case 7: return 5;
//		case 8: return 6;
//		case 9: return 7;
//		case 10: return 8;
//		case 16: return 9;
//		case 36: return 10;
//		case 144: return 11;
//		case 10000: return 12;
//		default: return -1;
//	}
//}
//size_t increment(size_t& i) {
//	switch (i) {
//		case 2: return i = 3;
//		case 3: return i = 4;
//		case 4: return i = 5;
//		case 5: return i = 6;
//		case 6: return i = 7;
//		case 7: return i = 8;
//		case 8: return i = 9;
//		case 9: return i = 10;
//		case 10: return i = 16;
//		case 16: return i = 36;
//		case 36: return i = 144;
//		case 144: return i = 10000;
//		case 10000: return i = 2;
//		default: return i = -1;
//	}
//}
//
//Number q_table[] = {9.065, 7.679, 6.841, 6.287, 5.892, 5.598, 5.365,
//5.175, 5.017, 4.884, 4.366, 3.720, 3.093, 2.500};
//Number q_test(size_t m) { return q_table[decode(m)]; }
//
//Number t_table[31] = {12.71, 4.303, 3.182, 2.776, 2.571, 2.447, 2.365, 2.306, 2.228, 2.201, 2.179, 2.160,
//2.145, 2.131, 2.120, 2.110, 2.101, 2.093, 2.086, 2.080, 2.074, 2.069, 2.064, 2.060,
//2.056, 2.052, 2.048, 2.045, 2.042, 1.96};
//Number t_test(size_t m) {
//	if (m >= 1 && m <= 30)
//		return t_table[m - 1];
//	else
//		return t_table[30];
//}
//
//Number f_table[] = {224.6, 19.3, 9.1, 6.4, 5.2, 4.5, 4.1, 3.8, 3.6, 3.5, 3.4, 3.3, 3.2, 3.1, 3, 3, 2.9, 2.9,
//2.8, 2.8, 2.7, 2.7, 2.7, 2.6, 2.5, 2.5, 2.4};
//Number f_test(size_t f3, size_t f4) {
//	if (f3 < 30 && f3 > 0)
//		return f_table[f3];
//	else
//		return f_table[30];
//}
constexpr size_t Exp = 8u;
constexpr size_t Var = 3u;
constexpr DefaultNumberType y_max = 200 + DefaultNumberType(+20 + +50 + +35) / 3;
constexpr DefaultNumberType y_min = 200 + DefaultNumberType(-30 + +15 + +20) / 3;

gui::gui(QWidget *parent) : QWidget(parent) {
	auto lambda = [this]() {
		Matrix<Exp, Var> x {Experiment<Var>{-30, +15, +20}, Experiment<Var>{-30, +15, +35}, 
							Experiment<Var>{-30, +50, +20}, Experiment<Var>{-30, +50, +35},
							Experiment<Var>{+20, +15, +20}, Experiment<Var>{+20, +15, +35}, 
							Experiment<Var>{+20, +50, +20}, Experiment<Var>{+20, +50, +35}};
		Matrix<Exp, Var> xn{Experiment<Var>{-1, -1, -1}, Experiment<Var>{-1, -1, +1}, 
							Experiment<Var>{-1, +1, -1}, Experiment<Var>{-1, +1, +1},
							Experiment<Var>{+1, -1, -1}, Experiment<Var>{+1, -1, +1}, 
							Experiment<Var>{+1, +1, -1}, Experiment<Var>{+1, +1, +1}};
 		Matrix<Exp, Var> xxn = xn;
 		Array<Exp> xxxn;
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
 		}
//
//
//		std::mt19937_64 g((std::random_device())());
//		std::uniform_real_distribution<float> d(y_min, y_max);
//
//		size_t m = 2;
//		std::vector<Experiment> y;
//		bool one_more_time = false;
//		float y_av = 0;
//		Number sigma_max = 0.f, sigma_sum = 0.f;
//		non_adequate: do {
//			increment(m);
//			constexpr size_t Y_Shift = Array_Size * 3 + 1;
//			ui.table->setColumnCount(m + Y_Shift);
//			for (size_t i = y.size(); i < m; i++) {
//				ui.table->setHorizontalHeaderItem(i + Y_Shift, new QTableWidgetItem("y" + QString::number(i)));
//				y.push_back({d(g), d(g), d(g), d(g), d(g), d(g), d(g), d(g)});
//				for (size_t j = 0; j < Experiments_Number; j++)
//					draw(ui.table, j, i + Y_Shift, y[i][j]);
//			}
//			Experiment sigma{0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f};
//			for (size_t j = 0; j < Experiments_Number; j++) {
//				y_av = 0;
//				for (size_t i = 0; i < m; i++)
//					y_av += y[i][j];
//				y_av /= m;
//			
//				for (size_t i = 0; i < m; i++)
//					sigma[j] += (y[i][j] - y_av) * (y[i][j] - y_av);
//				sigma[j] /= m;
//				if (sigma[j] > sigma_max)
//					sigma_max = sigma[j];
//				sigma_sum += sigma[j];
//			}
//			Number g = sigma_max / sigma_sum;
//			one_more_time = g > q_test(m);
//		} while (one_more_time);
		//
		//Number sigma_av = sigma_sum / Array_Size;
		//sigma_av /= m * Array_Size;
		//
		//size_t d_c = Array_Size;
		//
		//Array beta = {0, 0, 0, 0};
		//for (size_t i = 0; i < Array_Size; i++)
		//	for (size_t j = 0; j < Array_Size && j < m; j++)
		//		beta[j] += y_av * x[i][j];
		//Array t = {0, 0, 0, 0};
		//for (size_t j = 0; j < Array_Size && j < m; j++) {
		//	t[j] = beta[j] / sigma_av;
		//	if (t[j] > 0 && t[j] < t_test((m - 1) * Array_Size))
		//		d_c--;
		//}
		//
		//Array sy;
		//for (size_t i = 0; i < Array_Size; i++) {
		//	for (size_t j = 0; j < m; j++)
		//		sy[i] += y[j][i];
		//	sy[i] /= m;
		//}
		//
		//Number m1 = 0.f, m2 = 0.f, m3 = 0.f, my = 0.f;
		//Number a1 = 0.f, a2 = 0.f, a3 = 0.f;
		//Number a11 = 0.f, a22 = 0.f, a33 = 0.f, a12 = 0.f, a13 = 0.f, a23 = 0.f;
		//for (size_t i = 0; i < Array_Size; i++) {
		//	m1 += x[1][i];
		//	m2 += x[2][i];
		//	m3 += x[3][i];
		//	my += sy[i];
		//
		//	a12 += x[1][i] * x[2][i];
		//	a13 += x[1][i] * x[3][i];
		//	a23 += x[1][i] * x[3][i];
		//
		//	a11 += x[1][i] * x[1][i];
		//	a22 += x[2][i] * x[2][i];
		//	a33 += x[3][i] * x[3][i];
		//}
		//m1 /= Array_Size;
		//m2 /= Array_Size;
		//m3 /= Array_Size;
		//my /= Array_Size;
		//a12 /= Array_Size;
		//a13 /= Array_Size;
		//a23 /= Array_Size;
		//a11 /= Array_Size;
		//a22 /= Array_Size;
		//a33 /= Array_Size;
		//a1 /= Array_Size;
		//a2 /= Array_Size;
		//a3 /= Array_Size;
		//
		//float def_det = boost::qvm::determinant(MathMatrix{1,  m1,  m2,  m3,
		//										m1, a11, a12, a13,
		//										m2, a12, a22, a23,
		//										m3, a13, a23, a33});
		//
		//float b0 = boost::qvm::determinant(MathMatrix{my,  m1,  m2,  m3,
		//								   a1, a11, a12, a13,
		//								   a2, a12, a22, a23,
		//								   a3, a13, a23, a33})
		//	/ def_det;
		//float b1 = boost::qvm::determinant(MathMatrix{1, my,  m2,  m3,
		//								   m1, a1, a12, a13,
		//								   m2, a2, a22, a23,
		//								   m3, a3, a23, a33})
		//	/ def_det;
		//float b2 = boost::qvm::determinant(MathMatrix{1,  m1, my,  m3,
		//								   m1, a11, a1, a13,
		//								   m2, a12, a2, a23,
		//								   m3, a13, a3, a33})
		//	/ def_det;
		//float b3 = boost::qvm::determinant(MathMatrix{1,  m1,  m2, my,
		//								   m1, a11, a12, a1,
		//								   m2, a12, a22, a2,
		//								   m3, a13, a23, a3})
		//	/ def_det;
		//
		//Number sigma_ad = 0.f, sigma_s = 0.f;
		//for (size_t j = 0; j < Array_Size; j++)
		//	sigma_ad += (b0 + b1 * x[j][0] + b2 * x[j][1] + b3 * x[j][2]) - y_av;
		//sigma_ad *= m / d_c;
		//
		//Number f = sigma_ad / sigma_av;
		//if (f > f_test((m - 1) * Array_Size, d_c))
		//	goto non_adequate;
		//
		//std::stringstream s1, s2;
		//s1 << "y = (" << b0 << ") + (" << b1 << ") * x1 + (" << b2 << ") * x2 + (" << b3 << ") * x3;\n";
		//ui.res->setText(QString::fromStdString(s1.str()));
	};
	ui.setupUi(this);
	connect(ui.calculate, &QPushButton::clicked, lambda);
	lambda();
}