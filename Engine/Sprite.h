#pragma once
#include "Vector.h"
#include "Image.h"
#include "ImageResources.h"
#include "Transform.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "NambonaMath.h"

#define IMGCNTR(i,j) { (float)image[i]->getWidth() * j,(float)image[i]->getHeight() * j }

class Sprite
{
protected:
	std::shared_ptr<Image>* image;
	ImageResources* imgRes;
	Transform t;
	float alpha = 1.0f;
	Vec2 pos;
	Vec2 scale = { 1.0f,1.0f };
	unsigned int imageIndex = 0;
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
	virtual void Logic(MainWindow& wnd, unsigned int globalTimer)
	{

	}
	virtual void Draw(Graphics& gfx)
	{

	}

};