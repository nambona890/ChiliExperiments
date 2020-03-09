#pragma once
#include <cmath>

#define PI 3.14159265358f
#define TAU 6.28318530718f

template <typename T>
T modulo(T n, T max) //why the fuck doesn't std come with a normal modulo function
{
	T ret;
	ret = std::fmod(n, max);

	if (ret < 0)
		ret += max;

	return ret;
}
