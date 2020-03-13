#include "Player.h"
#include "Bullet.h"

Player::Player(ImageResources* imgR) : Entity(imgR)
{
	image = new std::shared_ptr<Image>[1];
	image[0] = imgRes->AddImage("buzz.png", "buzz");
}

void Player::Logic(MainWindow& wnd, unsigned int globalTimer, std::vector<Bullet>& bullets)
{
	if (alive)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			pos.y -= speed;
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			pos.y += speed;
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			pos.x -= speed;
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			pos.x += speed;
		}

		pos.x = clamp(pos.x, (float)GAMELX + radius, (float)GAMERX - radius);
		pos.y = clamp(pos.y, (float)GAMETY + radius, (float)GAMEBY - radius);


		if (wnd.kbd.KeyIsPressed('Z') && bulletCooldown == 0)
		{
			bullets.emplace_back( Bullet(imgRes, { 0.0f,-10.0f }, pos, true) );
			bulletCooldown = 6u;
		}
		
		if (bulletCooldown > 0)
		{
			bulletCooldown--;
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
	}
}

void Player::Draw(Graphics& gfx)
{
	t.center = IMGCNTR(imageIndex,0.025f);
	t.ScaleNew(scale);
	image[imageIndex]->drawTransform(pos, t, gfx);
}
