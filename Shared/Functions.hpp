#pragma once
#include <random>
#include "Types.hpp"
namespace shared {
	template <size_t Variables, typename NumberType>
	Experiment<Variables> fillExperiment(NumberType value) {
		Experiment<Variables> res;
		for (auto &it : res) it = value;
		return res;
	}
	std::mt19937_64 g((std::random_device())());
	template <size_t Variables, class Distribution>
	Experiment<Variables> randomizeExperiment(Distribution distribution) {
		Experiment<Variables> res;
		for (auto &it : res) it = distribution(g);
		return res;
	}
}