#pragma once
#include "Entity.h"

class Bullet : public Entity
{
protected:
	bool isPlayer;
	Vec2 velocity;
	float radius = 4.0f;
public:
	Bullet(ImageResources* imgR, Vec2 vel, Vec2 startPos, bool player);
	void Logic(MainWindow& wnd, unsigned int globalTimer);
	void Draw(Graphics& gfx);
	bool GetPlayer()
	{
		return isPlayer;
	}
};