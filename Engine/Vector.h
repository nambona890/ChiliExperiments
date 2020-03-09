#pragma once
#include <cmath>



struct Vec2
{
	float x = 0;
	float y = 0;

	Vec2& operator=(const Vec2& a)
	{
		x = a.x;
		y = a.y;
		return *this;
	}

	Vec2 operator+(const Vec2& a) const
	{
		return { a.x + x, a.y + y };
	}

	Vec2 operator-(const Vec2& a) const
	{
		return { x - a.x, y - a.y };
	}

	template <typename T>
	Vec2 operator*(const T a) const
	{
		return { a * x, a * y};
	}

	template <typename T>
	Vec2 operator/(const T a) const
	{
		return { x / a, y / a };
	}

	Vec2& operator+=(const Vec2& a)
	{
		return *this + a;
	}

	Vec2& operator-=(const Vec2& a)
	{
		return *this - a;
	}

	template <typename T>
	Vec2& operator*=(const T a)
	{
		return *this * a;
	}

	template <typename T>
	Vec2& operator/=(const T a)
	{
		return *this / a;
	}

	Vec2& Rotate(const float th)
	{
		*this = {
			(x * cosf(th)) + (y * -sinf(th)),
			(x * sinf(th)) + (y * cosf(th))
		};
		return *this;
	}

	Vec2& Scale(const float sx, const float sy)
	{
		*this =
		{
			x * sx,
			y * sy
		};
		return *this;
	}

	float Distance() const
	{
		float d = sqrtf((x * x) + (y * y));
		return d;
	}
};