#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(ImageResources* imgR);
	void Logic(MainWindow& wnd);
	void Draw(Graphics& gfx);
};
