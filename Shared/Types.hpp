#pragma once
#include <array>
namespace shared {
	using Number = float;
	template <size_t Variables, typename NumberType = Number>
	using Experiment = std::array<NumberType, Variables>;
	template <size_t Variables, typename NumberType = Number>
	using Array = Experiment<Variables, NumberType>;
	template <size_t Experiments, size_t Variables, typename NumberType = Number>
	using Matrix = std::array<Experiment<Variables, NumberType>, Experiments>;
}