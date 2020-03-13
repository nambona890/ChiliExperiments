#include "Bullet.h"

Bullet::Bullet(ImageResources * imgR, Vec2 vel, Vec2 startPos, bool player) : Entity(imgR)
{

	image = new std::shared_ptr<Image>[4];
    image[0] = imgRes->AddImage("bullet1.png", "bullet1");
	image[1] = imgRes->AddImage("bullet2.png", "bullet2");
	image[2] = imgRes->AddImage("bullet3.png", "bullet3");
	image[3] = imgRes->AddImage("bullet2.png", "bullet2");
	isPlayer = player;
	velocity = vel;
	pos = startPos;
}

void Bullet::Logic(MainWindow & wnd, unsigned int globalTimer)
{
	if (alive && !destroy)
	{
		pos = pos + velocity;
		imageIndex = modulo(globalTimer/8,4u);
	}
	if (pos.x < GAMELX - image[imageIndex]->getWidth() || pos.x > GAMERX + image[imageIndex]->getWidth() ||
		pos.y < GAMETY - image[imageIndex]->getHeight() || pos.y > GAMEBY + image[imageIndex]->getHeight())
	{
		destroy = true;
	}
}

void Bullet::Draw(Graphics & gfx)
{
	if (alive && !destroy)
	{
		t.center = IMGCNTR(imageIndex,-0.5f);

		image[imageIndex]->drawTransform(pos, t, gfx);
	}
}
