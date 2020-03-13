#pragma once
#include "Entity.h"
#include "Bullet.h"

class Player : public Entity
{
protected:
	Vec2 scale = { 0.1f,0.1f };
	Vec2 pos = { 200,500 };
	unsigned int bulletCooldown = 0;
	static constexpr float speed = 4.0f;
public:
	Player(ImageResources* imgR);
	void Logic(MainWindow& wnd, unsigned int globalTimer, std::vector<Bullet>& bullets);
	void Draw(Graphics& gfx);
};
