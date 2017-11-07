#pragma once
#include "Types.hpp"
#include "Tools.hpp"
namespace shared {
	Number q_table[] = {9.065, 7.679, 6.841, 6.287, 5.892, 5.598, 5.365,
						5.175, 5.017, 4.884, 4.366, 3.720, 3.093, 2.500};
	Number q_test(size_t m) { return q_table[decode(m)]; }

	Number t_table[31] = {12.71, 4.303, 3.182, 2.776, 2.571, 2.447, 2.365, 2.306, 2.228, 2.201, 2.179, 2.160,
	2.145, 2.131, 2.120, 2.110, 2.101, 2.093, 2.086, 2.080, 2.074, 2.069, 2.064, 2.060,
	2.056, 2.052, 2.048, 2.045, 2.042, 1.96};
	Number t_test(size_t m) {
		if (m >= 1 && m <= 30)
			return t_table[m - 1];
		else
			return t_table[30];
	}

	Number f_table[] = {224.6, 19.3, 9.1, 6.4, 5.2, 4.5, 4.1, 3.8, 3.6, 3.5, 3.4, 3.3, 3.2, 3.1, 3, 3, 2.9, 2.9,
	2.8, 2.8, 2.7, 2.7, 2.7, 2.6, 2.5, 2.5, 2.4};
	Number f_test(size_t f3, size_t f4) {
		if (f3 < 30 && f3 > 0)
			return f_table[f3];
		else
			return f_table[30];
	}
}