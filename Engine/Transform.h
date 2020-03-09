#pragma once
#include "Vector.h"

class Transform
{
private:
	float A = 1, B = 0;
	float C = 0, D = 1;
	float angle = 0;
	Vec2 size = { 1,1 };
public:
	Vec2 center;
	Vec2 translation;
public:
	void RotateNew(const float th)
	{
		angle = 0;
		Rotate(th);
	}
	void Rotate(const float th);
	void ScaleNew(const Vec2 v)
	{
		size = { 1,1 };
		Scale(v);
	}
	void Scale(const float s)
	{
		Scale({ s,s });
	}
	void Scale(const Vec2 v);
	float getAngle()
	{
		return angle;
	}
	Vec2 getScale()
	{
		return size;
	}
	Vec2 Forward(Vec2 v);
	void Invert();
};