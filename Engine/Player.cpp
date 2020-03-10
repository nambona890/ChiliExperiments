#include "Player.h"

Player::Player(ImageResources* imgR) : Entity(imgR)
{
	image = imgRes->GetImage("buzz");
	pos = { 400,500 };
	t.ScaleNew({ 0.1f,0.1f });
	radius = 8.0f;
}

void Player::Logic(MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		pos.y -= 2.5f;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		pos.y += 2.5f;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= 2.5f;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += 2.5f;
	}

}

void Player::Draw(Graphics& gfx)
{
	image->drawTransform(pos, t, gfx);
}
