#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <random>
const size_t factors = 2;
constexpr size_t n = (1.65 * factors + 0.05 * factors * factors) + 1;
extern std::mt19937_64 g;
struct Point {
	float x, y;
};
struct Value : public Point {
	float v;
	Value(float x = 0.f, float y = 0.f, float v = 0.f) 
		: Point{x, y}, v(v) {}
};
struct Simplex {
	Value a, b, c;
};
constexpr float d_x(size_t i) {
	return i + 0 + 10;
}
inline float experiment(size_t i) {
	std::uniform_real_distribution<> d(0, d_x(i));
	auto x1 = 8 + d(g);
	auto x2 = 2 + d(g);
	return 5 * x1 / x2 / x2;
}
inline Simplex generate() {
	return Simplex{ Value(sinf(M_PI * 2 / 3), cosf(M_PI * 2 / 3), experiment(1)),
					Value(sinf(M_PI * 4 / 3), cosf(M_PI * 4 / 3), experiment(2)),
					Value(sinf(0), cosf(0), experiment(3))};
}