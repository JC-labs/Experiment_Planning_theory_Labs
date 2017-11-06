#pragma once
#include <array>
namespace shared {
	using DefaultNumberType = float;
	template <size_t Variables, typename NumberType = DefaultNumberType>
	using Experiment = std::array<NumberType, Variables>;
	template <size_t Variables, typename NumberType = DefaultNumberType>
	using Array = Experiment<Variables, NumberType>;
	template <size_t Experiments, size_t Variables, typename NumberType = DefaultNumberType>
	using Matrix = std::array<Experiment<Variables, NumberType>, Experiments>;
}