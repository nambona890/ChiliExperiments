#pragma once
#include "Vector.h"
#include "Image.h"
#include "ImageResources.h"
#include "Transform.h"
#include "Graphics.h"
#include "MainWindow.h"

class Sprite
{
protected:
	Image* image = nullptr;
	Transform t;
	float alpha = 1.0f;
	Vec2 pos;
public:
	Sprite() = default;
	Vec2 GetPos()
	{
		return pos;
	}
	virtual void Logic(MainWindow& wnd)
	{

	}
	virtual void UpdateImage(ImageResources* imgR)
	{

	}
	virtual void Draw(Graphics& gfx)
	{

	}

};