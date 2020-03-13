#pragma once
#include "Entity.h"
#include "Bullet.h"

class Enemy : public Entity
{
protected:
	Vec2 scale = { 3.0f, -3.0f };
	float radius = 8.0f;
public:
	Enemy(ImageResources* imgR, Vec2 initPos);
	void Logic(MainWindow& wnd, unsigned int globalTimer, std::vector<Bullet>& bullets);
	void Draw(Graphics& gfx);
};