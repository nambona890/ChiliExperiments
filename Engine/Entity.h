#pragma once
#include "Sprite.h"

class Entity : public Sprite
{
protected:
	int deathTimer = 0;
	float radius = 0.0f;
public:
	Entity(ImageResources* imgR) : Sprite(imgR)
	{

	}
	bool CheckCollision(Vec2 exPos)
	{
		return (pos - exPos).Distance() < radius;
	}
	void Kill()
	{
		if (deathTimer == 0)
		{
			deathTimer++;
		}
	}
};