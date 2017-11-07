#pragma once
namespace shared {
	constexpr int64_t ipow(int64_t base, int exp, int64_t result = 1) {
		return exp < 1 ? result : ipow(base * base, exp / 2, (exp % 2) ? result * base : result);
	}
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
			case 2: return i = 3;
			case 3: return i = 4;
			case 4: return i = 5;
			case 5: return i = 6;
			case 6: return i = 7;
			case 7: return i = 8;
			case 8: return i = 9;
			case 9: return i = 10;
			case 10: return i = 16;
			case 16: return i = 36;
			case 36: return i = 144;
			case 144: return i = 10000;
			case 10000: return i = 2;
			default: return i = -1;
		}
	}
}