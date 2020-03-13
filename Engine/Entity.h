#pragma once
#include "Sprite.h"

class Entity : public Sprite
{
protected:
	float radius;
	bool alive = true;
	bool destroy = false;
public:
	Entity(ImageResources* imgR) : Sprite(imgR)
	{

	}
	bool GetAlive()
	{
		return alive;
	}
	bool GetDestroy()
	{
		return destroy;
	}
	bool CheckCollision(Vec2 exPos, const float exRad)
	{
		return (pos - exPos).Distance() < radius + exRad;
	}
	void Kill()
	{
		alive = false;
	}
	void Destroy()
	{
		destroy = true;
	}
	float GetRadius()
	{
		return radius;
	}
};