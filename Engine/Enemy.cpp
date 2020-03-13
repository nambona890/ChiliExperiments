#include "Enemy.h"

Enemy::Enemy(ImageResources* imgR, Vec2 initPos) : Entity(imgR)
{
	pos = initPos;
	image = new std::shared_ptr<Image>[2];
	image[0] = imgRes->AddImage("munch1.png", "muncher1");
	image[1] = imgRes->AddImage("munch2.png", "muncher2");

}

void Enemy::Logic(MainWindow & wnd, unsigned int globalTimer, std::vector<Bullet>& bullets)
{
	if (alive)
	{
		imageIndex = modulo(globalTimer / 8, 2u);
		pos.y += 2.5f;
		if (pos.y > GAMEBY + image[imageIndex]->getHeight())
		{
			destroy = true;
		}
		for (Bullet& b : bullets)
		{
			if (b.CheckCollision(pos, radius) && !b.GetDestroy() && b.GetPlayer())
			{
				alive = false;
			}
		}
	}
	else if (alpha > 0.0f)
	{
		scale = { scale.x * 1.04f,scale.y * 1.04f };
		alpha = std::fmaxf(alpha - 0.04f, 0.0f);
	}
	else
	{
		alpha = 0.0f;
		destroy = true;
	}

}

void Enemy::Draw(Graphics & gfx)
{
	t.ScaleNew(scale);
	t.center = IMGCNTR(imageIndex,-0.5f);
	image[imageIndex]->drawTransform(pos, t, gfx);
}
