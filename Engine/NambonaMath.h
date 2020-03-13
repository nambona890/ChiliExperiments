#pragma once
#include <cmath>

#define PI 3.14159265358f
#define TAU 6.28318530718f

#define GAMEWIDTH 368
#define GAMEHEIGHT 568
#define GAMELX 16
#define GAMERX 384
#define GAMETY 16
#define GAMEBY 584

template <typename T>
T modulo(T n, T max) //why the fuck doesn't std come with a normal modulo function
{
	T ret;
	ret = std::fmod(n, max);

	if (ret < 0)
		ret += max;

	return ret;
}

template <typename T>
T clamp(T n, T min, T max)
{
	T ret;
	ret = std::max(min, std::min(n,max));
	return ret;
}