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
	std::shared_ptr<Image> image;
	ImageResources* imgRes;
	Transform t;
	float alpha = 1.0f;
	Vec2 pos;
public:
	Sprite() = default;
	Sprite(ImageResources* imgR)
	{
		imgRes = imgR;
	}
	Vec2 GetPos()
	{
		return pos;
	}
	virtual void Logic(MainWindow& wnd)
	{

	}
	virtual void Draw(Graphics& gfx)
	{

	}

};